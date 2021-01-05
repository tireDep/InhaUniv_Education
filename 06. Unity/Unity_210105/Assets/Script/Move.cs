using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    // [SerializeField]
    private float moveSpeed = 1.0f;
    // 객체 생성시 한 번
    private void Awake()
    {

    }

    // 스크립트 실행될 때 한 번
    void Start()
    {    
        // this.transform.position = new Vector3(0.0f, 5.0f, 0.0f); // 절대 좌표
        // this.transform.Translate(new Vector3(0.0f, 5.0f, 0.0f)); // 상대 좌표
    }

    // 매 프레임
    void Update()
    {
        DoMove();
    }

    void DoMove()
    {
        // float moveDelta = this.moveSpeed * Time.deltaTime;
        // Vector3 pos = this.transform.position;
        // pos.z += moveDelta;
        // 
        // this.transform.position = pos;

        float moveDelta = this.moveSpeed * Time.deltaTime;
        this.transform.Translate(Vector3.right * moveDelta);
    }

}
