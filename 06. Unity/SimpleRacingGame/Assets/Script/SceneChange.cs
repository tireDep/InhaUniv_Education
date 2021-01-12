using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class SceneChange : MonoBehaviour
{
    private Scene scene;
    public GameObject[] objArr;
    private bool isGameChange = false;

    private void OnGUI()
    {
        scene = SceneManager.GetActiveScene();

        if (scene.name.Contains("Start"))
        {
            isGameChange = false;
            SceneChangeUI("GameStart", "Start", "01. RacingGame");
        }

        else if (scene.name.Contains("End"))
        {
            SceneChangeUI("EndGame", "Retry", "00. Start");

            // float[] timeArr = GameManager.Instance.GetLabTime();
            // string[] nameArr = GameManager.Instance.GetObjName();
            // for(int i=0;i<timeArr.Length;i++)
            // {
            //     // GUILayout.Label(i + 1 + " : " + timeArr[i]);
            //     GUILayout.Label(i + 1 + " : " + nameArr[i] + " / " + timeArr[i]);
            // }

            Hashtable rank = GameManager.Instance.GetHashRank();

            for (int i = 0; i < rank.Count; i++)
                GUILayout.Label((i + 1)+ " : " + rank[i].ToString());
        }

        else if (scene.name.Contains("RacingGame"))
        {
            if(!isGameChange)
            {
                GameManager.Instance.ResetLabTime();
                isGameChange = true;
            }

            if (CheckChangeScene())
                SceneManager.LoadScene("02. End");
            else
            {
                string[] nameArr = GameManager.Instance.GetObjName();
                Hashtable remainLap = GameManager.Instance.GetHashRemainTrack();

                for(int i=0;i<remainLap.Count;i++)
                {
                    GUILayout.Label(nameArr[i] + " : " + remainLap[nameArr[i]].ToString());
                }
            }
        }
    }

    private bool CheckChangeScene()
    {
        int checkCnt = 0;
        for(int i=0;i<objArr.Length;i++)
        {
            if(objArr[i].tag == "Vehicle")
            {
                if (objArr[i].name != "Player" && objArr[i].GetComponent<AutoMove>().fSpeed <= 0.0f)
                    checkCnt++;
                
                if(objArr[i].name == "Player" && objArr[i].GetComponent<PlayerMove>().fSpeed <= 0.0f)
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

        GUI.Box(new Rect(camPos.x - 20, camPos.y, 100, 30), nowSceneName);

        if (GUI.Button(new Rect(camPos.x, camPos.y + 45, 50, 30), btnName))
            SceneManager.LoadScene(nextScene);
    }
}
