using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoMove : MonoBehaviour
{
    // public GameObject[] tempArr = null;
    // >> unity 내부에서 배열 크기 & 오브젝트 추가 가능

    private float fOrigSpeed = 100.0f;
    public float fSpeed = 100.0f;
    public float fDistance = 75.0f;

    private Ray rayRight;
    private Ray rayLeft;
    private Ray rayFront;

    private RaycastHit rayLeftHit;
    private RaycastHit rayRightHit;
    private RaycastHit rayFrontHit;

    public int finishCheck = 2;
    public bool isFinish = false;
    
    private Rigidbody rigidbody = null;
    void Start()
    {
        fOrigSpeed = fSpeed;
        SetRay();

        rigidbody = this.gameObject.GetComponent<Rigidbody>();
    }

    public float Labtime = 0.0f;
    private bool check = false;
    void Update()
    {
        if(Labtime >= 0.5f)
        {
            if (isFinish)
            {
                ReduceSpeed();
            }

            if (IsSpeedNotZero())
            {
                AutoMoving();
                CheckWall();
            }
            else
            {
                if (!check)
                {
                    check = true;
                    GameManager.Instance.LabTimeRecord(Labtime);
                }
            }
        }

        Labtime += Time.deltaTime;
    }

    void AutoMoving()
    {
        this.transform.Translate(Vector3.forward * fSpeed * Time.deltaTime);
    }

    void CheckWall()
    {
        SetRay();

        //if (Physics.Raycast(rayFront, out rayFrontHit, fDistance * 0.5f))
        //{
        //    if (rayFrontHit.collider.gameObject.tag == "Vehicle")
        //    {
        //        fSpeed -= 0.25f;
        //    }
        //}
        //else
        //{
        //    Debug.Log(fSpeed);
        //    fSpeed = 100.0f;
        //}

        float rDist = 9999, lDist = 9999;
        if (Physics.Raycast(rayRight, out rayRightHit, fDistance))
        {
            if (rayRightHit.collider.gameObject.tag != "EndLine")
                rDist = rayRightHit.distance;
        }

        if (Physics.Raycast(rayLeft, out rayLeftHit, fDistance))
        {
            if (rayLeftHit.collider.gameObject.tag != "EndLine")
                lDist = rayLeftHit.distance;
        }

        // rDist = Mathf.Floor(rDist);
        // lDist = Mathf.Floor(lDist);

        
        // if(lDist != 9999 && (rDist >= 9999 && rDist <= 9998))// (rayRightHit.collider.tag=="Wall"))
        // if(lDist < rDist && rDist >= 9998.9 && rayLeftHit.collider.tag == "Wall")
        // {
        //     Debug.Log("turnRight");
        //     this.transform.Rotate(new Vector3(0, -1 * fSpeed * Time.deltaTime, 0));
        // }
        // else if (rDist == 9999 && rayLeftHit.collider.tag == "Wall")
        //     this.transform.Rotate(new Vector3(0, fSpeed * Time.deltaTime, 0));

        if (rDist < lDist)
            this.transform.Rotate(new Vector3(0, -1 * fSpeed * Time.deltaTime, 0));
        else if (rDist > lDist)
            this.transform.Rotate(new Vector3(0, fSpeed * Time.deltaTime, 0));
    }

    void SetRay()
    {
        Vector3 pos = this.transform.forward;
        Quaternion rotate = Quaternion.Euler(0.0f, -45.0f, 0.0f);
        Vector3 leftPos = rotate * pos;

        rotate = Quaternion.Euler(0.0f, 45.0f, 0.0f);
        Vector3 rightPos = rotate * pos;

        rayLeft.origin = this.transform.position;
        rayLeft.direction = leftPos;

        rayRight.origin = this.transform.position;
        rayRight.direction = rightPos;

        rayFront.origin = this.transform.position;
        rayFront.direction = pos;
    }

    private void OnDrawGizmos()
    {
        
        Debug.DrawRay(rayRight.origin, rayRight.direction * fDistance, Color.red);
        Debug.DrawRay(rayLeft.origin, rayLeft.direction * fDistance, Color.blue);

       // Debug.DrawRay(rayFront.origin, rayFront.direction * fDistance * 0.5f, Color.black);
    }

    private void OnCollisionEnter(UnityEngine.Collision collision)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = collision.gameObject;

        if (hitObj.tag == "Floor")
            return;

        // if (hitObj.tag == "Vehicle" && !isFinish)
        if (!isFinish)
        {
            float tempSpeed = fSpeed;
            fSpeed = tempSpeed * 0.5f;
        }
        // else if (hitObj.tag == "Vehicle" && isFinish)
        else if(isFinish)
        {
            Debug.Log("hit");
            fSpeed = 0.0f;
        }
    }

    private void OnCollisionStay(UnityEngine.Collision collision)
    {
        //if (rigidbody == null)
        //    return;

        //GameObject hitObj = collision.gameObject;

        //if (hitObj.tag == "Floor")
        //    return;

        //// if (hitObj.tag == "Vehicle" && !isFinish)
        //if (!isFinish && hitObj)
        //{
        //    float tempSpeed = fSpeed;
        //    fSpeed = tempSpeed * 0.5f;
        //}
        //// else if (hitObj.tag == "Vehicle" && isFinish)
        //else if (isFinish)
        //{
        //    Debug.Log("hit");
        //    fSpeed = 0.0f;
        //}
    }

    private void OnCollisionExit(UnityEngine.Collision collision)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = collision.gameObject;

        if (hitObj.tag == "Floor")
            return;

        // if (hitObj.tag == "Vehicle" && !isFinish)
        if (!isFinish)
        {
            fSpeed = fOrigSpeed;
        }
    }


    private void OnTriggerEnter(Collider other)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = other.gameObject;

        if (hitObj.tag == "EndLine" && IsSpeedNotZero())
        {
           
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = other.gameObject;

        if (hitObj.tag == "EndLine" && this.tag == "Vehicle")
        {
            finishCheck--;

            if (finishCheck <= 0)
                isFinish = true;
        }
    }

    private void ReduceSpeed()
    { 
        if (fSpeed > 0)
            fSpeed -= 0.1f;
    }

    private bool IsSpeedNotZero()
    {
        if (fSpeed > 0)
            return true;
        else
        {
            // rigidbody.isKinematic = true;
            return false;
        }
    }
}
