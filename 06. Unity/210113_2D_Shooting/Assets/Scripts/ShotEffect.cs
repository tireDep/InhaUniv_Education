using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShotEffect : MonoBehaviour
{
    private Animator animator = null;

    void Start()
    {
        animator = GetComponent<Animator>();

        StartCoroutine("ShotEffect_Coroutine");
        // -> 시작하면서 바로 실행
        // -> 같은 기능을 업데이트에 넣어도 되나, 업데이트의 경우 실행이 일정하지 않을 수 있음

        // Invoke("TTT", 0.1f); // 그 시간에 체크
        // InvokeRepeating(); // 반복적으로 그 시간에 체크
        // // -> 해당 시간에 실행
    }

    IEnumerator ShotEffect_Coroutine()
    {
        // -> 애니메이션 시작 여부
        while (animator.GetCurrentAnimatorStateInfo(0).normalizedTime < 1.0f)
            yield return null;
        // -> IEnumerator는 yield return 필요함

        Destroy(this.gameObject);
    }

    //private void TTT()
    //{
    //    if (animator.GetCurrentAnimatorStateInfo(0).normalizedTime < 1.0f)
    //        Invoke("TTT", 0.1f);

    //    Destroy(this.gameObject);
    //}

    //public GameObject obj = null;
    //public void Setup(Vector3 pos)
    //{
    //    animator = GetComponent<Animator>();

    //    Instantiate(obj, pos, this.transform.rotation);

    //    StartCoroutine("ShotEffect_Coroutine");
    //}
}
