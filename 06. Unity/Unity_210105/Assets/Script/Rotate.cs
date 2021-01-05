using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotate : MonoBehaviour
{

    private float rotSpeed = 10.0f;

    // Start is called before the first frame update
    void Start()
    {
        Look_At();
    }

    // Update is called once per frame
    void Update()
    {
       Vector
    }

    // ==============

    void Rot_1()
    {
        this.transform.eulerAngles = new Vector3(0.0f, 45.0f, 0.0f);
        // 오일러각
    }

    void Rot_2()
    {
        Quaternion target = Quaternion.Euler(0.0f, 45.0f, 0.0f);
        transform.rotation = target;
        // 쿼터니언
    }

    void Rot_3()
    {
        this.transform.Rotate(Vector3.up, 60.0f);
    }

    void Rot_4()
    {
        this.transform.rotation *= Quaternion.AngleAxis(10.0f, Vector3.forward);
    }

    void Rot_5()
    {
        float rot = rotSpeed * Time.deltaTime;
        transform.rotation *= Quaternion.AngleAxis(rot, Vector3.up);
    }

    void Rot_6()
    {
        this.transform.RotateAround(new Vector3(0.0f, 0.0f, 0.0f), Vector3.up, Time.deltaTime * rotSpeed);
        // 원점 기준 회전
    }

    public GameObject target = null;
    void Look_At()
    {
        if(target != null)
        {
            Vector3 dirToTarget = target.transform.position - this.transform.position;
            this.transform.forward = dirToTarget.normalized;
        }
    }
}
