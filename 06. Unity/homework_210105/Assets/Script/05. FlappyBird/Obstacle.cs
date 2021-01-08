using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obstacle : MonoBehaviour
{
    private float fSpeed = 10.0f;
    private float fTime = 0.0f;
    private float fDeleteTime = 3.0f;

    private Vector3 targetPos;

    void Start()
    {

    }

    void Update()
    {
        //if (fTime >= fDeleteTime)
        //    ObjDestroy();

        //fTime += Time.deltaTime;

        targetPos = Camera.main.WorldToScreenPoint(this.transform.position);
        if (targetPos.x <= -10.0f)
            ObjDestroy();

        AutoMove();
    }

    private void AutoMove()
    {
        this.transform.Translate(Vector3.left * fSpeed * Time.deltaTime);
    }

    private void ObjDestroy()
    {
        Destroy(this.gameObject);
    }

}
