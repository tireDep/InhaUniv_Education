using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    // public GameObject enemyObj = null;

    [System.Serializable]
    public class Pool
    {
        public string tag;
        public GameObject prefab;
        public int size;
    }

    public List<Pool> Pools;
    public Dictionary<string, Queue<GameObject>> dicPool;

    #region Singleton
    public static EnemySpawner Instance;
    private void Awake()
    {
        Instance = this;

        dicPool = new Dictionary<string, Queue<GameObject>> ();

        // if(enemyObj != null)
        // {
        //     Instantiate(enemyObj, this.transform.position, this.transform.rotation);
        // }

        foreach (Pool pool in Pools)
        {
            Queue<GameObject> objectPool = new Queue<GameObject>();

            for (int i = 0; i < pool.size; i++)
            {
                GameObject obj = Instantiate(pool.prefab);
                obj.SetActive(false);

                objectPool.Enqueue(obj);
            }

            dicPool.Add(pool.tag, objectPool);
        }
    }
    #endregion

    public GameObject SpwanFormPool(string tag, Vector3 position, Quaternion rotation)
    {
        if(!dicPool.ContainsKey(tag))
        {
            Debug.LogWarning("Pool with tag" + tag + "doesn't exist");
            return null;
        }

        GameObject objectToSpwan = dicPool[tag].Dequeue();

        objectToSpwan.SetActive(true);
        objectToSpwan.transform.position = position;
        objectToSpwan.transform.rotation = rotation;

        // IPooledObject pooledObj = objectToSpwan.GetComponent<IPooledObject>();
        // if(pooledObj!=null)
        // {
        //     pooledObj.OnObjectSpwan(); 
        // }

        dicPool[tag].Enqueue(objectToSpwan);


        return objectToSpwan;
    }


    private float limitTime = 2.0f;
    private float nowTime = 0.0f;
    private void Update()
    {
        nowTime += Time.deltaTime;
        if(nowTime >= limitTime)
        {
            nowTime = 0.0f;
            DoSpwan();
        }
    }

    private void DoSpwan()
    {
        Vector3 pos = new Vector3(1.7f, 0.0f, 75.3f);
        int rndNum = Random.Range(0, 4);

        switch(rndNum)
        {
            case 0:
                pos = new Vector3(-19.75f, 0.0f, 75.3f - 25.0f);
                break;

            case 1:
                pos = new Vector3(-9.0f, 0.0f, 75.3f - 25.0f);
                break;

            case 2:
                pos = new Vector3(1.7f, 0.0f, 75.3f - 25.0f);
                break;


            case 3:
                pos = new Vector3(12.6f, 0.0f, 75.3f - 25.0f);
                break;


            case 4:
                pos = new Vector3(23.5f, 0.0f, 75.3f - 25.0f);
                break;
        }    

        EnemySpawner.Instance.SpwanFormPool("Enemy", pos, this.transform.rotation);
    }
}
