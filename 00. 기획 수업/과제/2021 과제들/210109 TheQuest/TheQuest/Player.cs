using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheQuest
{
    class Player
    {
        int nMoveSpeed = 10;
        public int MoveSpeed
        {
            get
            {
                return nMoveSpeed;
            }
            set
            {
                nMoveSpeed = value;
            }
        }

        int[] CenterPosArr = new int[2];
        public int[] CenterPos
        {
            get
            {
                return CenterPosArr;
            }
        }

        public void SetCenterPos(int top, int left, int width, int height)
        {
            float x = (top + height) * 0.5f;
            float y = (left + width) * 0.5f;

            CenterPos[0] = (int) x;
            CenterPos[1] = (int) y;
        }

    }

}
