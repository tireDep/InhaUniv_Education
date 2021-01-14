using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Popup : MonoBehaviour
{
    public GameObject textObj = null;
    public InputField inputField = null;

    Text titleText;

    public GameObject toggleObj = null;
    Toggle toggleTest;

    void Start()
    {
        // >> 타이핑이 나오면 폰트 모두 존재하는 것

        if (gameObject.name == "PopupSecond")
            gameObject.SetActive(false);

        // GameObject.Find("Title").GetComponent<Text>();
        titleText = textObj.GetComponent<Text>();
        titleText.text = "팝업 타이틀";
        //textObj.GetComponent<Text>().text = textObj.GetComponent<Text>().text + "팝업창";

        toggleTest = toggleObj.GetComponent<Toggle>();
    }

    void Update()
    {
        
    }

    private void onClickOK()
    {
        Debug.Log("ClickOK");
        gameObject.SetActive(false);
        // >> 해당 오브젝트 비활성화
    }

    private void onClickedSecond()
    {
        Debug.Log("ClickSecond");
        gameObject.SetActive(false);
        // >> 해당 오브젝트 비활성화
    }

    private void onOpenPopup()
    {
        // GameObject.Find("PopupSecond").SetActive(true);
        // gameObject.SetActive(true);
    }

    private void onTextChanged()
    {
        titleText.text = inputField.text;
    }

    private void onTextEdit()
    {
        titleText.text = inputField.text;
    }

    private void onToggleTest()
    {
        if(toggleTest.isOn)
        {
            Debug.Log("isOn");
        }
        else
        {
            Debug.Log("<color=red>!isOn</color>");
        }
    }
}
