using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    private float liveTime = 0.0f;
    private float maxTime = 1.0f;
    private Vector3 dir;

    private float fSpeed = 500.0f;

    public GameObject obj = null;

    private void Start()
    {
        dir = new Vector3(transform.rotation.x, transform.rotation.y, transform.rotation.z);
        transform.Rotate(new Vector3(0, 0, 0));

        if (dir == Vector3.left)
            this.transform.position = new Vector3(this.transform.position.x - 250, this.transform.position.y, this.transform.position.z);
    }  

    void Update()
    {
        Update_Bullet();
    }

    private void Update_Bullet()
    {
        liveTime += Time.deltaTime;

        this.transform.Translate(dir * fSpeed * Time.deltaTime);

        
        if (liveTime >= maxTime)
        {
            Destroy(this.gameObject);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.tag.Contains("Wall"))
            return;

        if (this.tag.Contains("enemy") && collision.collider.tag.Contains("enemy"))
            return;

        if (!collision.collider.tag.Contains("Bullet") && this.tag != collision.collider.tag)
        {
            if (this.tag == "playerBullet" && collision.collider.tag == "enemy")
                GameManager.Instance.AddScore();

            Destroy(this.gameObject);

            Instantiate(obj, this.transform.position, this.transform.rotation);
        }
    }
}
