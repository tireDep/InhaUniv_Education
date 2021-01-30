using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;

namespace Invaders
{
    class Player
    {
        Bitmap bmp;
        PictureBox picture = new PictureBox();
        public PictureBox playerPicture { get { return picture; } }

        PictureBox[] picture_hpArr = new PictureBox[3];
        public PictureBox hpPicture(int i)
        {
            return picture_hpArr[i];
        }

        Point centerPos;
        public Point CenterPos { get { return centerPos; } }

        int score = 0;
        public int Score { get { return score; }    set { score = value; } }

        int speed = 50;
        public int Speed { get { return speed; }    set { speed = value; } }

        int playerLife = 3;
        public int PlayerLife
        {
            get { return playerLife; }
            set
            {
                playerLife = value;

                for(int i = 0; i < picture_hpArr.Length; i++)
                {
                    if (picture_hpArr[i].Image != null)
                    {
                        picture_hpArr[i].Image = null;
                        break;
                    }
                } // : for

            } // : set

        }

        public void Setup(Point point, Size size, string path)
        {
            centerPos = point;

            picture.Left = point.X;
            picture.Top = point.Y;
            picture.Width = size.Width;
            picture.Height = size.Height;

            bmp = new Bitmap(@path + "player" + ".png");
            picture.Image = (Image)bmp;

            picture.SizeMode = PictureBoxSizeMode.StretchImage;

            int leftPos = 450;
            for (int i = 0; i < picture_hpArr.Length; i++)
            {
                picture_hpArr[i] = new PictureBox();

                picture_hpArr[i].Left = leftPos;
                leftPos += 50;

                picture_hpArr[i].Top = 10;
                picture_hpArr[i].Width = size.Width;
                picture_hpArr[i].Height = size.Height;

                picture_hpArr[i].Image = (Image)bmp;

                picture_hpArr[i].SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }

    }
}
