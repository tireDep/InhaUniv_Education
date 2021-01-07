using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class SceneChange : MonoBehaviour
{
    private Scene scene;
    public GameObject[] objArr;

    private void OnGUI()
    {
        scene = SceneManager.GetActiveScene();

        if (scene.name.Contains("Start"))
            SceneChangeUI("StartScene", "Start", "00. RacingGame");

        else if (scene.name.Contains("End"))
            SceneChangeUI("EndScene", "Retry", "02_1. Start");

        else if (scene.name.Contains("RacingGame"))
        {
            if (CheckChangeScene())
                SceneManager.LoadScene("02_2. End");
        }
    }

    private bool CheckChangeScene()
    {
        int checkCnt = 0;
        for(int i=0;i<objArr.Length;i++)
        {
            if(objArr[i].tag == "Vehicle")
            {
                if (objArr[i].GetComponent<AutoMove>().isFinish)
                    checkCnt++;
            }
        }

        if (checkCnt == objArr.Length)
            return true;
        else
            return false;
    }
    
    private void SceneChangeUI(string nowSceneName, string btnName, string nextScene)
    {
        Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);

        GUI.Box(new Rect(camPos.x, camPos.y, 100, 30), nowSceneName);

        if (GUI.Button(new Rect(camPos.x + 20, camPos.y + 45, 50, 30), btnName))
            SceneManager.LoadScene(nextScene);
    }
}
