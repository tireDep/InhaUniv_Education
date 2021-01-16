using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace TheQuest
{
    class Monster
    {
        Bitmap bmp;
        PictureBox p1 = new PictureBox();
        private string monsterName;
        public string MonsterName
        {
            get { return monsterName; }
        }


        public PictureBox  MonsterPictureBox
        {
            get { return p1; }
        }

        string path = "D:\\바탕화면\\Image\\";
        int nSpeed = 10;
        public int MoveSpeed
        {
            get
            {
                return nSpeed;
            }
            set
            {
                nSpeed = value;
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

        private int attackDmg = 1;
        public int Damage
        {
            get { return attackDmg; }
            set { attackDmg = value; }
        }

        private int hp = 5;
        public int MonsterHp
        {
            get { return hp; }
            set { hp = value; }
        }

        public Monster(int leftPos, int topPos, string name = "bat")
        {
            monsterName = name;

            p1.Left = leftPos;
            p1.Top = topPos;
            p1.Width = 50;
            p1.Height = 50;
            p1.SizeMode = PictureBoxSizeMode.StretchImage;

            bmp = new Bitmap(@path + name + ".png");
            p1.Image = (Image)bmp;
        }

        public void MonsterMove(string strDir)
        {
            if (strDir == "Up") p1.Top = p1.Top - nSpeed;
            else if (strDir == "Left") p1.Left = p1.Left- nSpeed;
            else if (strDir == "Down") p1.Top = p1.Top + nSpeed;
            else if (strDir == "Right") p1.Left = p1.Left + nSpeed;

            if (p1.Top < 0) p1.Top = 0;
            else if (p1.Left < 0) p1.Left = 0;

            // if (p1.Top + nSpeed >= 400 - p1.Image.Height) p1.Top = 400 - p1.Image.Height;
            // else if (p1.Left + nSpeed >= 400 - p1.Image.Width) p1.Left = 600 - p1.Image.Width;

            SetCenter();
        }

        private void SetCenter()
        {
            CenterPosArr[0] = (int) ((p1.Top + p1.Height) * 0.5f);
            CenterPosArr[1] = (int) ((p1.Left + p1.Width) * 0.5f);
        }

        public void LoseHp(int dmg)
        {
            hp -= dmg;
        }
    }
}
