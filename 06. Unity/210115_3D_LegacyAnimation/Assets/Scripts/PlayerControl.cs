using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    Animation spartanKing;

    public AnimationClip DIE;

    CharacterController playerController;
    public float RunSpeed = 10.0f;
    Vector3 velocity;

    public GameObject objSword = null;

    void Start()
    {
        spartanKing = gameObject.GetComponentInChildren<Animation>();
        spartanKing.wrapMode = WrapMode.Loop;
        // >> �ִϸ��̼� �÷��� ����(�ݺ� ��)

        playerController = gameObject.GetComponent<CharacterController>();

        objSword.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        // Animation_Play_1();
        // >> �ִϸ��̼�

        // CharacterControll();
        // >> ĳ���� ��Ʈ�ѷ�

        CharacterControll_Slerp();
        // >> �ε巯�� ĳ���� ��Ʈ�ѷ�
    }

    private void Animation_Play_1()
    {
        if (Input.GetKey(KeyCode.F))
        {
            // spartanKing.Play("attack");
            // >> �ִϸ��̼� Ŭ�� �̸�
            // >> �⺻ ���

            //spartanKing.wrapMode = WrapMode.Once;
            // >> �ִϸ��̼� �÷��� ����(�ݺ� ��)

            //spartanKing.CrossFade("attack", 0.3f);
            // >> �ִϸ��̼� ����
            // >> �ִϸ��̼��� ���̸� Ȯ���ؼ� �������ָ� ��

            // >> �ִϸ��̼��� ���̿� ���缭 �ڷ�ƾ���� �ۼ��ص� ��
            StartCoroutine("AttackToIdle");
        }

        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            spartanKing.CrossFade("walk", 0.3f);
            spartanKing.wrapMode = WrapMode.Loop;
        }
        // else if (Input.GetKeyDown(KeyCode.Alpha2))  { spartanKing.Play("run"); }
        // else if (Input.GetKeyDown(KeyCode.Alpha3)) { spartanKing.Play("charge"); }
        // else if (Input.GetKeyDown(KeyCode.Alpha4)) { spartanKing.Play("idlebattle"); }
        // else if (Input.GetKeyDown(KeyCode.Alpha5)) { spartanKing.Play("resist"); }
        // else if (Input.GetKeyDown(KeyCode.Alpha6)) { spartanKing.Play("victory"); }
        // else if (Input.GetKeyDown(KeyCode.Alpha7)) { spartanKing.Play("salute"); }
        else if (Input.GetKeyDown(KeyCode.Alpha8))
        {
            spartanKing.CrossFade(DIE.name, 0.3f);
            spartanKing.wrapMode = WrapMode.Once;
        }
        // else if (Input.GetKeyDown(KeyCode.Alpha9)) { spartanKing.Play("diehard"); }
        else if (Input.GetKeyDown(KeyCode.Alpha0))
        {
            spartanKing.CrossFade("idle", 0.3f);
            spartanKing.wrapMode = WrapMode.Loop;
        }

    }

    private bool isFin = false;
    IEnumerator AttackToIdle()
    {
        if (spartanKing.IsPlaying("attack") != true)
        {
            isFin = true;
            objSword.SetActive(true);
            objSword.transform.position = new Vector3(0, 0, 0);
            objSword.transform.position = this.transform.position;

            spartanKing.wrapMode = WrapMode.Once;
            spartanKing.CrossFade("attack", 0.3f);

            float fDelayTime = spartanKing.GetClip("attack").length - 0.3f;
            // >> �ִϸ��̼� ������ �ð�

            yield return new WaitForSeconds(fDelayTime);

            objSword.SetActive(false);
            spartanKing.wrapMode = WrapMode.Loop;
            spartanKing.CrossFade("idle", 0.3f);

            isFin = false;
        }
    }

    void CharacterControll()
    {
        // >> ������ �̵��� �ǳ� ����鼭 ��ȯ��
        // >> ������Ģ�� ������� ����! RPG ����� �ٸ� ��� �̿��ؾ���
        // >> �浹 ���� ó����

        velocity = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
        velocity *= RunSpeed;

        if (velocity.magnitude > 0.5f)
        {
            // -> magnitude ���� ã�ƺ���
            spartanKing.CrossFade("run", 0.3f);
            transform.LookAt(transform.position + velocity);
        }
        else if (Input.GetKey(KeyCode.F))
            StartCoroutine("AttackToIdle");
        // else
        //     spartanKing.CrossFade("idle", 0.3f);

        playerController.Move(velocity * Time.deltaTime);
        // ->  �߷� ���� x : ���߿� �� ���� ��� ���ߺξ� ���� ��
        // -> + Physics.gravity ���ָ� �߷¹��� �� ����

        // playerController.SimpleMove(velocity * Time.deltaTime);
        // -> �߷� ����
    }

    static float fRotSpeed = 480.0f;
    void CharacterControll_Slerp()
    {
        Vector3 direction = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));

        if(Input.GetKeyDown(KeyCode.Space))
        {
            // StartCoroutine("MoveDash");

            Vector3 prePos = transform.position;

            Plane plane = new Plane(Vector3.up, 0); // ������ ��

            float distance;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

            Vector3 hitPos;
            Vector3 dir = new Vector3(0, 0, 0);
            if (plane.Raycast(ray, out distance))
            {
                hitPos = ray.GetPoint(distance);
                dir = hitPos - transform.position;

                transform.rotation = Quaternion.LookRotation(dir);
                dir = Vector3.Normalize(dir);
            }

            // transform.Translate(dir * 1000 * Time.deltaTime);
            transform.position += (dir * 1000 * Time.deltaTime);
            // >> todo : �̵� ����
        }

        if (Input.GetKeyDown(KeyCode.Mouse0))
        {
            // >> Ŀ�� ��ġ(���콺 Ŭ��) ����
            Plane plane = new Plane(Vector3.up, 0); // ������ ��

            float distance;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (plane.Raycast(ray, out distance))
            {
                // transform.position = ray.GetPoint(distance);
                transform.LookAt(ray.GetPoint(distance));
            }
            // << Ŀ�� ��ġ(���콺 Ŭ��) ����

            StartCoroutine("AttackToIdle");

        }

        if (!isFin)
        {
            if (direction.sqrMagnitude > 0.01f)
            {
                spartanKing.CrossFade("run", 0.3f);
                Vector3 forward = Vector3.Slerp(transform.forward,
                                                direction,
                                                fRotSpeed * Time.deltaTime / Vector3.Angle(transform.forward, direction));
                // >> �ٶ󺸴� ����, �̵� ���� �� ����

                transform.LookAt(transform.position + forward);

            }
            else
                spartanKing.CrossFade("idle", 0.3f);

            playerController.Move(direction * RunSpeed * Time.deltaTime + Physics.gravity);
        }

    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        // >> ĳ���� ��Ʈ�ѷ����� �浹 Ȯ�� ����
        // Debug.Log(hit.collider.name);
    }

}
