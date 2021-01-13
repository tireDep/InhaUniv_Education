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
    }

    void Update()
    {
        SoundTest_1();
    }

    private void SoundTest_1()
    {
        if (Input.GetKeyDown(KeyCode.Keypad1))
            StopAndPlay(audioClipArr[0]);
        else if (Input.GetKeyDown(KeyCode.Keypad2))
            StopAndPlay(audioClipArr[1]);
        else if (Input.GetKeyDown(KeyCode.Keypad3))
        {
            audioSource.loop = false;
            StopAndPlay(audioClipArr[2]);
        }
    }
    
    private void StopAndPlay(AudioClip clip)
    {
        audioSource.Stop();
        audioSource.clip = clip;
        audioSource.Play();
    }
}
