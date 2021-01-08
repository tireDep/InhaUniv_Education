using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class FB_GameManager : MonoBehaviour
{
    public float fScore = 0.0f;
    private static FB_GameManager sInstance;

    public static FB_GameManager Instance
    {
        get
        {
            if (sInstance == null)
            {
                GameObject newGameObject = new GameObject("FB_GameManager");
                sInstance = newGameObject.AddComponent<FB_GameManager>();
            }
            return sInstance;
        }
    }

    private void Awake()
    {
        DontDestroyOnLoad(this.gameObject);
    }

    public void ChangeSceneStrName(string scene)
    {
        SceneManager.LoadScene(scene);
    }

}
