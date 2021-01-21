using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ActionManager : MonoBehaviour
{
    private IAction curAction;

    public void StartAction(IAction newAction)
    {
        // 대리자
        if (curAction == newAction)
            return;

        if(curAction != null)
            curAction.End();

        curAction = newAction;
    }

}
