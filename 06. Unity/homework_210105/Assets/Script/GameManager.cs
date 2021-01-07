using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    // >> singleton
    private static GameManager sInstance;

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
}
