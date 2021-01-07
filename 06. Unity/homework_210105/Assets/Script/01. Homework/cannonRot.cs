using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cannonRot : MonoBehaviour
{
    void Start()
    {
        
    }

    void Update()
    {
        float fRot = 10.0f;
        float fSpeed = 10.0f;
        float moveDelta = fSpeed * Time.deltaTime;

        if(Input.GetKey(KeyCode.Z))
        {
            this.transform.rotation *= Quaternion.AngleAxis(moveDelta * fRot * -1, Vector3.up);
        }
        else if (Input.GetKey(KeyCode.C))
        {
            this.transform.rotation *= Quaternion.AngleAxis(moveDelta * fRot, Vector3.up);
        }
    }
}
    