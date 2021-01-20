using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    //public Transform target;

    //private Transform tr;                // 카메라 자신의 Transform

    //void Start()
    //{
    //    tr = GetComponent<Transform>();
    //}

    //void LateUpdate()
    //{
    //    tr.position = new Vector3(target.position.x - 0.52f, tr.position.y, target.position.z - 6.56f);

    //    tr.LookAt(target);
    //}

    public GameObject target;

    public float offsetX;
    public float offsetY;
    public float offsetZ;

    public float DelayTime;

    void Update()
    {
        Ray ray = new Ray();
        ray.origin = this.transform.position;
        ray.direction = (GameObject.FindGameObjectWithTag("Player").transform.position - this.transform.position).normalized;

        float fDist = 10.0f;
        RaycastHit[] rayHitsArr;
        rayHitsArr = Physics.RaycastAll(ray);

        GameObject[] mapWallArr = GameObject.FindGameObjectsWithTag("Maze");
        for (int i = 0; i < mapWallArr.Length; i++)
        {
            Color color = mapWallArr[i].GetComponent<Renderer>().material.color;
            color.a = 1.0f;

            mapWallArr[i].GetComponent<Renderer>().material.shader = Shader.Find("Standard");
            mapWallArr[i].GetComponent<Renderer>().material.color = color;
        }

        for (int i=0;i<rayHitsArr.Length;i++)
        {
            if(rayHitsArr[i].collider.CompareTag("Maze"))
            {
                Color color = rayHitsArr[i].collider.GetComponent<Renderer>().material.color;
                color.a = 0.5f;

                rayHitsArr[i].collider.GetComponent<Renderer>().material.shader = Shader.Find("Transparent/Diffuse");
                rayHitsArr[i].collider.GetComponent<Renderer>().material.color = color;
            }
        }

        Vector3 FixedPos =
            new Vector3(
            target.transform.position.x + offsetX,
            target.transform.position.y + offsetY,
            target.transform.position.z + offsetZ);
        transform.position = Vector3.Lerp(transform.position, FixedPos, Time.deltaTime * DelayTime);
    }
}
