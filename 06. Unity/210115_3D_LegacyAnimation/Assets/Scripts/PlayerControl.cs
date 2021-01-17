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
        // >> 애니메이션 플레이 설정(반복 등)

        playerController = gameObject.GetComponent<CharacterController>();

        objSword.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        // Animation_Play_1();
        // >> 애니메이션

        // CharacterControll();
        // >> 캐릭터 컨트롤러

        CharacterControll_Slerp();
        // >> 부드러운 캐릭터 컨트롤러
    }

    private void Animation_Play_1()
    {
        if (Input.GetKey(KeyCode.F))
        {
            // spartanKing.Play("attack");
            // >> 애니메이션 클립 이름
            // >> 기본 재생

            //spartanKing.wrapMode = WrapMode.Once;
            // >> 애니메이션 플레이 설정(반복 등)

            //spartanKing.CrossFade("attack", 0.3f);
            // >> 애니메이션 블렌딩
            // >> 애니메이션의 길이를 확인해서 지정해주면 됨

            // >> 애니메이션의 길이에 맞춰서 코루틴으로 작성해도 됨
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
            // >> 애니메이션 딜레이 시간

            yield return new WaitForSeconds(fDelayTime);

            objSword.SetActive(false);
            spartanKing.wrapMode = WrapMode.Loop;
            spartanKing.CrossFade("idle", 0.3f);

            isFin = false;
        }
    }

    void CharacterControll()
    {
        // >> 간단한 이동은 되나 끊기면서 전환됨
        // >> 물리법칙이 적용되지 않음! RPG 등에서는 다른 방식 이용해야함
        // >> 충돌 등은 처리됨

        velocity = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
        velocity *= RunSpeed;

        if (velocity.magnitude > 0.5f)
        {
            // -> magnitude 뭔지 찾아보기
            spartanKing.CrossFade("run", 0.3f);
            transform.LookAt(transform.position + velocity);
        }
        else if (Input.GetKey(KeyCode.F))
            StartCoroutine("AttackToIdle");
        // else
        //     spartanKing.CrossFade("idle", 0.3f);

        playerController.Move(velocity * Time.deltaTime);
        // ->  중력 받지 x : 공중에 떠 있을 경우 공중부양 상태 됨
        // -> + Physics.gravity 해주면 중력받을 수 있음

        // playerController.SimpleMove(velocity * Time.deltaTime);
        // -> 중력 받음
    }

    static float fRotSpeed = 480.0f;
    void CharacterControll_Slerp()
    {
        Vector3 direction = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));

        if(Input.GetKeyDown(KeyCode.Space))
        {
            // StartCoroutine("MoveDash");

            Vector3 prePos = transform.position;

            Plane plane = new Plane(Vector3.up, 0); // 가상의 면

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
            // >> todo : 이동 수정
        }

        if (Input.GetKeyDown(KeyCode.Mouse0))
        {
            // >> 커서 위치(마우스 클릭) 공격
            Plane plane = new Plane(Vector3.up, 0); // 가상의 면

            float distance;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (plane.Raycast(ray, out distance))
            {
                // transform.position = ray.GetPoint(distance);
                transform.LookAt(ray.GetPoint(distance));
            }
            // << 커서 위치(마우스 클릭) 공격

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
                // >> 바라보는 방향, 이동 방향 간 보간

                transform.LookAt(transform.position + forward);

            }
            else
                spartanKing.CrossFade("idle", 0.3f);

            playerController.Move(direction * RunSpeed * Time.deltaTime + Physics.gravity);
        }

    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        // >> 캐릭터 컨트롤러끼리 충돌 확인 가능
        // Debug.Log(hit.collider.name);
    }

}
