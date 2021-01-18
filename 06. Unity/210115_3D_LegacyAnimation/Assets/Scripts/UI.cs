using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UI : MonoBehaviour
{
    public Button mainToGameBtn = null;

    public Text scoreText = null;

    public Text endScore = null;
    public Button endToMainBtn = null;

    void Start()
    {
        
    }

    private void Update()
    {
        if (SceneManager.GetActiveScene().name == "01. Game")
        {
            if (scoreText != null)
                // scoreText.text = "Score : " + GameObject.FindGameObjectWithTag("Player").GetComponent<PlayerControl>().Score.ToString();
                scoreText.text = "Score : " + GameManager.Instance.Score.ToString();
        }
        else if (SceneManager.GetActiveScene().name == "02. End")
        {
            if(endScore!=null)
                endScore.text = "Score : " + GameManager.Instance.Score.ToString();
        }
    }

    public void onEndToMain()
    {
        GameManager.Instance.SetScene("00. Start");
    }

    public void onMainToGame()
    {
        GameManager.Instance.SetScene("01. Game");
    }
}
