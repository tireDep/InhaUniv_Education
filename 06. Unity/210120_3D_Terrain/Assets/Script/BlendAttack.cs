using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlendAttack : MonoBehaviour, IAction
{
    [SerializeField, Range(1.0f, 3.0f)]
    private float range = 2.0f;
    private BlendMove move = null;
    private ActionManager actionManager = null;
    private Transform _target = null;

    private Animator animator = null;

    private void Awake()
    {
        move = GetComponent<BlendMove>();
        actionManager = GetComponent<ActionManager>();

        animator = GetComponentInChildren<Animator>();
    }

    private Damage damage = null;
    void Update()
    {
        // if (animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        //    Debug.Log("fdashkjfdskjsdhkjsdfakhj");

        //int layerCnt = 0;
        //var clipInfo = animator.GetCurrentAnimatorClipInfo(layerCnt);
        //for(int i=0;i<clipInfo.Length;i++)
        //{
        //    print(i + " : " +clipInfo[i].clip.name);
        //}

        if (_target == null)
            return;

        if(IsInRange() == true && animator.GetCurrentAnimatorStateInfo(0).nameHash != Animator.StringToHash("Base Layer.Attack"))
        {
           // if (animator.GetCurrentAnimatorStateInfo(0).normalizedTime > 1.0f)
           // if(clipInfo[0].clip.name != "Attack")
            {
                animator.SetTrigger("Attack");
            }
            move.End();
            print("Attack");

            damage = _target.GetComponent<Damage>();

            End();
        }
        else
        {
            print("None");
            move.MoveTo(_target.position);
        }

    }

    public void Begin(object obj)
    {
        Damage target = obj as Damage;

        if (target == null)
            return;

        // Debug.Assert(target != null, obj.ToString() + "Damage type Need");
        // >> asset 조건이 false여야 실행됨에 주의

        actionManager.StartAction(this);
        _target = target.transform;
    }

    public void End()
    {
        _target = null;
    }

    private bool IsInRange()
    {
        Vector2 other = new Vector2(_target.position.x, _target.position.z);
        // >> 높이는 비교 x

        Vector2 my = new Vector2(transform.position.x, transform.position.z);

        return Vector2.Distance(other, my) < range;
    }

    public void Hit()
    {
        if (damage != null)
        {
            damage.Damaged();
            damage = null;
            Debug.Log("Hit");
        }         
    }

}
