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
        // -> �����ϸ鼭 �ٷ� ����
        // -> ���� ����� ������Ʈ�� �־ �ǳ�, ������Ʈ�� ��� ������ �������� ���� �� ����

        // Invoke("TTT", 0.1f); // �� �ð��� üũ
        // InvokeRepeating(); // �ݺ������� �� �ð��� üũ
        // // -> �ش� �ð��� ����
    }

    IEnumerator ShotEffect_Coroutine()
    {
        // -> �ִϸ��̼� ���� ����
        while (animator.GetCurrentAnimatorStateInfo(0).normalizedTime < 1.0f)
            yield return null;
        // -> IEnumerator�� yield return �ʿ���

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
