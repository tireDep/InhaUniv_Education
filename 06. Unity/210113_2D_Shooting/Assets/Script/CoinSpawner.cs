using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CoinSpawner : MonoBehaviour
{
    public GameObject obj = null;
    private float fRange = 150.0f;

    IEnumerator Start()
    {
        while (true)
        {
            if (obj != null)
            {
                transform.position = new Vector3(
                    Random.Range(-fRange, fRange),
                    Random.Range(-fRange, fRange),
                    0);

                transform.rotation = new Quaternion(0, 0, 0, 1);

                Instantiate(obj, transform.position, transform.rotation);
            }

            yield return new WaitForSeconds(5.0f);
        }
    }
}
