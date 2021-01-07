using UnityEngine;

public class Raycast : MonoBehaviour
{
    [Range(0, 50)]
    public float fDistance = 10.0f;
    private RaycastHit raycastHit;
    private Ray ray;

    private RaycastHit[] rayHits;

    
    void Start()
    {
        ray = new Ray();
        ray.origin = this.transform.position;
        ray.direction = this.transform.forward;

        // ray = new Ray(this.transform.position, this.transform.forward);
        // >> 같은 방법
    }

    void Update()
    {
        // CheckRay_1();
        // CheckRay_2();
        // CheckRay_3();

        
    }

    void CheckRay_1()
    {
        // >> 한 방향에 있는 것에 대해서만 판별(1개)

        // 여러 함수 중, 부딪힌 오브젝트의 정보까지 받아올 수 있는 함수
        if (Physics.Raycast(ray, out raycastHit, fDistance))
        {
            Debug.Log(raycastHit.collider.gameObject.name);
        }
    }

    void CheckRay_2()
    {
        // >> 한 방향에 있는 모든 것에 대해서 판별
        rayHits = Physics.RaycastAll(ray, fDistance);

        for (int index = 0; index < rayHits.Length; index++)
        {
            Debug.Log(rayHits[index].collider.gameObject.name + "Hit");
        }
    }

    private void OnDrawGizmos()
    {
        // >> 디버그용으로 그릴 수 있음
        // >> 씬 뷰에만 그려짐, 게임 뷰에는 그려지지 않음

        Debug.DrawRay(ray.origin, ray.direction * fDistance, Color.red);
    }

    void CheckRay_3()
    {
        rayHits = Physics.RaycastAll(ray, fDistance);
        for (int index = 0; index < rayHits.Length; index++)
        {
            if (rayHits[index].collider.gameObject.tag == "Enemy")
            {
                Debug.Log(rayHits[index].collider.gameObject.name + "Hit - Tag");
            }
            else if (rayHits[index].collider.gameObject.layer == LayerMask.NameToLayer("Test3"))
            {
                Debug.Log(rayHits[index].collider.gameObject.name + "Hit - Layer");
            }
        }

        // >> 일정범위 탐지
        // Physics.SphereCastAll(ray, 10.0f);
        // Physics.BoxCastAll()
    }
}
