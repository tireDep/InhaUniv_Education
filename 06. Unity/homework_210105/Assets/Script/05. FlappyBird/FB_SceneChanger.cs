using UnityEngine;
using UnityEngine.SceneManagement;

public class FB_SceneChanger : MonoBehaviour
{
    private Scene scene;
    private void OnGUI()
    {
        scene = SceneManager.GetActiveScene();

        if (scene.name.Contains("Main"))
        {
            FB_GameManager.Instance.fScore = 0.0f;
            SceneChangeUI("FlappyBird", "Start", "01. Game");
        }

        else if (scene.name.Contains("End"))
        {
            float score = FB_GameManager.Instance.fScore;
            SceneChangeUI("Score : " + score.ToString(), "Retry", "00. Main");
        }

        else if (scene.name.Contains("Game"))
        {
            float score = FB_GameManager.Instance.fScore;
            GUILayout.Label("Score : " + score);
        }
    }

    private void SceneChangeUI(string nowSceneName, string btnName, string nextScene)
    {
        Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);

        GUI.Box(new Rect(camPos.x - 20, camPos.y, 100, 30), nowSceneName);

        if (GUI.Button(new Rect(camPos.x, camPos.y + 45, 50, 30), btnName))
            SceneManager.LoadScene(nextScene);
    }
}
