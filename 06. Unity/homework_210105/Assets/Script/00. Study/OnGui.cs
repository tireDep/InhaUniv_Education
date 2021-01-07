using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;
// >> 씬 전환

public class OnGui : MonoBehaviour
{
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    private void OnGUI()
    {
        // >> OnGUI
        //// >> 단, OnGUI는 테스트용으로만 사용할 것
        //// >> 최적화 문제 등

        //GUI.TextArea(new Rect(200, 50, 100, 30), "TextArea");
        //GUI.TextField(new Rect(200, 100, 100, 30), "TextField");
        //// >> Editing 가능

        //GUI.Box(new Rect(200, 150, 100, 30),"Box");
        //// >> Editing 불가능

        //GUILayout.Label("Layout Label");

        //if(GUI.Button(new Rect(10,240,50,30), "Button"))
        //{
        //    Debug.Log("PressedBtn");
        //}
        // << OnGUI

        GUI.Box(new Rect(10, 200, 100, 30), "changeScene");
        if (GUI.Button(new Rect(10, 240, 50, 30), "Button"))
        {
            Debug.Log("PressedBtn");
            ChangeScene();
        }
    }

    void ChangeScene()
    {
        SceneManager.LoadScene("01. RayCasting");
    }
}
