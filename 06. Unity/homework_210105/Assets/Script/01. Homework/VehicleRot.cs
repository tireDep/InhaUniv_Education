using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VehicleRot : MonoBehaviour
{
    void Start()
    {

    }

    public GameObject target = null;
    Quaternion preRot = new Quaternion(0,0,0,0);
    Vector3 prePos = new Vector3(0, 0, 0);
    void Update()
    {
        float fRot = 10.0f;
        float fSpeed = 10.0f;
        float moveDelta = fSpeed * Time.deltaTime;

        // else if (Input.GetKey(KeyCode.D))
        // {
        //     if (transform.rotation.x >= 120)
        //         transform.rotation = Quaternion.Euler(-120, 0, 0);
        //     else if (transform.rotation.x <= 90 && transform.rotation.x < 120)
        //         transform.rotation = Quaternion.Euler(-90, 0, 0);
        // }

        // Vector3 pos = this.transform.position;
        // this.transform.RotateAround(new Vector3(pos.x, pos.y, pos.z), Vector3.forward, moveDelta * fRot);

        // transform.rotation = Quaternion.Euler(90, 0, moveDelta * fRot * fSpeed);
        // >> 같이 돌아가긴 함

        // if(Input.GetKey(KeyCode.A))
        //     transform.rotation = Quaternion.Euler(-moveDelta, 0, 0);
        // else if(Input.GetKey(KeyCode.D))
        //     transform.rotation = Quaternion.Euler(moveDelta, 0, 0);

        //if(target!=null)
        //{
        //    if(preRot != target.transform.rotation)
        //    {
        //        transform.rotation = Quaternion.Euler(90, 0, 0);
        //        preRot = target.transform.rotation;
        //    }
        //}

        // Vector3 pos = target.transform.position;
        // if(prePos != pos)
        transform.rotation *= Quaternion.AngleAxis(moveDelta * fRot * fSpeed, Vector3.down);
    }
}
