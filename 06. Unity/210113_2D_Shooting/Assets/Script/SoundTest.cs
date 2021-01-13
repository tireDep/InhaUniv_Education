using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundTest : MonoBehaviour
{
    public AudioClip[] audioClipArr;
    private AudioSource audioSource;

    void Start()
    {
        audioSource = GetComponent<AudioSource>();

        if (this.tag != "Player")
        {
            StopAndPlay(audioClipArr[0]);
            audioSource.loop = true;
        }

    }

    public void setSound(int set)
    {
        StopAndPlay(audioClipArr[set]);
    }
    
    private void StopAndPlay(AudioClip clip)
    {
        if (this.tag == "Player")
            audioSource.loop = false;

        audioSource.Stop();
        audioSource.clip = clip;
        audioSource.Play();
    }
}
