using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Patrol : MonoBehaviour
{
    // >> 몬스터별 지정
    // >> 프리팹으로 사용 해도 됨
    // >> npc만나서 대화 후 npc 쫓아가는 이벤트 시에 사용해도 됨(실시간)
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    public int GetNextIndex(int index)
    {
        // >> 랜덤 순찰 경로 설정
        return (index + 1) % this.transform.childCount;
    }

    public Transform GetWayPoint(int index)
    {
        // >> 위치 확인만, 실제 이동 x
        return this.transform.GetChild(index);
    }

    private void OnDrawGizmos()
    {
        for(int i=0;i<this.transform.childCount;i++)
        {
            int next = GetNextIndex(i);
            Gizmos.color = Color.green;
            Gizmos.DrawSphere(GetWayPoint(i).position, 0.1f);
            // >> 노드 표시

            Gizmos.color = Color.white;
            Gizmos.DrawLine(GetWayPoint(i).position, GetWayPoint(next).position);
            // >> 경로표시
        }
    }
}
