using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    private AudioClip[] audioClipArr = new AudioClip[2];
    private AudioSource audioSource;

    // >> singleton
    private static GameManager sInstance;
    GameObject[] objArr = null;
    float[] timeArr = null;

    private float fScore = 0.0f;

    public float Score
    {
        get
        {
            return fScore;
        }
    }

    private float fLife = 100.0f;
    private float fReduceLife = 10.0f;
    private bool isLive = true;
    public float Life
    {
        get
        {
            return fLife;
        }
    }

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
    private void Awake()
    {
        // audioSource = GetComponent<AudioSource>();
        // >> todo : 질문하기
        audioClipArr[0] = Resources.Load("Sound/title") as AudioClip;
        audioClipArr[1] = Resources.Load("Sound/stage") as AudioClip;
        DontDestroyOnLoad(this.gameObject);
    }
    // << singleton

    public void AddScore()
    {
        fScore += 10.0f;
    }

    public void SetPlayerLive(bool set)
    {
        isLive = set;

        if(isLive == false)
        {
            SceneManager.LoadScene("02. End");
        }
    }

    public void LoseLife()
    {
        fLife -= fReduceLife;

        if (fLife <= 0.0f)
            SetPlayerLive(false);
    }

    public void Reset()
    {
        fLife = 100.0f;
        isLive = true;
    }

    //public void SetBGM(int set)
    //{
    //    StopAndPlay(audioClipArr[set]);
    //}

    //public void StopAndPlay(AudioClip clip)
    //{
    //    audioSource.Stop();
    //    audioSource.clip = clip;
    //    audioSource.Play();
    //}
}
