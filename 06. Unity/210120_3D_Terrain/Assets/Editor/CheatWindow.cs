using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;

public class CheatWindow : EditorWindow
{
    //  >> 보통 파일에서 읽어옴
    string[] cheatList = new string[] { "치트", "골드 생성", "포인트 생성" };

    static int selectIndex = 0;
    int getInt = 0;
    string getString = "";

    [MenuItem("Menu/CheatCmd", false, 0)]
    // >> false / true 는 모양 및 배치에 해당됨

    static public void OpenCheatWindow1()
    {
        CheatWindow getWindow = EditorWindow.GetWindow<CheatWindow>(false, "CheatWindow", true);
    }

    private void OnGUI()
    {
        GUILayout.Space(10.0f);

        int getIndex = EditorGUILayout.Popup(selectIndex, cheatList, GUILayout.MaxWidth(200));

        if(selectIndex != getIndex)
        {
            selectIndex = getIndex;
        }

        GUILayout.BeginHorizontal(GUILayout.MaxWidth(300.0f));

        string cheatText = "";
        // >> 서버 전송 혹은 게임 내에서 입력된 치트 

        if(selectIndex == 0)
        {
            GUILayout.Label("치트키 입력", GUILayout.Width(70.0f));
            getString = EditorGUILayout.TextField(getString, GUILayout.Width(100.0f));
            cheatText = string.Format("치트키 : {0}", getString);
        }
        else if (selectIndex == 1)
        {
            GUILayout.Label("골드", GUILayout.Width(70.0f));
            getString = EditorGUILayout.TextField(getString, GUILayout.Width(100.0f));
            int.TryParse(getString, out getInt);
            cheatText = string.Format("골드 : {0}", getInt);
        }
        else if (selectIndex == 2)
        {
            GUILayout.Label("포인트", GUILayout.Width(70.0f));
            getString = EditorGUILayout.TextField(getString, GUILayout.Width(100.0f));
            int.TryParse(getString, out getInt);
            cheatText = string.Format("포인트 : {0}", getInt);
        }

        GUILayout.EndHorizontal();

        GUILayout.Space(20.0f);
        GUILayout.BeginHorizontal(GUILayout.MaxWidth(800.0f));
        {
            GUILayout.BeginVertical(GUILayout.MaxWidth(300.0f));
            {
                GUILayout.BeginHorizontal(GUILayout.MaxWidth(300.0f));
                {
                    if(GUILayout.Button("\n적용\n", GUILayout.Width(100.0f)))
                    {
                        if(EditorApplication.isPlaying 
                          && EditorSceneManager.GetActiveScene().name == "Terrain")
                         // && EditorApplication.currentScene == "Terrain")
                        {
                            getInt = 0;
                            getString = "";
                            Debug.Log(cheatText);
                        }
                    }
                }
                GUILayout.EndHorizontal();

                GUILayout.BeginHorizontal(GUILayout.MaxWidth(300.0f));
                {
                    if(GUILayout.Button("\n백그라운드\n실행\n", GUILayout.Width(100.0f)))
                    {
                        Application.runInBackground = true;
                    }

                    if (GUILayout.Button("\n백그라운드\n실행안함\n", GUILayout.Width(100.0f)))
                    {
                        Application.runInBackground = false;
                    }

                    // >> auto 테스트 할 때 필요함
                    // >> test 용
                }
                GUILayout.EndHorizontal();
            }
            GUILayout.EndVertical();
        }
        GUILayout.EndHorizontal();
    }
}
