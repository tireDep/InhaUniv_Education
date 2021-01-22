using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameTitle : MonoBehaviour
{
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    private void OnGoNextScene()
    {
        GameManager.Instance.NextSceneName = "Game";
        SceneManager.LoadScene("Loading");
    }
}
