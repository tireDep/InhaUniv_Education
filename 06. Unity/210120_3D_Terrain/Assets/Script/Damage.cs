using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Damage : MonoBehaviour
{
    private List<Material> materials = new List<Material>();

    private void Awake()
    {
        Renderer[] renderers = GetComponentsInChildren<Renderer>();
        
        foreach(Renderer obj in renderers)
        {
            materials.AddRange(obj.materials);
            // >> 배열의 마지막에 추가
        }
    }

    public void Damaged()
    {
        Debug.Log("-----DamedObject-----");

        foreach(Material mat in materials)
        {
            mat.color = new Color(1, 0, 0, 0);
        }

        Invoke("SetNormalMaterial", 0.5f);
    }

    private void SetNormalMaterial()
    {
        foreach (Material mat in materials)
        {
            mat.color = new Color(1, 1, 1, 1);
        }
    }
}
