using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class UI : MonoBehaviour
{
    private Scene scene;

    private bool isChangeMain = false;
    private bool isChangeGame = false;
    private void OnGUI()
    {
        scene = SceneManager.GetActiveScene();

        if (scene.name.Contains("Main"))
        {
            if(isChangeMain == false)
            {
                // GameManager.Instance.SetBGM(0);
                isChangeMain = true;
            }

            SceneChangeUI("StartScene", "Start", "01. Game");
            GameManager.Instance.Reset();
        }

        else if (scene.name.Contains("End"))
        {
            Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);
            GUI.Box(new Rect(camPos.x - 30, camPos.y - 50, 100, 30), "Score : " + GameManager.Instance.Score);

            SceneChangeUI("EndScene", "Retry", "00. Main");

            isChangeGame = false;
            isChangeMain = false;
        }

        else if (scene.name.Contains("Game"))
        {
            if (isChangeGame == false)
            {
                // GameManager.Instance.SetBGM(1);
                isChangeGame = true;
            }

            GUILayout.Label("PlayerLife : " + GameManager.Instance.Life);
            GUILayout.Label("PlayerScore : " + GameManager.Instance.Score);
        }

    }

    private void SceneChangeUI(string nowSceneName, string btnName, string nextScene)
    {
        Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);

        GUI.Box(new Rect(camPos.x - 30, camPos.y, 100, 30), nowSceneName);

        if (GUI.Button(new Rect(camPos.x - 10, camPos.y + 45, 50, 30), btnName))
            SceneManager.LoadScene(nextScene);
    }
}
