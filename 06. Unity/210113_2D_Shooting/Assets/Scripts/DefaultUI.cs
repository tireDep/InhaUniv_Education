using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DefaultUI : MonoBehaviour
{
    public Image imgHPbar;

    void Start()
    {
        ShowHPbar(0.5f);
    }

    void Update()
    {
        
    }

    public void ShowHPbar(float hp)
    {
        imgHPbar.fillAmount = (float)hp;
    }
}
