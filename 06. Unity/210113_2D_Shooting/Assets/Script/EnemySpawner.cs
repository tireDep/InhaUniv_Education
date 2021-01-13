using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    public GameObject obj = null;
    private float fRange = 150.0f;

    //private void Start()
    //{
    //    StartCoroutine("Create");
    //}

    IEnumerator Start()
    {
        while (true)
        {
            if (obj != null)
            {
                transform.position = new Vector3(
                    transform.position.x,
                    Random.Range(-fRange, fRange),
                    0);

                Instantiate(obj, transform.position, transform.rotation);
            }

            yield return new WaitForSeconds(3.0f);
        }
    }

}
