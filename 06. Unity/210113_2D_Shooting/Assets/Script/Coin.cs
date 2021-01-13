using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coin : MonoBehaviour
{
    private float liveTime = 0.0f;
    private float maxTime = 2.0f;

    void Update()
    {
        liveTime += Time.deltaTime;

        if (liveTime >= maxTime)
            Destroy(this.gameObject);
    }
}
