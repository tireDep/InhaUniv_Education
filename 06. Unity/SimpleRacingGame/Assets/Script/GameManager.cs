using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    // >> singleton
    private static GameManager sInstance;
    private int finishCheck = -1;
    GameObject[] objArr = null;
    float[] timeArr = null;
    string[] nameArr = null;

    private Hashtable remainTrack = new Hashtable();
    private Hashtable hashTRank = new Hashtable();

    public static GameManager Instance
    {
        get
        {
            if (sInstance == null)
            {
                GameObject newGameObject = new GameObject("_GameManager");
                sInstance = newGameObject.AddComponent<GameManager>();
            }
            return sInstance;
        }
    }

    private void Awake()
    {
        objArr = GameObject.FindGameObjectsWithTag("Vehicle");
        nameArr = new string[objArr.Length];

        finishCheck = objArr[0].GetComponent<AutoMove>().finishCheck;

        for (int i = 0; i < nameArr.Length; i++)
        {
            nameArr[i] = objArr[i].gameObject.name;
            
            remainTrack[objArr[i].gameObject.name] = finishCheck;
        }


        timeArr = new float[objArr.Length];
        for (int i = 0; i < timeArr.Length; i++)
            timeArr[i] = -1.0f;

        DontDestroyOnLoad(this.gameObject);
    }
    // << singleton

    public void LabTimeRecord(float labTime)
    {
        for (int i = 0; i < timeArr.Length; i++)
        {
            if (timeArr[i] < 0)
            {
                timeArr[i] = labTime;
                break;
            }
        }

        for (int i = 0; i < timeArr.Length; i++)
        {
            Debug.Log(timeArr[i]);
        }
    }

    public float[] GetLabTime()
    {
        return timeArr;
    }

    public string[] GetObjName()
    {
        return nameArr;
    }

    public void ResetLabTime()
    {
        for (int i = 0; i < timeArr.Length; i++)
            timeArr[i] = -1;

        rankNum = 0;
        for (int i = 0; i < hashTRank.Count; i++)
            hashTRank[i] = 0;

        for (int i = 0; i < nameArr.Length; i++)
        {
            remainTrack[nameArr[i]] = finishCheck;
        }
    }

    public void SetHashRemainTrack(string name, int track)
    {
        remainTrack[name] = track;
    }

    public Hashtable GetHashRemainTrack()
    {
        return remainTrack;
    }

    public Hashtable GetHashRank()
    {
        return hashTRank;
    }

    private int rankNum = 0;
    public void SetHashRank(string name, float time)
    {
        hashTRank[rankNum] = name + " / " + time.ToString();
        rankNum++;
    }
}
