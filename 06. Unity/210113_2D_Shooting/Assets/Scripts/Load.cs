using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Load : MonoBehaviour
{
    private AsyncOperation asyncOperation;
    public Image progressBar;
    void Start()
    {
        StartCoroutine(LoadingNextScene(GameManager.Instance.NextSceneName));

        progressBar.fillAmount = 0.0f;
    }

    void Update()
    {
        DelayTime();

        progressBar.fillAmount += delayTime;
        // Debug.Log(asyncOperation.progress.ToString());
    }

    private float delayTime = 0.0f;
    private void DelayTime()
    {
        delayTime += Time.deltaTime;
    }

    IEnumerator LoadingNextScene(string sceneName)
    {
        asyncOperation = SceneManager.LoadSceneAsync(sceneName);
        asyncOperation.allowSceneActivation = false;
        // >> 씬 로딩 시 오브젝트가 모두 로드되면 넘어가는데, 그거를 비활성화 함

        // !asyncOperation.isDone()
        // >> 요거 사용해도 되는데 missing이 되는 경우가 있을 수 있음
        // >> 테스트 필요함

        while (asyncOperation.progress < 0.9f)
        {
            // >> 이 시간동안 대기
            // : to do Something

            yield return null;
        }

        while (asyncOperation.progress >= 0.9f)
        {
            yield return new WaitForSeconds(0.1f);

            if (delayTime > 1.0f)
                break;
        }

        asyncOperation.allowSceneActivation = true;
    }
}
