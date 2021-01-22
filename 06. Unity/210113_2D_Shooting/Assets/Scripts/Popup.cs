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
        // >> Ÿ������ ������ ��Ʈ ��� �����ϴ� ��

        if (gameObject.name == "PopupSecond")
            gameObject.SetActive(false);

        // GameObject.Find("Title").GetComponent<Text>();
        titleText = textObj.GetComponent<Text>();
        titleText.text = "�˾� Ÿ��Ʋ";
        //textObj.GetComponent<Text>().text = textObj.GetComponent<Text>().text + "�˾�â";

        toggleTest = toggleObj.GetComponent<Toggle>();
    }

    void Update()
    {
        
    }

    private void onClickOK()
    {
        Debug.Log("ClickOK");
        gameObject.SetActive(false);
        // >> �ش� ������Ʈ ��Ȱ��ȭ
    }

    private void onClickedSecond()
    {
        Debug.Log("ClickSecond");
        gameObject.SetActive(false);
        // >> �ش� ������Ʈ ��Ȱ��ȭ
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
