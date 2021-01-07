using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VehicleMove : MonoBehaviour
{
    void Start()
    {
        
    }

    void Update()
    {
        float fRot = 10.0f;
        float fSpeed = 10.0f;
        float moveDelta = fSpeed * Time.deltaTime;

        if (Input.GetKey(KeyCode.W))
        {
            this.transform.Translate(Vector3.forward * moveDelta);
        }
        else if (Input.GetKey(KeyCode.S))
        {
            this.transform.Translate(Vector3.back * moveDelta);
        }

        else if (Input.GetKey(KeyCode.A))
        {
            this.transform.Rotate(Vector3.up * moveDelta * fRot * -1);
        }
        else if (Input.GetKey(KeyCode.D))
        {
            this.transform.rotation *= Quaternion.AngleAxis(moveDelta * fRot, Vector3.up);
        }
    }
}
