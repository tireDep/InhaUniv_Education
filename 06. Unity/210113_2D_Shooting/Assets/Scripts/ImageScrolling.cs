using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ImageScrolling : MonoBehaviour
{
    private float fSpeed = 100.0f;

    void Update()
    {
        this.transform.Translate(Vector3.left * fSpeed * Time.deltaTime);

        if(this.transform.position.x <= -1180)
        {
            this.transform.position = new Vector3(43, 0, 0);
        }
    }
}
