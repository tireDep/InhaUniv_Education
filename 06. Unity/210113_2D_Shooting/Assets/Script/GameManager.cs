using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    private AudioClip[] audioClipArr;
    private AudioSource audioSource;

    private AudioClip[] audioClipSFX;
    private AudioSource audioSFX;

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

    private string strID;
    public string PlayerID
    {
        get
        {
            return strID;
        }

        set
        {
            strID = value;
        }
    }

    private bool isBGMplay = false;
    public bool BGMPlay
    {
        get { return isBGMplay; }
        set { isBGMplay = value; }
    }

    private bool isSFXplay = false;
    public bool SFXPlay
    {
        get { return isSFXplay; }
        set { isSFXplay = value; }
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
        isBGMplay = true;
        isSFXplay = true;

        audioSource = gameObject.AddComponent<AudioSource>();
        audioSource.loop = true;
        // >> 유니티 컴퍼넌트라서 new AudioSource() 이거로는 생성되지 않음에 주의

        audioClipArr = new AudioClip[2];
        audioClipArr[0] = Resources.Load("Sound/title") as AudioClip;
        audioClipArr[1] = Resources.Load("Sound/stage") as AudioClip;

        audioSFX = gameObject.AddComponent<AudioSource>();
        audioSFX.loop = false;

        audioClipSFX = new AudioClip[4];
        audioClipSFX[0] = Resources.Load("Sound/attack") as AudioClip;
        audioClipSFX[1] = Resources.Load("Sound/get") as AudioClip;
        audioClipSFX[2] = Resources.Load("Sound/damaged") as AudioClip;
        audioClipSFX[3] = Resources.Load("Sound/start") as AudioClip;
        

        DontDestroyOnLoad(this.gameObject);
    }
    // << singleton

    public void AddScore()
    {
        fScore += 10.0f;
        GameObject.Find("Canvas").GetComponent<UI>().SetScore(fScore);
    }

    public void SetPlayerLive(bool set)
    {
        isLive = set;

        if(isLive == false)
        {
            audioSource.Stop();
            SceneManager.LoadScene("02. End");
        }
    }

    public void LoseLife()
    {
        fLife -= fReduceLife;

        GameObject.Find("Canvas").GetComponent<UI>().SetHPbar(fLife);

        if (fLife <= 0.0f)
            SetPlayerLive(false);
    }

    public void Reset()
    {
        fLife = 100.0f;
        isLive = true;
    }

    public void SetBGM(int set)
    {
        if (!isBGMplay)
            return;

        StopAndPlay(audioClipArr[set]);
    }

    public void StopAndPlay(AudioClip clip)
    {
        audioSFX.loop = true;
        audioSource.Stop();
        audioSource.clip = clip;
        audioSource.Play();
    }

    public void SetSFX(int set)
    {
        if (!isSFXplay)
            return;

        StopAndPlaySFX(audioClipSFX[set]);
    }

    private void StopAndPlaySFX(AudioClip clip)
    {
        audioSFX.loop = false;
        audioSFX.Stop();
        audioSFX.clip = clip;
        audioSFX.Play();
    }

    private bool isPause = false;
    public bool Pause
    {
        get
        {
            return isPause;
        }
        set
        {
            isPause = value;

            if (value)
            {
                Time.timeScale = 0;
                audioSource.Pause();
                audioSFX.Pause();
            }
            else
            {
                Time.timeScale = 1;
                if(isBGMplay)
                    audioSource.Play();

                if(isSFXplay)
                    audioSFX.Stop();
            }
            GameObject.Find("Canvas").GetComponent<UI>().SetActivePausePopup(value);

        }
    }
}
