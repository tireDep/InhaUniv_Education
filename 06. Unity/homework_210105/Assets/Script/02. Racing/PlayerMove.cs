using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public int finishCheck = 2;
    public bool isFinish = false;

    public float fRot = 100.0f;
    public float fSpeed = 100.0f;

    void Start()
    {
        
    }

    void Update()
    {
        if (isFinish)
        {
            ReduceSpeed();
        }
        else
        {
            float moveDelta = fSpeed * Time.deltaTime;

            if (Input.GetKey(KeyCode.W))
                this.transform.Translate(Vector3.forward * moveDelta);
            else if (Input.GetKey(KeyCode.S))
                this.transform.Translate(Vector3.back * moveDelta);
            
            if (Input.GetKey(KeyCode.A))
                this.transform.rotation *= Quaternion.AngleAxis(moveDelta * -1, Vector3.up);
            else if (Input.GetKey(KeyCode.D))
                this.transform.Rotate(Vector3.up * moveDelta);
        }
    }

    private void ReduceSpeed()
    {
        if (fSpeed > 0)
            fSpeed -= 0.1f;
    }
}
