using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2D : MonoBehaviour
{
    private Rigidbody2D rigidbody2D = null;
    private float fSpeedMove = 1000.0f;

    void Start()
    {
        rigidbody2D = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        // Move();
        RigidbodyMove();
    }

    private void Move()
    {
        float horizontalMove = Input.GetAxis("Horizontal");
        horizontalMove = horizontalMove * fSpeedMove * Time.deltaTime;
        this.gameObject.transform.Translate(Vector3.right * horizontalMove);

        float verticalMove = Input.GetAxis("Vertical");
        verticalMove = verticalMove * fSpeedMove * Time.deltaTime;
        // this.gameObject.transform.Rotate(Vector3.forward * verticalMove); // 회전
        this.gameObject.transform.Translate(Vector3.up * verticalMove);
    }

    private void RigidbodyMove()
    {
        float x = Input.GetAxis("Horizontal");
        float y = Input.GetAxis("Vertical");

        // Move_AddForce(x, y);
        Move_MovePosition(x, y);
    }

    private void Move_AddForce(float x, float y)
    {
        // -> 키에서 손을 떼도 계속 움직임
        // -> 2D에서는 부자연스러울 수 있음
        rigidbody2D.AddForce(new Vector2(x * fSpeedMove * Time.deltaTime, y * fSpeedMove * Time.deltaTime));
    }

    private void Move_MovePosition(float x, float y)
    {
        // -> 키에서 손을 떼면 움직이지 않음
        // -> 물리법칙 적용되서 지연현상이 일어남
        Vector3 position = rigidbody2D.transform.position;
        position = new Vector3(
            position.x + (x * fSpeedMove * Time.deltaTime),
            position.y + (y * fSpeedMove * Time.deltaTime),
            position.z);

        rigidbody2D.MovePosition(position);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // -> 색상 지정 가능
        // -> 스크립트 출력에 활용가능함
        Debug.Log("<color=red>충돌 : </color>" + collision.gameObject.name);

        Destroy(collision.gameObject, 0.5f);
        // -> 삭제 딜레이
    }
}
