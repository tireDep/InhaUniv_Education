using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    // >> singleton
    private static GameManager sInstance;
    GameObject[] objArr = null;
    float[] timeArr = null;

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

        timeArr = new float[objArr.Length];
        for (int i = 0; i < timeArr.Length; i++)
            timeArr[i] = -1.0f;

        DontDestroyOnLoad(this.gameObject);
    }
    // << singleton

    // ====================================

    // private void OnGUI()
    // {
    //     ChangeScene();
    // }
    // 
    // public int nSceneID = 0;
    // private void ChangeScene()
    // {
    //     if(nSceneID == 0)
    //     {
    //         Debug.Log("씬전환");
    //     }
    // }

    // ===================================

    public void LabTimeRecord(float labTime)
    {
        for (int i = 0; i < timeArr.Length; i++)
        {
            if (timeArr[i] == -1)
            {
                timeArr[i] = labTime;
                break;
            }
        }
    }

    public float[] GetLabTime()
    {
        return timeArr;
    }

    public string[] GetObjName()
    {
        string[] result = new string[objArr.Length];

        for (int i = 0; i < result.Length; i++)
            result[i] = objArr[i].gameObject.name;

        return result;
    }

    public void ResetLabTime()
    {
        for (int i = 0; i < timeArr.Length; i++)
            timeArr[i] = -1;
    }

}
