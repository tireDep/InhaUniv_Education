using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    //public Transform target;

    //private Transform tr;                // 카메라 자신의 Transform

    //void Start()
    //{
    //    tr = GetComponent<Transform>();
    //}

    //void LateUpdate()
    //{
    //    tr.position = new Vector3(target.position.x - 0.52f, tr.position.y, target.position.z - 6.56f);

    //    tr.LookAt(target);
    //}

    public GameObject target;

    public float offsetX;
    public float offsetY;
    public float offsetZ;

    public float DelayTime;

    void Update()
    {
        Vector3 FixedPos =
            new Vector3(
            target.transform.position.x + offsetX,
            target.transform.position.y + offsetY,
            target.transform.position.z + offsetZ);
        transform.position = Vector3.Lerp(transform.position, FixedPos, Time.deltaTime * DelayTime);
    }
}
