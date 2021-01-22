using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEditor;
using UnityEditor.SceneManagement;

public class EditorTest : MonoBehaviour
{
    // >> 툴 제작 등에 사용해 볼 수 있음

    // >> Componet 옆에 추가됨을 확인할 수 있음
    [MenuItem("Menu/Clear PlayerPrefs")]
    private static void Clear_PlayerPrefs()
    {
        Debug.Log("Clear PlayerPrefs");
    }

    [MenuItem("Menu/SubMenu/Select")]
    private static void SubMenu_Selected()
    {
        Debug.Log("selected!");
    }

    // >> 단축키
    // # : Ctrl
    // % : Shift
    // & : Alt
    [MenuItem("Menu/SubMenu/Hotkey Test 1 %#v")]
    private static void SubMenu_Hotkey_1()
    {
        Debug.Log("Hotkey test : Ctrl + shift + V");
    }

    [MenuItem("Menu/SubMenu/Hotkey Test 1 &g")]
    private static void SubMenu_Hotkey_2()
    {
        Debug.Log("Hotkey test : Arlt + G");
    }


    [MenuItem("Assets/Load Selected Scene %5")]
    private static void LoadSelectedScene()
    {
        var selected = Selection.activeObject;

        if (EditorApplication.isPlaying)
            EditorSceneManager.LoadScene(AssetDatabase.GetAssetPath(selected));
        else
            EditorSceneManager.OpenScene(AssetDatabase.GetAssetPath(selected));
            // >> 플레이 상태에서는 동작하지 않음
    }
}


