using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MecanimControl : MonoBehaviour
{
    private float fSpeed = 10.0f;
    private float fRotSpeed = 360.0f;

    CharacterController pcController;
    Animator animator;

    void Start()
    {
        pcController = GetComponent<CharacterController>();
        animator = GetComponent<Animator>();
    }

    private bool isAttack = false;
    void Update()
    {
        // if(pcController.velocity.magnitude)

        // animator.SetFloat("Speed", pcController.velocity.magnitude);
        // 
        // if(Input.GetKeyDown(KeyCode.Space))
        // {
        //     animator.SetTrigger("Attack");
        //     isAttack = true;
        // }
        // 
        // StartCoroutine("CheckAttack");

        Input_Animation();
        // Input_Animation2();

        CharacterController_Slerp();        
    }

    private void CheckAttack()
    {
        if (isAttack && animator.GetCurrentAnimatorStateInfo(0).normalizedTime >= 1.0f)
        {
            isAttack = false;
            animator.ResetTrigger("Attack");
            // animator.Rebind();
            // animator.Play("Wait");
        }
    }

    void CharacterController_Slerp()
    {
        Vector3 direction = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));

        if (direction.sqrMagnitude > 0.01f)
        {
            Vector3 forward = Vector3.Slerp(transform.forward,
                                            direction,
                                            fRotSpeed * Time.deltaTime / Vector3.Angle(transform.forward, direction));
            // >> 바라보는 방향, 이동 방향 간 보간

            transform.LookAt(transform.position + forward);
        }
        else
        {

        }
        pcController.Move(direction * fSpeed * Time.deltaTime + Physics.gravity);

    }

    private void Input_Animation()
    {
        // animator.SetFloat("Speed", pcController.velocity.magnitude);

        if(Input.GetMouseButtonDown(0))
        {
            animator.SetTrigger("HandUp");       
        }
    }

    private bool bHandUp = false;
    private void Input_Animation2()
    {
        animator.SetFloat("Speed", pcController.velocity.magnitude);

        if (Input.GetMouseButtonDown(0) && !bHandUp)
        {
            bHandUp = true;
            animator.SetBool("HandUp", bHandUp);
            StartCoroutine("HandUp_Routine");
        }
    }

    IEnumerator HandUp_Routine()
    {
        while(true)
        {
            yield return new WaitForSeconds(0.0f);
            if (bHandUp && animator.GetCurrentAnimatorStateInfo(1).IsName("UpperBody.Attack"))
            {
                if(animator.GetCurrentAnimatorStateInfo(1).normalizedTime >= 1.0f)
                {
                    // >> 애니메이션 끝난 상태
                    bHandUp = false;
                    animator.SetBool("HandUp", bHandUp);
                    break;
                }
            }
        }
    }
}
