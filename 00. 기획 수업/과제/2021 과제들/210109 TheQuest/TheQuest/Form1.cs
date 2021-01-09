using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TheQuest
{
    public partial class Form1 : Form
    {
        Player player = null;
        
        string path = "D:\\바탕화면\\Image\\";
        int nSpeed = 10;

        public Form1()
        {
            player = new Player();

            InitializeComponent();

            // dungeoon Load
            pictureBox_dungeon.Load(@path + "dungeon600x400.png");
            pictureBox_dungeon.SizeMode = PictureBoxSizeMode.StretchImage;

            // player Load
            pictureBox_player.Load(@path + "player.png");
            pictureBox_player.SizeMode = PictureBoxSizeMode.StretchImage;

            pictureBox_player.BackColor = Color.Transparent; // 배경 투명
            pictureBox_player.Parent = pictureBox_dungeon;  // 부모 배경 설정

            // inventory Load
        
        }

        // playerMove
        private void button_m_up_Click(object sender, EventArgs e)
        {
            pictureBox_player.Top = pictureBox_player.Top - nSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);
        }

        private void button_m_left_Click(object sender, EventArgs e)
        {
            pictureBox_player.Left = pictureBox_player.Left - nSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);
        }

        private void button_m_down_Click(object sender, EventArgs e)
        {
            pictureBox_player.Top = pictureBox_player.Top + nSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);
        }

        private void button_m_right_Click(object sender, EventArgs e)
        {
            pictureBox_player.Left = pictureBox_player.Left + nSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);
        }

        private void pictureBox_inven1_Click(object sender, EventArgs e)
        {
            pictureBox_player.Left = pictureBox_player.Left + 50;

            Bitmap bmp;
            bmp = new Bitmap(@path + "player.png");

            PictureBox p1 = new PictureBox();

            p1.Image = (Image)bmp;

            p1.Location = new Point(79, 325);
            p1.Size = new Size(bmp.Width, bmp.Height);
            // p1.Left = 79;
            // p1.Top = 250;
            // p1.Width = 50;
            // p1.Height = 50;

            p1.Load(@path + "bat.png");
            p1.SizeMode = PictureBoxSizeMode.StretchImage;

            p1.BorderStyle = BorderStyle.FixedSingle;

            p1.BackColor = Color.Transparent; // 배경 투명
            p1.Parent = pictureBox_dungeon;  // 부모 배경 설정

            this.Controls.Add(p1);
            bmp = null;
        }
    }
}