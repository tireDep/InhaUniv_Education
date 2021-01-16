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
        Monster monster = null;
        
        string path = "D:\\바탕화면\\Image\\";

        int nCheckRange = 10;

        public Form1()
        {
            player = new Player();

            monster = new Monster(350, 200, "bat");
            PictureBox a = monster.MonsterPictureBox;
            this.Controls.Add(a);

            InitializeComponent();

            // dungeoon Load
            pictureBox_dungeon.Load(@path + "dungeon600x400.png");
            pictureBox_dungeon.SizeMode = PictureBoxSizeMode.StretchImage;

            // enemy Img
            a.BackColor = Color.Transparent;
            a.Parent = pictureBox_dungeon;
            // >> 배경 투명화

            // player Load
            pictureBox_player.Load(@path + "player.png");
            pictureBox_player.SizeMode = PictureBoxSizeMode.StretchImage;

            pictureBox_player.BackColor = Color.Transparent; // 배경 투명
            pictureBox_player.Parent = pictureBox_dungeon;  // 부모 배경 설정

            label_Player.Text = "Player Hp : " + player.PlayerHP.ToString();
            textBox_PlayerHp.Text = player.PlayerHP.ToString();
            textBox_playerSpeed.Text = player.MoveSpeed.ToString();

            // inventory Load

            // enemy labelSetting
            label_Enemy1.Text = monster.MonsterName + " : " + monster.MonsterHp.ToString();

            label_monsterName.Text = monster.MonsterName;
            textBox_monsterHp.Text = monster.MonsterHp.ToString();
            textBox_monsterSpeed.Text = monster.MoveSpeed.ToString();
            textBox_monsterDmg.Text = monster.Damage.ToString();
            // textBox_monsterRange = monster.Damage.ToString();

            // item labelSetting
            label_itemName.Text = player.HasWeapon.WeaponName;
            textBox_itemDmg.Text = player.HasWeapon.WeaponDamage.ToString();
            textBox_itemRng.Text = player.HasWeapon.WeaponRange.ToString();
            textBox_itemRec.Text = player.HasWeapon.WeaponRecovery.ToString();
        }

        // playerMove
        private void button_m_up_Click(object sender, EventArgs e)
        {
            pictureBox_player.Top = pictureBox_player.Top - player.MoveSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);

            CheckHit(player, monster);
            DoTurnMonster();
        }

        private void button_m_left_Click(object sender, EventArgs e)
        {
            pictureBox_player.Left = pictureBox_player.Left - player.MoveSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);

            CheckHit(player, monster);
            DoTurnMonster();
        }

        private void button_m_down_Click(object sender, EventArgs e)
        {
            pictureBox_player.Top = pictureBox_player.Top + player.MoveSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);

            CheckHit(player, monster);
            DoTurnMonster();
        }

        private void button_m_right_Click(object sender, EventArgs e)
        {
            pictureBox_player.Left = pictureBox_player.Left + player.MoveSpeed;
            player.SetCenterPos(pictureBox_player.Top, pictureBox_player.Left, pictureBox_player.Width, pictureBox_player.Height);

            CheckHit(player, monster);
            DoTurnMonster();
        }

        private void CheckHit(Player player, Monster monster)
        {
            // >> 몬스터 충돌판정
            if(Math.Abs(player.CenterPos[0] - monster.CenterPos[0]) <= nCheckRange
            && Math.Abs(player.CenterPos[1] - monster.CenterPos[1]) <= nCheckRange)
            {
                player.LoseHpPoint(monster.Damage);
            }

            if(player.PlayerHP <= 0)
            {
                const string message = "GameOver";
                const string caption = "System";
                var result = MessageBox.Show(message, caption,
                                             MessageBoxButtons.OK,
                                             MessageBoxIcon.Question);

                if(result == DialogResult.OK)
                {
                    // todo : 프로그램 종료
                }
            }

            label_Player.Text = "Player Hp : " + player.PlayerHP.ToString();
        }

        private void DoTurnMonster()
        {
            // >> 랜덤 위치로 이동

            Random random = new Random();
            int dir = random.Next(0, 3);
            string strDir;
            switch(dir)
            {
                case 0:
                    strDir = "Up";
                    break;
                case 1:
                    strDir = "Left";
                    break;
                case 2:
                    strDir = "Down";
                    break;
                case 3:
                    strDir = "Right";
                    break;
                default:
                    strDir = "";
                    break;
            }

            monster.MonsterMove(strDir);
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

        private void textBox_PlayerHp_TextChanged(object sender, EventArgs e)
        {
            label_Player.Text = "Player Hp : " + textBox_PlayerHp.Text;

            player.PlayerHP = Int32.Parse(textBox_PlayerHp.Text);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            player.MoveSpeed = Int32.Parse(textBox_playerSpeed.Text);
        }


        private void CheckMonsterState()
        {
            monster.LoseHp(player.HasWeapon.WeaponDamage);

            label_Enemy1.Text = monster.MonsterName + " : " + monster.MonsterHp.ToString();

            if (monster.MonsterHp <= 0)
            {
                const string message = "GameClear";
                const string caption = "System";
                var result = MessageBox.Show(message, caption,
                                             MessageBoxButtons.OK,
                                             MessageBoxIcon.Question);

                if (result == DialogResult.OK)
                {
                    // todo : 프로그램 종료
                }
            }
        }

        private void button_a_up_Click(object sender, EventArgs e)
        {
            int smallNum = player.CenterPos[1], bigNum = player.CenterPos[1] - player.HasWeapon.WeaponRange;
            if(smallNum > bigNum)
            {
                int temp = smallNum;
                smallNum = bigNum;
                bigNum = temp;
            }

            if(smallNum <= monster.CenterPos[1] 
           && bigNum >= monster.CenterPos[1]
           && Math.Abs(player.CenterPos[0] - monster.CenterPos[0]) <= nCheckRange)
            {
                CheckMonsterState();
            }

            DoTurnMonster();
        }

        private void button_a_left_Click(object sender, EventArgs e)
        {
            int smallNum = player.CenterPos[0], bigNum = player.CenterPos[0] - player.HasWeapon.WeaponRange;
            if (smallNum > bigNum)
            {
                int temp = smallNum;
                smallNum = bigNum;
                bigNum = temp;
            }

            if (smallNum <= monster.CenterPos[0]
           && bigNum >= monster.CenterPos[0]
           && Math.Abs(player.CenterPos[1] - monster.CenterPos[1]) <= nCheckRange)
            {
                CheckMonsterState();
            }

            DoTurnMonster();
        }

        private void button_a_right_Click(object sender, EventArgs e)
        {
            int smallNum = player.CenterPos[0], bigNum = player.CenterPos[0] + player.HasWeapon.WeaponRange;
            if (smallNum > bigNum)
            {
                int temp = smallNum;
                smallNum = bigNum;
                bigNum = temp;
            }

            if (smallNum <= monster.CenterPos[0]
           && bigNum >= monster.CenterPos[0]
           && Math.Abs(player.CenterPos[1] - monster.CenterPos[1]) <= nCheckRange)
            {
                CheckMonsterState();
            }

            DoTurnMonster();
        }

        private void button_a_down_Click(object sender, EventArgs e)
        {
            int smallNum = player.CenterPos[1], bigNum = player.CenterPos[1] + player.HasWeapon.WeaponRange;
            if (smallNum > bigNum)
            {
                int temp = smallNum;
                smallNum = bigNum;
                bigNum = temp;
            }

            if (smallNum <= monster.CenterPos[1]
           && bigNum >= monster.CenterPos[1]
           && Math.Abs(player.CenterPos[0] - monster.CenterPos[0]) <= nCheckRange)
            {
                CheckMonsterState();
            }

            DoTurnMonster();
        }

        private void textBox_monsterHp_TextChanged(object sender, EventArgs e)
        {
            monster.MonsterHp = Int32.Parse(textBox_monsterHp.Text);

            label_Enemy1.Text = monster.MonsterName + " : " + monster.MonsterHp.ToString();
        }

        private void textBox_monsterSpeed_TextChanged(object sender, EventArgs e)
        {
            monster.MoveSpeed = Int32.Parse(textBox_monsterSpeed.Text);
        }

        private void textBox_monsterDmg_TextChanged(object sender, EventArgs e)
        {
            monster.Damage = Int32.Parse(textBox_monsterDmg.Text);
        }

        private void textBox_monsterRange_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_itemDmg_TextChanged(object sender, EventArgs e)
        {
            player.HasWeapon.WeaponDamage = Int32.Parse(textBox_itemDmg.Text);
        }

        private void textBox_itemRng_TextChanged(object sender, EventArgs e)
        {
            player.HasWeapon.WeaponRange = Int32.Parse(textBox_itemRng.Text);
        }

        private void textBox_itemRec_TextChanged(object sender, EventArgs e)
        {
            player.HasWeapon.WeaponRecovery = Int32.Parse(textBox_itemRec.Text);
        }
    }
}