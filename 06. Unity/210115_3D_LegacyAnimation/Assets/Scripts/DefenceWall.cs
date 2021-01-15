using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DefenceWall : MonoBehaviour
{
    private int nHitCnt = 3;

    private float fMaxTime = 0.05f;
    private float fNowTime = 0.0f;
    private bool isChanged = false;

    void Start()
    {
        SetChildMaterial(new Color(1, 1, 1, 1));
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.tag == "EnemySword")
        {
            // this.GetComponent<BoxCollider>().isTrigger = true;

            Invoke("SetMaterial", 0.0f);

            if (nHitCnt < 0)
            {
                SetChildShader("Transparent/Diffuse");
                SetChildMaterial(new Color(1, 1, 1, 0.5f));

                Destroy(this.gameObject);
                
                collision.collider.GetComponentInParent<Enemy>().EnemyCollisionState = false;
                // >> 부모 컴포넌트
            }
        }
    }

    private void SetMaterial()
    {
        fNowTime += Time.deltaTime;

        if(fNowTime <= fMaxTime)
        {
            SetChildShader("Transparent/Diffuse");

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

            Invoke("SetMaterial", 0.1f);
        }
        else
        {
            SetChildShader("Standard");
           
            nHitCnt--;
            fNowTime = 0.0f;
            isChanged = false;
            SetChildMaterial(new Color(1, 1, 1, 1));
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

    private void SetChildShader(string strShader)
    {
        int numofChild = transform.childCount;

        for (int i = 0; i < numofChild; i++)
        {
            GameObject child = transform.GetChild(i).gameObject;
            child.GetComponent<Renderer>().material.shader = Shader.Find(strShader);
        }
    }
}
