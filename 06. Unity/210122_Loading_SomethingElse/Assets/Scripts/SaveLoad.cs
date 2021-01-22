using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SaveLoad : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // >> 간단한 데이터 저장
        // >> int, float, string 저장 가능
        // >> 너무 큰 데이터는 저장하지 말 것 => 1MB 넘기면 에러남
        // >> 출석체크 이벤트 등을 체크할 때 처음에 로컬에 저장해 두면,
        //    다시 접속해도 이미 출석이 완료됨을 확인할 수 있어서 네트워크 패킷을 보내지 않아도 됨

        if (Input.GetKeyDown(KeyCode.A))
        {
            if(PlayerPrefs.HasKey("ID"))
            {
                string getID = PlayerPrefs.GetString("ID");
                Debug.Log(string.Format("ID : {0}", getID));
            }
            else
            {
                Debug.Log("ID 없음");
            }
        }

        if (Input.GetKeyDown(KeyCode.B))
        {
            string setID = "PlayerID";
            PlayerPrefs.SetString("ID", setID);
            Debug.Log("Saved!");
        }

        if (Input.GetKeyDown(KeyCode.C))
        {
            PlayerPrefs.SetInt("INT", 33);
            PlayerPrefs.SetFloat("FLOAT", 33.3f);

            int getInt = PlayerPrefs.GetInt("INT");
            float getFloat = PlayerPrefs.GetFloat("FLOAT");

            Debug.Log(getInt.ToString());
            Debug.Log(getFloat.ToString());
        }

        if(Input.GetKeyDown(KeyCode.D))
        {
            // >> savedata를 가져올 때 존재하지 않을 경우, 디폴트 값으로 가져옴

            int getInt = PlayerPrefs.GetInt("INT2", 0);
            float getFloat = PlayerPrefs.GetFloat("FLOAT2", 1.0f);
            string getString = PlayerPrefs.GetString("ID2", "None");

            Debug.Log(getInt.ToString());
            Debug.Log(getFloat.ToString());
            Debug.Log(getString);
        }

        if(Input.GetKeyDown(KeyCode.F))
        {
            // >> 로컬에 쌓인 값 삭제

            PlayerPrefs.DeleteKey("ID");
            PlayerPrefs.DeleteKey("INT");
            PlayerPrefs.DeleteKey("FLOAT");
            // >> 필드, 데이터 포함
            // >> 개별적인 데이터 삭제

            PlayerPrefs.DeleteAll();
            // >> 이전 데이터 삭제

        }

        if (Input.GetKeyDown(KeyCode.F))
        {
            PlayerPrefs.Save();
            // >> PlayerPrefs가 제대로 작동하지 않을 경우 사용
        }
    }
}
