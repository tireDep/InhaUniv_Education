using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DefenceWall : MonoBehaviour
{
    private int nHitCnt = 1;

    private float fMaxTime = 0.1f;
    private float fNowTime = 0.0f;
    private bool isChanged = false;

    void Start()
    {
        SetChildMaterial(new Color(1, 1, 1, 1.0f));
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.tag == "Enemy")
        {
            nHitCnt--;
            this.GetComponent<BoxCollider>().isTrigger = true;

            Invoke("SetMaterial", 0.2f);

            if (nHitCnt <= 0)
            {
                Destroy(this.gameObject, 0.5f);
            }
        }
    }

    private void SetMaterial()
    {
        if(fNowTime <= fMaxTime)
        {
            int numofChild = transform.childCount;

            for (int i = 0; i < numofChild; i++)
            {
                GameObject child = transform.GetChild(i).gameObject;
                child.GetComponent<Renderer>().material.shader = Shader.Find("Transparent/Diffuse");
                // >> 투명 쉐이더 적용
            }

            fNowTime += Time.deltaTime;

            if(isChanged)
            {
                isChanged = false;
                SetChildMaterial(new Color(1, 0, 0, 0.5f));
            }
            else
            {
                isChanged = true;
                SetChildMaterial(new Color(1, 1, 1, 0.5f));
            }

            Invoke("SetMaterial", 0.2f);
        }
        else
        {
            fNowTime = 0.0f;
            isChanged = false;
        }

        return;
    }

    private void SetChildMaterial(Color color)
    {
        int numofChild = transform.childCount;

        for (int i = 0; i < numofChild; i++)
        {
            GameObject child = transform.GetChild(i).gameObject;
            child.GetComponent<Renderer>().material.color = color;
        }
    }
}
