using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow : MonoBehaviour
{
    void Update()
    {
        GameObject[] tempPosArr = GameObject.FindGameObjectsWithTag("Gem");
        Vector3 tempPos = new Vector3(9999, 9999, 9999);

        for (int i = 0; i < tempPosArr.Length; i++)
        {
            Vector3 offset_1 = tempPosArr[i].transform.position - this.transform.position;
            float sqrLen_1 = offset_1.sqrMagnitude;

            Vector3 offset_2 = tempPos - this.transform.position;
            float sqrLen_2 = offset_2.sqrMagnitude;

            if (sqrLen_1 < sqrLen_2)
                tempPos = tempPosArr[i].transform.position;
        }

        if (tempPos.x != 9999)
        {
            this.GetComponent<Renderer>().material.color = new Color(255, 255, 255, 255);
            // this.transform.LookAt(tempPos);

            // Vector3 angle = tempPos - this.transform.position;
            // this.transform.LookAt(Mathf.Atan2(angle.x, angle.y, angle.z) * Mathf.Rad2Deg);

            // float dot = Vector3.Dot(tempPos, this.transform.position);
            // float angle = Mathf.Acos(dot);

            //Vector3 v = tempPos - this.transform.position;
            //float angle = Mathf.Atan2(v.y, v.x);

            //this.transform.rotation = Quaternion.Euler(-90, 0, angle);

            Vector3 newRot = Quaternion.LookRotation(tempPos - this.transform.position).eulerAngles;

            newRot.x = -90;
            // newRot.y = -180;
            // newRot.y = 0;
            newRot.z += 180;
            transform.rotation = Quaternion.Euler(newRot);
        }
        else
        {
            transform.rotation = Quaternion.Euler(90, 0, 0);
            this.GetComponent<Renderer>().material.color = new Color(255, 0, 0, 255);
        }
    }
}
