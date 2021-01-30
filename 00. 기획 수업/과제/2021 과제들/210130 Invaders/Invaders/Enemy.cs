using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;


namespace Invaders
{
    class Enemy
    {
        Bitmap bmp;
        PictureBox picture = new PictureBox();
        public PictureBox EnemyPicture { get { return picture; } }

        Point centerPos;


        int moveSpeed = 50;
        public int Speed { get { return moveSpeed; } set { moveSpeed = value; } }

        bool isNotMoving = true;
        public Enemy(Point point, string path)
        {
            centerPos = new Point(point.X * (1 / 2), point.Y * (1 / 2));

            picture.Left = point.X;
            picture.Top = point.Y;
            picture.Width = 30;
            picture.Height = 30;

            Random rndNum = new Random();

            int enemyNum = rndNum.Next(0, 5);
            string name = "";
            switch(enemyNum)
            {
                case 1:
                    name = "bug1";
                    break;
                case 2:
                    name = "flyingsaucer1";
                    break;
                case 3:
                    name = "satellite1";
                    break;
                case 4:
                    name = "spaceship1";
                    break;
                case 5:
                    name = "star1";
                    break;
            }

            bmp = new Bitmap(@path + name + ".png");
            picture.Image = (Image)bmp;

            picture.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        public void Update()
        {
            Move();
        }


        bool isLeft = false;
        bool isMax = false;
        private void Move()
        {
            if (picture.Left == 50 && isNotMoving)
            {
                isNotMoving = false;
                picture.Left += moveSpeed;
                return;
            }

            if ((picture.Left == 500 || picture.Left == 50) && !isMax)
            {
                picture.Top += 30;
                isMax = true;

                if (isLeft)
                {
                    isLeft = false;
                }
                else
                {
                    isLeft = true;
                }
            }
            else
            {
                if (isMax)
                {
                    isMax = false;
                    if (isLeft)
                        picture.Left = 500;
                    else
                        picture.Left = 50;
                }

                if (!isLeft)
                    picture.Left += moveSpeed;
                else
                    picture.Left -= moveSpeed;
            }

        }

        public bool DoCheckLine()
        {
            if(picture.Top >= 480 && picture.Image != null)
            {
                picture.Image = null;
                return true;
            }
            return false;
        }
    }
}
