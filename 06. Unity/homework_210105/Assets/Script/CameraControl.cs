using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraControl : MonoBehaviour
{
    Camera mainCamera;
    void Start()
    {
        mainCamera = this.GetComponent<Camera>();
    }

    // << cullMode
    private void OnPreCull()
    {

    }

    private void OnPreRender()
    {

    }
    // >> 이미지가 깨져서 나올경우 컬링문제
    // >> 좌우반전 등 필요할 수도 있음
    // >> cullMode

    void Update()
    {
        MoveCamera();

        // RotateCamera();
        RotateCamera_Center();

        ZoomCamera();
    }

    void MoveCamera()
    {
        if(Input.GetMouseButton(0))
        {
            // >> 좌클릭
            this.transform.Translate(
                Input.GetAxisRaw("Mouse X") / 5.0f * -1, 
                Input.GetAxisRaw("Mouse Y") / 5.0f * -1,
                0.0f);
        }
    }

    void RotateCamera()
    {
        if(Input.GetMouseButton(1))
        {
            // 우클릭
            // >> y축 기준 회전
            this.transform.Rotate(0.0f, Input.GetAxisRaw("Mouse X") * 5.0f, 0.0f);
        }
    }

    void RotateCamera_Center()
    {
        if (Input.GetMouseButton(1))
        {
            // >> 공전
            Transform temp = GameObject.FindGameObjectWithTag("Player").transform;
            this.transform.RotateAround(temp.position, new Vector3(0.0f, Input.GetAxisRaw("Mouse X") * 5.0f, 0.0f), 5);
        }
    }

    void ZoomCamera()
    {
        mainCamera.fieldOfView += (20.0f * Input.GetAxis("Mouse ScrollWheel"));

        if (mainCamera.fieldOfView < 10)
            mainCamera.fieldOfView = 10;
    }
}
