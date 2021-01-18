using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    private static GameManager sInstance = null;

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

    private int score = 0;
    public int Score
    {
        get { return score; }
        set { score = value; }
    }

    private void Awake()
    {
        DontDestroyOnLoad(this.gameObject);
    }

    public void SetScene(string sceneName)
    {
        SceneManager.LoadScene(sceneName);
    }
}
