using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    private static GameManager instance;
    public static GameManager Instance
    {
        get
        {
            if(instance == null)
            {
                GameObject newGameObject = new GameObject("GameManager");
                instance = newGameObject.AddComponent<GameManager>();
            }
            return instance;
        }
    }

    private void Awake()
    {
        DontDestroyOnLoad(this);
    }

    // ============================

    private string nextSceneName;
    public string NextSceneName
    {
        get { return nextSceneName; }
        set { nextSceneName = value; }
    }
}
