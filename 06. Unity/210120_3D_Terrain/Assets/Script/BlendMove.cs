using UnityEngine;
using UnityEngine.AI;

public class BlendMove : MonoBehaviour, IAction
{
    private NavMeshAgent navMeshAgent = null;
    private Animator animator = null;

    private ActionManager actionManager = null;

    private float fSpeed = 10.0f;

    void Start()
    {
        navMeshAgent = GetComponent<NavMeshAgent>();
        animator = GetComponentInChildren<Animator>();
        actionManager = GetComponent<ActionManager>();
    }

    private void FixedUpdate()
    {
        Vector3 velocity = navMeshAgent.velocity;
        Vector3 local = transform.InverseTransformDirection(velocity);
        // >> 전방이동시 속도 계산

        fSpeed = local.z / navMeshAgent.speed;

        if (fSpeed < 0)
            fSpeed *= -1;

        animator.SetFloat("Speed", fSpeed);
    }

    public void Begin(object obj)
    {
        if(obj is Vector3)
        {
            // >> boxing -> unboxing

            actionManager.StartAction(this);
            Vector3 dest = (Vector3)obj;
            MoveTo(dest);
        }
    }

    public void End()
    {
        navMeshAgent.isStopped = true;
    }

    public void MoveTo(Vector3 dest)
    {
        navMeshAgent.isStopped = false;
        navMeshAgent.destination = dest;
    }

}
