using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collision : MonoBehaviour
{
    /// >> Checked
    //// Awake
    //
    //// OnEnable 
    //
    //// Start
    //
    //// Fixed Update 
    //// : 지정된 시간에 업데이트 실행(0.02초로 고정, 수정 가능은 함), 
    //// 델타타임 필요 x, 물리나 충돌 체크
    //
    //// Update : 물리 x 단순한 시간, 움직임 등
    //
    //// LateUpdate : 업데이트 실행 후, 카메라 같은 것
    //
    //// OnBecameVisible / OnBecameInvisible : 화면상에 보임 / 안보임
    //
    //private void Awake()
    //{
    //    print("Awake Call");
    //}
    //
    //private void OnEnable()
    //{
    //    print("OnEnable Call");
    //}
    //
    //void Start()
    //{
    //    print("Start Call");
    //}
    //
    //void Update()
    //{
    //    print("Update Call");
    //}
    //
    //private void LateUpdate()
    //{
    //    print("LateUpdate Call");
    //}
    //
    //private void FixedUpdate()
    //{
    //    print("FixedUpdate Call");
    //}
    //
    //private void OnDisable()
    //{
    //    print("OnDisable Call");
    //}
    //
    //private void OnDestroy()
    //{
    //    print("OnDestroy Call");
    //}
    //
    //private void OnBecameVisible()
    //{
    //    print("OnBecameVisible Call");
    //}
    //
    //private void OnBecameInvisible()
    //{
    //    print("OnBecameInvisible Call");
    //}

    public float fSpeedRot = 1.0f;
    public float fSpeedMove = 0.5f;

    Rigidbody rigidbody = null;

    private void Start()
    {
        rigidbody = this.gameObject.GetComponent<Rigidbody>();
    }

    private void Update()
    {
        
    }

    private void FixedUpdate()
    {
        MoveRotate();
    }

    private void MoveRotate()
    {
        float rot = Input.GetAxis("Horizontal");
        // GetAxis : 왼쪽, 오른쪽 누름이 1, -1
        // GetAxisRaw : 누름 & 미묘한 수치값

        float move = Input.GetAxis("Vertical");

        rot = rot * fSpeedRot;
        move = move * fSpeedMove;

        this.gameObject.transform.Rotate(Vector3.up * rot);
        this.gameObject.transform.Translate(Vector3.forward * move);
    }

    // >> 충돌처리
    private void OnCollisionEnter(UnityEngine.Collision collision)
    {
        // 충돌 발생 시점
        GameObject hitObj = collision.gameObject;
        print("충돌 시작 : " + hitObj.name);
    }

    private void OnCollisionStay(UnityEngine.Collision collision)
    {
        // 충돌 중
        GameObject hitObj = collision.gameObject;
        print("충돌 중 : " + hitObj.name);
    }

    private void OnCollisionExit(UnityEngine.Collision collision)
    {
        // 충돌 종료 시점
        GameObject hitObj = collision.gameObject;
        print("충돌 종료 : " + hitObj.name);
    }

    private void OnTriggerEnter(Collider other)
    {
        GameObject hitObj = other.gameObject;
        print("트리거 충돌 시작 : " + hitObj.name);
    }

    private void OnTriggerStay(Collider other)
    {
        GameObject hitObj = other.gameObject;
        print("트리거 충돌 중 : " + hitObj.name);
    }

    private void OnTriggerExit(Collider other)
    {
        GameObject hitObj = other.gameObject;
        print("트리거 충돌 종료 : " + hitObj.name);
    }
    // << 충돌처리
}
