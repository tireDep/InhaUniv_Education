using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;

public class ItemSpawner : MonoBehaviour
{
    [System.Serializable]
    public class GemClass
    {
        public string tag;
        // 태그

        // public GameObject[] GemArr;
        public GameObject GemPrefab_1;
        public GameObject GemPrefab_2;
        public GameObject GemPrefab_3;
        // 종류

        public int size;
        // 생성 크기
    }

    public List<GemClass> ObjectPools;
    public Dictionary<string, Queue<GameObject>> dicPools;

    NavMeshAgent agent;
    GameObject navMesh;

    #region Singleton
    public static ItemSpawner Instance;
    private void Awake()
    {
        Instance = this;

        agent = GetComponent<NavMeshAgent>();
        ResultDialog.SetActive(false);
        InGameDiallog.SetActive(true);

        dicPools = new Dictionary<string, Queue<GameObject>>();

        foreach (GemClass gem in ObjectPools)
        {
            Queue<GameObject> objectPool = new Queue<GameObject>();

            int rndNum = 0;
            for(int i=0;i<gem.size;i++)
            {
                rndNum = Random.Range(0, 2);
                GameObject obj = null;
                switch(rndNum)
                {
                    case 0:
                        obj = Instantiate(gem.GemPrefab_1);
                        break;

                    case 1:
                        obj = Instantiate(gem.GemPrefab_2);
                        break;

                    case 2:
                        obj = Instantiate(gem.GemPrefab_3);
                        break;
                }
                obj.SetActive(false);
                objectPool.Enqueue(obj);
            }

            dicPools.Add(gem.tag, objectPool);
            cnt = gem.size;
        }

    }
    #endregion


    public GameObject SpawnFromPool(string tag, Vector3 position, Quaternion rotation)
    {
        if(!dicPools.ContainsKey(tag))
        {
            Debug.LogWarning("Pool witdh tag" + tag + "doesn't exist");
            return null;
        }

        GameObject objectToSpwan = dicPools[tag].Dequeue();

        if (objectToSpwan == null)
            return null;

        objectToSpwan.SetActive(true);

        objectToSpwan.transform.position = position;
        objectToSpwan.transform.rotation = rotation;

        dicPools[tag].Enqueue(objectToSpwan);

        return objectToSpwan;
    }

    [SerializeField]
    private float limitTime = 5.0f;
    private float nowTime = 0.0f;

    public GameObject InGameDiallog = null;
    public Text CntText = null;
    public Text PlayerScoreText = null;
    public Text EnemySocreText = null;
    private int cnt;
    public int ObjCnt
    {
        get { return cnt; }
        set { cnt = value; }
    }

    public GameObject ResultDialog = null;
    public Text FinScore = null;
    public Text PlayerState = null;
    private void FixedUpdate()
    {
        if(cnt > 0)
        {
            CntText.text = cnt.ToString();
            PlayerScoreText.text = GameObject.FindGameObjectWithTag("Player").GetComponent<MecanimControl>().ItemCount.ToString();
            EnemySocreText.text = GameObject.FindGameObjectWithTag("Enemy").GetComponent<NavEnemy>().ItemCount.ToString();

            nowTime += Time.deltaTime;
            if (nowTime >= limitTime)
            {
                nowTime = 0.0f;
                DoSpwan();
            }
        }
        else
        {
            InGameDiallog.SetActive(false);
            ResultDialog.SetActive(true);

            if (GameObject.FindGameObjectWithTag("Player").GetComponent<MecanimControl>().ItemCount > GameObject.FindGameObjectWithTag("Enemy").GetComponent<NavEnemy>().ItemCount)
                PlayerState.text = "Player Win";
            else
                PlayerState.text = "Player Defeat";

            FinScore.text = PlayerScoreText.text + " : " + EnemySocreText.text;
        }
    }

    private void DoSpwan()
    {
        Vector3 pos = new Vector3(0, 0, 0);

        while(true)
        {
            agent.transform.position = new Vector3(Random.Range(-20, 20), 2, Random.Range(0, 20));

            if (agent.CalculatePath(agent.transform.position, agent.path))
            {
                pos = agent.transform.position;
                break;
            }
        }

        SpawnFromPool("Gem", pos, Quaternion.identity);
    }
}
