using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    Animation animation = null;
    public GameObject objSword = null;
    private CapsuleCollider collider = null;

    [SerializeField]
    private float fSpeed = 15.0f;

    private bool isCollision = false;


    void Start()
    {
        animation = gameObject.GetComponentInChildren<Animation>();
        animation.wrapMode = WrapMode.Loop;
        animation.CrossFade("run");

        collider = gameObject.GetComponent<CapsuleCollider>();

        objSword.SetActive(false);
    }

    void Update()
    {
        if (!isCollision)
        {
            this.transform.Translate(Vector3.forward * fSpeed * Time.deltaTime);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Map" || other.tag == "Enemy")
            return;

        isCollision = true;
        if (other.tag == "Sword")
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

            animation.wrapMode = WrapMode.Loop;
            animation.CrossFade("run");

            isCollision = false;
        }

    }
}
