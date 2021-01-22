using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    private float nowTime = 0.0f;
    private float maxTime = 5.0f;

    private float shotTime = 1.5f;

    private float fSpeed = 100.0f;

    private void Shot()
    {
        GameObject.FindGameObjectWithTag("bulletSpawner").GetComponent<BulletSpawner>().EnemyShot(this.transform.position, Vector3.left);

        if(this.gameObject != null)
            Invoke("Shot", shotTime);
    }

    private void Start()
    {
        Invoke("Shot", shotTime);
    }

    void Update()
    {
        Move();
    }

    private void Move()
    {
        //nowTime += Time.deltaTime;

        //if (nowTime >= maxTime)
        //    Destroy(this.gameObject);
        //// todo : screen ÁÂÇ¥ ¹Û Destroy
        ///

        this.transform.Translate(Vector3.left * Time.deltaTime * fSpeed);

        Vector3 targetPos = Camera.main.WorldToScreenPoint(this.transform.position);

        if (targetPos.x <= -10.0f)
            Destroy(this.gameObject);
    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (this.tag.Contains("enemy") && collision.collider.tag.Contains("enemy"))
            return;

        Destroy(this.gameObject);
    }
}
