using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public GameObject effectObj_Player = null;
    public GameObject effectObj_Enemy = null;

    void Start()
    {

    }

    [SerializeField]
    private float limitTime = 10.0f;
    private float nowTime = 0.0f;
    private void FixedUpdate()
    {
        nowTime += Time.deltaTime;
        if (nowTime >= limitTime)
        {
            nowTime = 0.0f;
            Destroy(this.gameObject, 0.3f);
            GameObject.Find("ItemSpanwer").GetComponent<ItemSpawner>().ObjCnt = GameObject.Find("ItemSpanwer").GetComponent<ItemSpawner>().ObjCnt - 1;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        GameObject tempObj = null;

        if (other.CompareTag("Player") && effectObj_Player != null)
        {
            tempObj = Instantiate(effectObj_Player, this.transform.position, Quaternion.identity);
            other.GetComponentInParent<MecanimControl>().ItemCount = 1;
            SoundSys.Instance.StopAndPlay(0);
        }
        else if (other.CompareTag("Enemy") && effectObj_Enemy != null)
        {
            tempObj = Instantiate(effectObj_Enemy, this.transform.position, Quaternion.identity);
            other.GetComponent<NavEnemy>().setZero();
            other.GetComponentInParent<NavEnemy>().ItemCount = 1;
            SoundSys.Instance.StopAndPlay(1);
        }
        else
            return;

        this.GetComponent<BoxCollider>().enabled = false;

        if (tempObj != null)
            Destroy(tempObj.gameObject, 1.0f);

        Destroy(this.gameObject, 0.3f);

        GameObject.Find("ItemSpanwer").GetComponent<ItemSpawner>().ObjCnt = GameObject.Find("ItemSpanwer").GetComponent<ItemSpawner>().ObjCnt - 1;
    }

}
