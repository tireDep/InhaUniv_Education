using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundSys : MonoBehaviour
{
    private static SoundSys instances;
    public static SoundSys Instance
    {
        get
        {
            if (instances == null)
            {
                GameObject newGameObject = new GameObject("SoundSys");
                instances = newGameObject.AddComponent<SoundSys>();
            }
            return instances;
        }
    }

    
    private AudioClip[] audioClipArr;
    private AudioSource audioSource;

    private void Awake()
    {
        audioSource = gameObject.AddComponent<AudioSource>();

        audioClipArr = new AudioClip[2];
        audioClipArr[0] = Resources.Load("Sound/phaserUp6") as AudioClip;
        audioClipArr[1] = Resources.Load("Sound/phaserUp5") as AudioClip;

        DontDestroyOnLoad(this);
    }

    public void StopAndPlay(int sound)
    {
        audioSource.loop = false;
        audioSource.Stop();

        if (0 == sound)
            audioSource.clip = audioClipArr[0];
        else if (1 == sound)
            audioSource.clip = audioClipArr[1];

        audioSource.Play();
    }
}
