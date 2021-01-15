using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    Animation animation = null;
    public GameObject objSword = null;
    private CapsuleCollider collider = null;

    private float fSpeed = 10.0f;

    private bool isCollision = false;


    void Start()
    {
        animation = gameObject.GetComponentInChildren<Animation>();
        animation.wrapMode = WrapMode.Loop;
        animation.CrossFade("walk");

        collider = gameObject.GetComponent<CapsuleCollider>();

        objSword.SetActive(false);
    }

    void Update()
    {
        if (!isCollision)
        {
            // this.transform.Translate(Vector3.forward * fSpeed * Time.deltaTime);
            this.transform.position += Vector3.back * fSpeed * Time.deltaTime;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Map" || collision.collider.tag == "Enemy")
            return;

        isCollision = true;
        if (collision.collider.tag == "Sword")
        {
            animation.Play("die");
            collider.enabled = false;
        }
        else
        {
            StartCoroutine("Attack");
        }
    }

    IEnumerator Attack()
   {
        if (animation.IsPlaying("attack") != true )
        {
            objSword.SetActive(true);
            objSword.transform.position = new Vector3(0, 0, 0);
            objSword.transform.position = this.transform.position;

            animation.wrapMode = WrapMode.Once;
            animation.CrossFade("attack", 0.3f);

            float fDelayTime = animation.GetClip("attack").length - 0.3f;

            yield return new WaitForSeconds(fDelayTime);

            objSword.SetActive(false);
            animation.CrossFade("walk", 0.3f);

            isCollision = false;
        }

        // Invoke("Attack", 0.2f);
    }
}
