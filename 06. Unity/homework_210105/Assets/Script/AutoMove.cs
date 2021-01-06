using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoMove : MonoBehaviour
{
    public float fSpeed = 30.0f;
    public float fDistance = 75.0f;

    private Ray rayRight;
    private Ray rayLeft;
    private Ray rayFront;

    private RaycastHit rayLeftHit;
    private RaycastHit rayRightHit;
    private RaycastHit rayFrontHit;

    void Start()
    {
        SetRay();
    }

    void Update()
    {
        AutoMoving();
        CheckWall();
    }

    void AutoMoving()
    {
        this.transform.Translate(Vector3.forward * fSpeed * Time.deltaTime);
    }

    void CheckWall()
    {
        SetRay();

        if (Physics.Raycast(rayFront, out rayFrontHit, fDistance))
        {
            Debug.Log("front");
        }

        float rDist = -9999, lDist = -9999;
        if (Physics.Raycast(rayRight, out rayRightHit, fDistance))
        {
            rDist = rayRightHit.distance;
        }

        if (Physics.Raycast(rayLeft, out rayLeftHit, fDistance))
        {
            lDist = rayLeftHit.distance;
        }

        if(rDist > lDist)
            this.transform.Rotate(new Vector3(0, -1 * fSpeed * Time.deltaTime, 0));
        else if (rDist < lDist)
            this.transform.Rotate(new Vector3(0, fSpeed * Time.deltaTime, 0));

        // >> todo : center 이동
    }

    void SetRay()
    {
        // todo : direction만 바꿔보기

        Vector3 pos = this.transform.forward;
        Quaternion rotate = Quaternion.Euler(0.0f, -45.0f, 0.0f);
        Vector3 leftPos = rotate * pos;

        rotate = Quaternion.Euler(0.0f, 45.0f, 0.0f);
        Vector3 rightPos = rotate * pos;

        rayLeft = new Ray(this.transform.position, leftPos);
        rayRight = new Ray(this.transform.position, rightPos);
        rayFront = new Ray(this.transform.position, this.transform.forward);
    }

    private void OnDrawGizmos()
    {
        Debug.DrawRay(rayRight.origin, rayRight.direction * fDistance, Color.red);
        Debug.DrawRay(rayLeft.origin, rayLeft.direction * fDistance, Color.blue);
        // Debug.DrawRay(rayFront.origin, rayFront.direction * fDistance, Color.black);
    }
}
