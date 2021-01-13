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
        // this.gameObject.transform.Rotate(Vector3.forward * verticalMove); // ȸ��
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
        // -> Ű���� ���� ���� ��� ������
        // -> 2D������ ���ڿ������� �� ����
        rigidbody2D.AddForce(new Vector2(x * fSpeedMove * Time.deltaTime, y * fSpeedMove * Time.deltaTime));
    }

    private void Move_MovePosition(float x, float y)
    {
        // -> Ű���� ���� ���� �������� ����
        // -> ������Ģ ����Ǽ� ���������� �Ͼ
        Vector3 position = rigidbody2D.transform.position;
        position = new Vector3(
            position.x + (x * fSpeedMove * Time.deltaTime),
            position.y + (y * fSpeedMove * Time.deltaTime),
            position.z);

        rigidbody2D.MovePosition(position);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // -> ���� ���� ����
        // -> ��ũ��Ʈ ��¿� Ȱ�밡����
        Debug.Log("<color=red>�浹 : </color>" + collision.gameObject.name);

        Destroy(collision.gameObject, 0.5f);
        // -> ���� ������
    }
}
