using System.Collections;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    public GameObject obstacleObj = null;
    public float fRange = 3.0f;

    IEnumerator Start()
    {
        while (true)
        {
            if (obstacleObj != null)
            {
                transform.position = new Vector3(
                    transform.position.x,
                    Random.Range(-fRange, fRange),
                    transform.position.z);

               Instantiate(obstacleObj, transform.position, transform.rotation);
            }

            yield return new WaitForSeconds(1.5f);
            // -> 시스템한테 알려줌, 이 시간후에 이 함수로 다시 돌아옴
            // -> sleep과 다르게 제어권을 넘겨줌
            // -> 코루틴과 유사함
        }

        // >> update에서 안하는 이유
        // - 일정한 시간에 이루어지지 않음
        // - 시간 재서 해도 상관 없음
        //
        // GameObject obj = null;
        //  
        // if (obstacleObj != null)
        //     obj = Instantiate(obstacleObj, transform.position, transform.rotation);
        // // -> 오버라이딩 많으니까 참고할 것
        //
        //
        // 삭제 방법 
        // obstacle에서 처리할 것
        // OnBecameInvisible
        // Destroy
        // 코루틴, 인보크 등
        // Destroy(obj, 1.0f);
    }

}
