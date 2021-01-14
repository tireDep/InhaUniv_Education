using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

using UnityEngine.UI;

public class UI : MonoBehaviour
{
    private Scene scene;

    private bool isChangeMain = false;
    private bool isChangeGame = false;

    public Image ImgHPbar = null;
    public Text TextID = null;
    public InputField InputFieldID = null;

    public Image[] ImageScoreArr;

    private void Start()
    {
        // GameManager.Instance.Reset();
        // GameManager.Instance.SetBGM(0);

        for (int i = 0; i < ImageScoreArr.Length; i++)
            ImageScoreArr[i].enabled = false;

        // if(ImageScoreArr.Length >= 0)
        //     ImageScoreArr[0].enabled = true;
    }

    private void Update()
    {
        scene = SceneManager.GetActiveScene();

        if (scene.name.Contains("Main") && !isChangeMain)
        {
            isChangeMain = true;
            GameManager.Instance.Reset();
            GameManager.Instance.SetBGM(0);
        }
        else if(scene.name.Contains("Game") && !isChangeGame)
        {
            isChangeGame = true;
            GameManager.Instance.SetBGM(1);
            TextID.text = GameManager.Instance.PlayerID;
        }
        else if (scene.name.Contains("End"))
        {
            SetScore(GameManager.Instance.Score);

            isChangeMain = false;
            isChangeGame = false;
        }
    }

    private void onStartBtnPress()
    {
        SceneManager.LoadScene("01. Game");
    }

    private void onInputID()
    {
        GameManager.Instance.PlayerID = InputFieldID.text;
    }

    private void onEndBtnPress()
    {
        SceneManager.LoadScene("00. Main");
    }

    //private void OnGUI()
    //{
    //    scene = SceneManager.GetActiveScene();

    //    //if (scene.name.Contains("Main"))
    //    //{
    //    //    if(isChangeMain == false)
    //    //    {
    //    //        GameManager.Instance.SetBGM(0);
    //    //        isChangeMain = true;
    //    //    }

    //    //    SceneChangeUI("StartScene", "Start", "01. Game");
    //    //    GameManager.Instance.Reset();
    //    //}

    //    //else if (scene.name.Contains("End"))
    //    //{
    //    //    Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);
    //    //    GUI.Box(new Rect(camPos.x - 30, camPos.y - 50, 100, 30), "Score : " + GameManager.Instance.Score);

    //    //    SceneChangeUI("EndScene", "Retry", "00. Main");

    //    //    isChangeGame = false;
    //    //    isChangeMain = false;
    //    //}

    //    //else if (scene.name.Contains("Game"))
    //    //{
    //    //    if (isChangeGame == false)
    //    //    {
    //    //        GameManager.Instance.SetBGM(1);
    //    //        isChangeGame = true;
    //    //    }

    //    //    GUILayout.Label("PlayerLife : " + GameManager.Instance.Life);
    //    //    GUILayout.Label("PlayerScore : " + GameManager.Instance.Score);
    //    //}

    //}

    ////private void SceneChangeUI(string nowSceneName, string btnName, string nextScene)
    ////{
    ////    Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);

    ////    GUI.Box(new Rect(camPos.x - 30, camPos.y, 100, 30), nowSceneName);

    ////    if (GUI.Button(new Rect(camPos.x - 10, camPos.y + 45, 50, 30), btnName))
    ////        SceneManager.LoadScene(nextScene);
    ////}

    public void SetHPbar(float playerLife)
    {
        ImgHPbar.fillAmount = GameManager.Instance.Life * 0.01f;
    }

    public void SetScore(float playerScore)
    {
        // TextScore.text = "Score : " + GameManager.Instance.Score;

        string temp = GameManager.Instance.Score.ToString();

        int i = 0;
        for (i = 0; i < temp.Length; i++)
        {
            SetImageNumber(i, temp[temp.Length - 1 - i].ToString());
            ImageScoreArr[i].enabled = true;
        }

        if(scene.name.Contains("Game"))
        {
            for (; i < ImageScoreArr.Length; i++)
                ImageScoreArr[i].enabled = false;
        }
        else if (scene.name.Contains("End"))
        {
            for (; i < ImageScoreArr.Length; i++)
                ImageScoreArr[i].enabled = true;
        }
    }

    private void SetImageNumber(int index, string strNumber)
    {
        if (strNumber == "0")      ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_0");
        else if (strNumber == "1") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_1");
        else if (strNumber == "2") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_2");
        else if (strNumber == "3") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_3");
        else if (strNumber == "4") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_4");
        else if (strNumber == "5") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_5");
        else if (strNumber == "6") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_6");
        else if (strNumber == "7") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_7");
        else if (strNumber == "8") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_8");
        else if (strNumber == "9") ImageScoreArr[index].sprite = Resources.Load<Sprite>("Image/UI/White_Count_9");
    }

    public void SetID(string strID)
    {
        TextID.text = GameManager.Instance.PlayerID;
    }
}
