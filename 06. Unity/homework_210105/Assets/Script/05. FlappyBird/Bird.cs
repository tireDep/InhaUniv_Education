using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bird : MonoBehaviour
{
    public float jumpPower = 5.0f;

    private bool isDead = false;
    public float fScore = 0.0f;

    private Rigidbody rigidbody = null;
    private float fSpeed = 10.0f;

    private float maxRot = 45.0f;
    private float rotZ = 0.0f;

    // private bool isPress = false;
    // private float pressTime = 0.0f;
    // private float maxPressTime = 0.025f;

    void Start()
    {
        rigidbody = this.gameObject.GetComponent<Rigidbody>();
    }

    void Update()
    {
        IsPosCamOut();

        if (!isDead)
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {
                // this.transform.rotation = Quaternion.Euler(0.0f, 0.0f, 0.0f);
                // this.transform.rotation *= Quaternion.Euler(0.0f, 0.0f, maxRot);
                // >> 2번 카운트 됨
                // >> 하강하면서 충돌 -> 상승 시

                this.transform.Rotate(new Vector3(0.0f, 0.0f, maxRot - rotZ));

                rotZ = maxRot;
                // isPress = true;

                GetComponent<Rigidbody>().velocity = new Vector3(0, jumpPower, 0);
                // >> addForce
            }
            else
            {
                //if (pressTime < maxPressTime && isPress)
                //{
                //    pressTime += Time.deltaTime;
                //    Debug.Log(pressTime);
                //}
                //else
                //{
                //    isPress = false;
                //    pressTime = 0.0f;
                //}

                if (rotZ <= 46.0f && rotZ >= -46.0f)
                {
                    float fNum = 0.5f;

                    this.transform.Rotate(new Vector3(0.0f, 0.0f, -fNum));
                    rotZ = rotZ - fNum;
                    // this.transform.rotation *= Quaternion.Euler(0.0f, 0.0f, -fNum);
                }
            }
        }
        else
        {
            if (IsPosCamOut())
            {
                this.transform.rotation = Quaternion.Euler(0.0f, 0.0f, 0.0f);
                this.transform.rotation *= Quaternion.Euler(0.0f, 0.0f, -90.0f);

                float fallSpeed = fSpeed * 1.5f;
                this.transform.Translate(Vector3.right * fallSpeed * Time.deltaTime);
            }
            else
            {
                FB_GameManager.Instance.ChangeSceneStrName("02. End");
            }
        }

    }

    private void OnCollisionEnter(UnityEngine.Collision collision)
    {
        if(rigidbody != null)
        {   
            isDead = true;
            rigidbody.isKinematic = true;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        //if (isPress)
        //    return;
        
        if (!isDead && other.tag == "passSpot")
        {
            fScore += 10.0f;
            FB_GameManager.Instance.fScore = fScore;
            other.gameObject.GetComponent<Collider>().enabled = false;
        }
    }


    private void OnTriggerExit(Collider other)
    {
        Debug.Log("exit");
    }

    private bool IsPosCamOut()
    {
        Vector3 targetPos = Camera.main.WorldToScreenPoint(this.transform.position);

        if (targetPos.y < Screen.height && targetPos.y > -10.0f)
            return true;

        isDead = true;
        Destroy(this.gameObject);

        return false;
    }

    private void OnBecameInvisible()
    {
        Debug.Log("here");
    }
}
