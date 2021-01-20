using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class NavEnemy : MonoBehaviour
{
    NavMeshAgent agent;

    Animator animator;

    [SerializeField]
    private float fSpeed = 20.0f;

    private int itemCnt = 0;
    public int ItemCount
    {
        get { return itemCnt; }
        set { itemCnt += value; }
    }

    void Start()
    {
        agent = GetComponent<NavMeshAgent>();
        agent.speed = fSpeed;

        animator = GetComponent<Animator>();
    }

    void Update()
    {
        GameObject[] tempPosArr = GameObject.FindGameObjectsWithTag("Gem");
        Vector3 tempPos = new Vector3(9999, 9999, 9999);

        for(int i=0;i<tempPosArr.Length;i++)
        {
            Vector3 offset_1 = tempPosArr[i].transform.position - this.transform.position;
            float sqrLen_1 = offset_1.sqrMagnitude;

            Vector3 offset_2 = tempPos - this.transform.position;
            float sqrLen_2 = offset_2.sqrMagnitude;

            if(sqrLen_1 < sqrLen_2)
            {
                // agent.destination = tempPos;
                tempPos = tempPosArr[i].transform.position;
            }
        }

        if (tempPos.x == 9999)
        {
            agent.destination = this.transform.position;
            setZero();
        }
        else
        {
            fSpeed = 10.0f;
            agent.speed = 10.0f;
            agent.updatePosition = true;
            agent.updateRotation = true;
            agent.isStopped = false;
            agent.destination = new Vector3(tempPos.x, 0, tempPos.z);
        }

        animator.SetFloat("Speed", agent.velocity.magnitude);
    }

    public void setZero()
    {
        agent.speed = 0.0f;
        agent.updatePosition = false;
        agent.updateRotation = false;
        agent.velocity = Vector3.zero;
        agent.isStopped = true;
        agent.destination = agent.transform.position;
        agent.ResetPath();
        // agent.acceleration = float.MaxValue;
    }
}
