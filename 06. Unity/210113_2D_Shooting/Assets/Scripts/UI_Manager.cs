using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UI_Manager : MonoBehaviour
{
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    public GameObject popup;
    public void onOpenPopup()
    {
        Debug.Log("pressed");
        popup.SetActive(true);
        // GameObject.Find("PopupSecond").SetActive(true);
        // gameObject.SetActive(true);
    }
}
