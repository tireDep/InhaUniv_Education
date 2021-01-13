using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletSpawner : MonoBehaviour
{
    public GameObject obj = null;

    public void Shot(Vector3 pos, Vector3 dir)
    {
        // todo : 배열 형식으로 바꿔보기
        Vector3 setPos = new Vector3
            (
            pos.x + 150.0f,
            pos.y - 50.0f,
            0
            );

        Instantiate(obj, setPos, new Quaternion(dir.x, dir.y, dir.z, 0));
    }
}
