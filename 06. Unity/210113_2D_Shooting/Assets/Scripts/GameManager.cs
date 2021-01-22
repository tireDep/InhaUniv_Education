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
    private float fReduceLife = 50.0f;
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

    // List<Dictionary<string, float>> rankScore;
    // Dictionary<string, float> tempData = null;

    public string NextSceneName;

    public class saveData
    {
        public string strName;
        public float fScore;
    }
    public List<saveData> listSaveData = null;
    public List<saveData> SaveLoadData()
    {
        #region test
        //if(tempData == null)
        //{
        //    tempData = new Dictionary<string, float>();
        //
        //    tempData.Add(PlayerPrefs.GetString("ID1", "NONE_1"), PlayerPrefs.GetFloat("Score1", 0));
        //    rankScore.Add(tempData);        tempData = null;
        //
        //    tempData.Add(PlayerPrefs.GetString("ID2", "NONE_2"), PlayerPrefs.GetFloat("Score2", 0));
        //    rankScore.Add(tempData); tempData = null;
        //
        //    tempData.Add(PlayerPrefs.GetString("ID3", "NONE_3"), PlayerPrefs.GetFloat("Score3", 0));
        //    rankScore.Add(tempData); tempData = null;
        //}
        //
        //var enumerator = rankScore.GetEnumerator();
        //
        //while(enumerator.MoveNext())
        //{
        //    var pair = enumerator.Current;
        //
        //    Debug.Log(pair.Key + " : " + pair.Value.ToString());
        //}
        //
        ////while(enumerator.MoveNext())
        ////{
        ////    var pair = enumerator.Current;
        ////
        ////    if(pair.Value < this.fScore)
        ////    {
        ////        tempData[pair.Value] = strID;
        ////        tempData[pair.Key] = fScore;
        ////    }
        ////    Debug.Log(pair.Key + " : " + pair.Value.ToString());
        ////}
        #endregion

        #region LoadData
        if (listSaveData == null)
            listSaveData = new List<saveData>();

        // PlayerPrefs.DeleteAll();

        saveData tempData = new saveData();
        tempData.strName = PlayerPrefs.GetString("ID1", "NONE");
        tempData.fScore = PlayerPrefs.GetFloat("Score1", 0);
        listSaveData.Add(tempData);

        saveData tempData2 = new saveData();
        tempData2.strName = PlayerPrefs.GetString("ID2", "NONE");
        tempData2.fScore = PlayerPrefs.GetFloat("Score2", 0);
        listSaveData.Add(tempData2);

        saveData tempData3 = new saveData();
        tempData3.strName = PlayerPrefs.GetString("ID3", "NONE");
        tempData3.fScore = PlayerPrefs.GetFloat("Score3", 0);
        listSaveData.Add(tempData3);
        #endregion

        var enumerator = listSaveData.GetEnumerator();

        while (enumerator.MoveNext())
        {
            var pair = enumerator.Current;

            if (pair.fScore < this.fScore)
            {
                string strTemp = pair.strName;
                float scoreTemp = pair.fScore;

                pair.strName = strID;
                pair.fScore = this.fScore;

                this.strID = strTemp;
                this.fScore = scoreTemp;

                // break;
            }
        }

        PlayerPrefs.SetString("ID1", listSaveData[0].strName);
        PlayerPrefs.SetFloat("Score1", listSaveData[0].fScore);

        PlayerPrefs.SetString("ID2", listSaveData[1].strName);
        PlayerPrefs.SetFloat("Score2", listSaveData[1].fScore);

        PlayerPrefs.SetString("ID3", listSaveData[2].strName);
        PlayerPrefs.SetFloat("Score3", listSaveData[2].fScore);

        return listSaveData;
    }

}
