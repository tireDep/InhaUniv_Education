using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    private float nowTime = 0.0f;
    private float maxTime = 5.0f;

    private ShotEffect effect = null;

    private void Shot()
    {
        GameObject.FindGameObjectWithTag("bulletSpawner").GetComponent<BulletSpawner>().Shot(this.transform.position, Vector3.left);

        if(this.gameObject != null)
            Invoke("Shot", 1.0f);
    }

    private void Start()
    {
        Invoke("Shot", 1.0f);
    }

    void Update()
    {
        Move();
    }

    private void Move()
    {
        this.transform.Translate(Vector3.left * Time.deltaTime * 100.0f);

        nowTime += Time.deltaTime;

        if (nowTime >= maxTime)
            Destroy(this.gameObject);
        // todo : screen ÁÂÇ¥ ¹Û Destroy
    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(this.gameObject, 0.2f);
        effect = GetComponent<ShotEffect>();
        effect.transform.position = this.transform.position;
        effect.Setup(this.transform.position);
    }
}
