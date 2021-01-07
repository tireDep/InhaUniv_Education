using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SmallPropellerRot : MonoBehaviour
{
    void Start()
    {
        
    }

    public GameObject target = null;
    void Update()
    {
        float fRot = 10.0f;
        float fSpeed = 10.0f;
        float moveDelta = fSpeed * Time.deltaTime;

        if (target != null)
        {
            Vector3 pos = target.transform.position;

             this.transform.RotateAround(new Vector3(pos.x, pos.y, pos.z), Vector3.back, moveDelta * fRot);
        }
    }
}
