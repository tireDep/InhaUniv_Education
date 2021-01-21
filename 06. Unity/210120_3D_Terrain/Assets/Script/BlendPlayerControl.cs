using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;


public class BlendPlayerControl : MonoBehaviour
{
    #region IAction
    //private void MoveTo(Vector3 dest)
    //{
    //    navMeshAgent.isStopped = false;
    //    navMeshAgent.destination = dest;
    //
    //}
    //
    //public void Begin(object obj)
    //{
    //
    //}
    //
    //public void End()
    //{
    //    navMeshAgent.isStopped = true;
    //}
    #endregion

    #region preMove
    // Player
    // public float fSpeed = 0.0f;
    // private Vector3 target;
    // private NavMeshAgent navMeshAgent = null;
    // private Animator animator = null;
    #endregion

    private BlendMove move = null;
    private BlendAttack attack = null;

    void Start()
    {
        #region preMove
        // navMeshAgent = GetComponent<NavMeshAgent>();
        // animator = GetComponentInChildren<Animator>();
        #endregion

        move = this.GetComponent<BlendMove>();
        attack = this.GetComponent<BlendAttack>();
    }

    private void FixedUpdate()
    {
        #region preMove
        //SetDestination();
        //
        //Vector3 velocity = navMeshAgent.velocity;
        //Vector3 local = transform.InverseTransformDirection(velocity);
        //// >> 전방이동시 속도 계산
        //
        //fSpeed = local.z / navMeshAgent.speed;
        //
        //if (fSpeed < 0)
        //    fSpeed *= -1;
        //
        //animator.SetFloat("Speed", fSpeed);
        #endregion

        if (Attacking() == true)
            return;

        if (Moving() == true)
            return;
    }

    private bool Moving()
    {
        if (Input.GetMouseButton(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit))
            {
                move.Begin(hit.point);
                return true;
            }
        }

        return false;
    }

    #region preMove
    // private void OnGUI()
    // {
    //     GUI.Box(new Rect(0, 0, 100, 100), fSpeed.ToString());
    // }
    // 
    // private void SetDestination()
    // {
    //     if (Input.GetMouseButton(0))
    //     {
    //         Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
    //         RaycastHit hit;
    // 
    //         if (Physics.Raycast(ray, out hit))
    //         {
    //             target = hit.point;
    //             navMeshAgent.destination = hit.point;
    //         }
    //     }
    // }
    #endregion

    private bool Attacking()
    {
        RaycastHit[] hitArr = Physics.RaycastAll(GetMouseRay());

        foreach(RaycastHit hit in hitArr)
        {
            Damage damage = hit.transform.GetComponent<Damage>();

            if (damage == null)
                continue;

            if(Input.GetMouseButtonDown(1))
            {
                // Debug.Log("attack");
                attack.Begin(damage);
            }
            return true;
        }

        return false;
    }

    private Ray GetMouseRay()
    {
        return Camera.main.ScreenPointToRay(Input.mousePosition);
    }

}
