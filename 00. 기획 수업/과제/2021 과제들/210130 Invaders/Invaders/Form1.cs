using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Invaders
{
    public partial class Form1 : Form
    {
        string path = "D:\\바탕화면\\Invaders\\Invaders\\Image\\";
        Player player = new Player();
        PictureBox pPicture;
        PictureBox[] pHParr;

        Enemy[] enemy;
        PictureBox[] ePictureArr;

        Bullet[] bulletArr;
        PictureBox[] bPictureArr;

        public Form1()
        {
            InitializeComponent();

            pictureBox_Background.Load(@path + "background.png");
            pictureBox_Background.SizeMode = PictureBoxSizeMode.StretchImage;

            #region player

            Point point = new Point(250, 450);
            Size size = new Size(30, 30);
            player.Setup(point, size, path);

            pPicture = player.playerPicture;
            this.Controls.Add(pPicture);
            pPicture.BackColor = Color.Transparent;
            pPicture.Parent = pictureBox_Background;

            pHParr = new PictureBox[3];
            for (int i = 0; i < 3; i++)
            {
                pHParr[i] = new PictureBox();
                pHParr[i] = player.hpPicture(i);

                this.Controls.Add(pHParr[i]);

                pHParr[i].BackColor = Color.Transparent;
                pHParr[i].Parent = pictureBox_Background;
            }

            label_Score.Text = "0";
            label_Score.ForeColor = Color.White;
            label_Score.BackColor = Color.Transparent;
            label_Score.Parent = pictureBox_Background;
            #endregion

            #region enemy
            enemy = new Enemy[10];
            ePictureArr = new PictureBox[10];
            for (int i = 0; i < 10; i++)
            {
                Point pos = new Point(50 * i + 50, 100);
                enemy[i] = new Enemy(pos, path);

                ePictureArr[i] = enemy[i].EnemyPicture;
                this.Controls.Add(ePictureArr[i]);
                ePictureArr[i].BackColor = Color.Transparent;
                ePictureArr[i].Parent = pictureBox_Background;
            }

            #endregion

            #region bullet
            bulletArr = new Bullet[2];
            bPictureArr = new PictureBox[2];

            for (int i = 0; i < bulletArr.Length; i++)
            {
                bulletArr[i] = new Bullet(path);
                bPictureArr[i] = new PictureBox();

                bPictureArr[i] = bulletArr[i].bulletPicture;
                this.Controls.Add(bPictureArr[i]);
                bPictureArr[i].BackColor = Color.Transparent;
                bPictureArr[i].Parent = pictureBox_Background;
            }
            #endregion
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys key)
        {
            // >> 키 입력 처리
            if(key == Keys.Left || key == Keys.A)
            {
                pPicture.Left -= player.Speed;
            }
            else if (key == Keys.Right || key == Keys.D)
            {
                pPicture.Left += player.Speed;
            }
            else if (key == Keys.Space)
            {
                for (int i = 0; i < bulletArr.Length; i++)
                {
                    if (!bulletArr[i].IsShoot)
                    {
                        Point pos = new Point(pPicture.Left, pPicture.Top);
                        bulletArr[i].SetPos(pos);
                        break;
                    }
                }   // : for
            }

            return true;
        }

        private void textBox_playerSpeed_TextChanged(object sender, EventArgs e)
        {
            player.Speed = Int32.Parse(textBox_playerSpeed.Text);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            for(int i=0;i<enemy.Length;i++)
            {
                enemy[i].Update();

                if (enemy[i].DoCheckLine())
                    player.PlayerLife -= player.PlayerLife;
            }

            for (int i = 0; i < bulletArr.Length; i++)
            {
                if (bulletArr[i].IsShoot)
                {
                    bulletArr[i].Move();


                    //for (int j = 0; j < enemy.Length; j++)
                    //{
                    //    if(bulletArr[i].)
                    //}
                }

            }   // : for
            
        }

        private void textBox_EnemySpeed_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < enemy.Length; i++)
            {
                enemy[i].Speed = Int32.Parse(textBox_EnemySpeed.Text);
            }
        }

        private void textBox_Bullet_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < bulletArr.Length; i++)
            {
                bulletArr[i].Speed = Int32.Parse(textBox_Bullet.Text);
            }
        }
    }
}
