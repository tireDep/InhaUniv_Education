using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2D : MonoBehaviour
{
    private Rigidbody2D rigidbody2D = null;
    private float fSpeedMove = 2500.0f;

    private SpriteRenderer spriteRenderer = null;
    private CircleCollider2D circleCollider2D = null;

    private Vector2 vec2Offset;

    private float hitTimer = 0.0f;
    private float maxTime = 0.025f;
    private Color color = Color.white;

    private bool isHit = false;

    private Vector3 dir = Vector3.right;
    public Vector3 Direction
    {
        get
        {
            return dir;
        }
    }

    void Start()
    {
        rigidbody2D = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        circleCollider2D = GetComponent<CircleCollider2D>();

        vec2Offset = circleCollider2D.offset;
    }

    void Update()
    {
        // Move();
        CheckLife();
        RigidbodyMove();
    }

    private void CheckLife()
    {
        // if(fLife <= 0.0f)
        //     GameManager.Instance.
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

        Filp_2D(x);

        // Move_AddForce(x, y);
        Move_MovePosition(x, y);

        Attack();
    }

    private void Filp_2D(float x)
    {
        // -> �Է¹��⿡ ���� �̹��� ������
        // -> �����⸸ �� ��� �ݶ��̴��� �Բ� �������� ������ �����ؾ���!
        // -> offset �缳�� �ʿ�

        if(Mathf.Abs(x) > 0)
        {
            if(x>=0)
            {
                circleCollider2D.offset = vec2Offset;
                spriteRenderer.flipX = false;
                dir = Vector3.right;
            }
            else
            {
                dir = Vector3.left;
                circleCollider2D.offset = vec2Offset * -1;
                spriteRenderer.flipX = true;
            }
        }
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

    private bool isPress = false;
    private float inputDelay = -0.0001f;
    private float maxDelay = 0.1f;
    private void Attack()
    {
        if (isPress && inputDelay <= maxDelay)
        {
            inputDelay += Time.deltaTime;
            return;
        }
        else
        {
            isPress = false;
            inputDelay = -0.0001f;
        }

        if(Input.GetKeyDown(KeyCode.Space))
        {
            GetComponent<SoundTest>().setSound(0);
            isPress = true;
            Vector3 pos = this.transform.position;
            GameObject.FindGameObjectWithTag("bulletSpawner").GetComponent<BulletSpawner>().Shot(this.transform.position, dir);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // -> ���� ���� ����
        // -> ��ũ��Ʈ ��¿� Ȱ�밡����
        Debug.Log("<color=red>�浹 : </color>" + collision.gameObject.name);

        GetComponent<SoundTest>().setSound(1);

        GameManager.Instance.AddScore();

        Destroy(collision.gameObject, 0.2f);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.tag.Contains("Wall") || isHit)
            return;

        Destroy(collision.gameObject);
        GameManager.Instance.LoseLife();
        GetComponent<SoundTest>().setSound(2);
        Invoke("Effect", 0.1f);
    }

    private void Effect()
    {
        hitTimer += Time.deltaTime;

        if (hitTimer <= maxTime)
        {
            isHit = true;

            if (color == Color.white)
                color = Color.red;
            else if (color == Color.red)
                color = Color.white;

            spriteRenderer.color = color;
            // spriteRenderer.color = new Color(color.r, color.g, color.b, 150);
            // -> alpha ����?
            Invoke("Effect", 0.2f);
        }
        else
        {
            hitTimer = 0.0f;
            color = Color.white;
            // spriteRenderer.color = new Color(color.r, color.g, color.b, 255);
            spriteRenderer.color = color;
            isHit = false;
        }

    }
}
