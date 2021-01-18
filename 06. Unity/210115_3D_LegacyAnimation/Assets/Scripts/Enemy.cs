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
    public bool EnemyCollisionState
    {
        get { return isCollision;  }
        set
        {
            if(!value)
            {
                isCollision = false;
                objSword.SetActive(false);
                animation.wrapMode = WrapMode.Loop;
                animation.CrossFade("run");
            }
        }
    }

    private bool isDead = false;

    public GameObject effectObj;

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
        // if(this.transform.position)
        // EnemySpawner.Instance.

        if(isDead)
        {
            animation.wrapMode = WrapMode.Once;

            if (!animation.IsPlaying("die"))
                Destroy(this.gameObject);
        }
        else
        {
            if (!isCollision)
            {
                this.transform.Translate(Vector3.forward * fSpeed * Time.deltaTime);
                fSpeed = 15.0f;
            }
            else
            {
                Invoke("Attack", 0.0f);
            }
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (isDead)
            return;

        if (other.tag == "Map" || other.tag == "Enemy")
            return;

        isCollision = true;
        fSpeed = 0.0f;
        if (other.tag == "Sword")
        {
            isDead = true;
            animation.Play("die");
            collider.enabled = false;
            Debug.Log("check");
        }
        else
        {
            Invoke("Attack", 0.0f);
        }
    }

    // IEnumerator Attack()
    private void Attack()
    {
        if (!isCollision || isDead)
            return;

        if (animation.IsPlaying("attack") != true )
        {
            GameObject tempObj = Instantiate(effectObj, this.transform.position, this.transform.rotation);

            objSword.SetActive(true);
            objSword.transform.position = new Vector3(0, 0, 0);
            objSword.transform.position = this.transform.position;

            animation.wrapMode = WrapMode.Once;
            animation.CrossFade("attack", 0.3f);

            // float fDelayTime = animation.GetClip("attack").length - 0.3f;
            // yield return new WaitForSeconds(fDelayTime);
            //  objSword.SetActive(false);
            //  animation.wrapMode = WrapMode.Loop;
            //  animation.CrossFade("run");
            // isCollision = false;

            Destroy(tempObj, 1.0f);
        }
        Invoke("Attack", 0.0f);
    }
}
