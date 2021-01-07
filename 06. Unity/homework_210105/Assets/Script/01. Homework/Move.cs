using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
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
            // this.transform.Translate(Vector3.forward * moveDelta);
            this.transform.Translate(Vector3.right * moveDelta);
        }
        else if (Input.GetKey(KeyCode.S))
        {
            // Vector3 pos = this.transform.position;
            // pos.x -= moveDelta;
            // this.transform.position = pos;
            // >> 방향에 따라 바뀔 수 있는 듯?

            this.transform.Translate(Vector3.left * moveDelta);
        }

        else if (Input.GetKey(KeyCode.A))
        {
            this.transform.Rotate(Vector3.up * moveDelta * fRot);
        }
        else if (Input.GetKey(KeyCode.D))
        {
            this.transform.rotation *= Quaternion.AngleAxis(moveDelta * fRot * -1, Vector3.up);
        }
    }
}
