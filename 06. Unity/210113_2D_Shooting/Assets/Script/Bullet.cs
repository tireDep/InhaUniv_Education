using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    private float liveTime = 0.0f;
    private float maxTime = 1.0f;
    private Vector3 dir;

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

        
        this.transform.Translate(dir * 5.0f);

        
        if (liveTime >= maxTime)
        {
            Destroy(this.gameObject);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(this.gameObject);
    }
}
