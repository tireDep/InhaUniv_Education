using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;


namespace Invaders
{
    class Bullet
    {
        bool isShoot = false;
        public bool IsShoot { get { return isShoot; }   set { isShoot = value; } }

        Bitmap bmp;
        PictureBox picture = new PictureBox();
        public PictureBox bulletPicture { get { return picture; } }

        Point centerPos;

        int moveSpeed = 50;
        public int Speed { get { return moveSpeed; } set { moveSpeed = value; } }

        public Bullet(string path)
        {
            centerPos = new Point(0, 0);

            picture.Left = 0;
            picture.Top = 0;
            picture.Width = 5;
            picture.Height = 15;

            bmp = new Bitmap(@path + "bullet" + ".png");
            picture.Image = (Image)bmp;

            picture.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        public void SetPos(Point playerPos)
        {
            isShoot = true;

            picture.Left = playerPos.X + 13;
            picture.Top = playerPos.Y - 15;

            centerPos = new Point(playerPos.X * (1 / 2), playerPos.Y * (1 / 2));
        }

        public void Move()
        {
            picture.Top -= moveSpeed;

            if (picture.Top <= 0)
                isShoot = false;
        }

    }
}
