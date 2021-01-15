using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    Animation animation;
    private CapsuleCollider collider = null;

    void Start()
    {
        animation = gameObject.GetComponentInChildren<Animation>();
        collider = gameObject.GetComponent<CapsuleCollider>();
    }

    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Sword")
        {
            animation.Play("die");
            collider.enabled = false;
        }
    }
}
