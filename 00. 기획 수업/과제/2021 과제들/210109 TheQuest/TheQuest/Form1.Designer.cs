namespace TheQuest
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox_dungeon = new System.Windows.Forms.PictureBox();
            this.groupBox_Move = new System.Windows.Forms.GroupBox();
            this.button_m_left = new System.Windows.Forms.Button();
            this.button_m_right = new System.Windows.Forms.Button();
            this.button_m_down = new System.Windows.Forms.Button();
            this.button_m_up = new System.Windows.Forms.Button();
            this.groupBox_Attack = new System.Windows.Forms.GroupBox();
            this.button_a_drink = new System.Windows.Forms.Button();
            this.button_a_left = new System.Windows.Forms.Button();
            this.button_a_down = new System.Windows.Forms.Button();
            this.button_a_right = new System.Windows.Forms.Button();
            this.button_a_up = new System.Windows.Forms.Button();
            this.label_Player = new System.Windows.Forms.Label();
            this.label_Enemy1 = new System.Windows.Forms.Label();
            this.label_Enemy2 = new System.Windows.Forms.Label();
            this.label_Enemy3 = new System.Windows.Forms.Label();
            this.pictureBox_player = new System.Windows.Forms.PictureBox();
            this.pictureBox_inven1 = new System.Windows.Forms.PictureBox();
            this.pictureBox_inven2 = new System.Windows.Forms.PictureBox();
            this.pictureBox_inven3 = new System.Windows.Forms.PictureBox();
            this.pictureBox_inven4 = new System.Windows.Forms.PictureBox();
            this.pictureBox_inven5 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_dungeon)).BeginInit();
            this.groupBox_Move.SuspendLayout();
            this.groupBox_Attack.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven5)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox_dungeon
            // 
            this.pictureBox_dungeon.Location = new System.Drawing.Point(3, 4);
            this.pictureBox_dungeon.Name = "pictureBox_dungeon";
            this.pictureBox_dungeon.Size = new System.Drawing.Size(600, 400);
            this.pictureBox_dungeon.TabIndex = 0;
            this.pictureBox_dungeon.TabStop = false;
            // 
            // groupBox_Move
            // 
            this.groupBox_Move.Controls.Add(this.button_m_left);
            this.groupBox_Move.Controls.Add(this.button_m_right);
            this.groupBox_Move.Controls.Add(this.button_m_down);
            this.groupBox_Move.Controls.Add(this.button_m_up);
            this.groupBox_Move.Location = new System.Drawing.Point(609, 3);
            this.groupBox_Move.Name = "groupBox_Move";
            this.groupBox_Move.Size = new System.Drawing.Size(245, 145);
            this.groupBox_Move.TabIndex = 1;
            this.groupBox_Move.TabStop = false;
            this.groupBox_Move.Text = "Move";
            // 
            // button_m_left
            // 
            this.button_m_left.Location = new System.Drawing.Point(15, 61);
            this.button_m_left.Name = "button_m_left";
            this.button_m_left.Size = new System.Drawing.Size(75, 23);
            this.button_m_left.TabIndex = 0;
            this.button_m_left.Text = "Left";
            this.button_m_left.UseVisualStyleBackColor = true;
            this.button_m_left.Click += new System.EventHandler(this.button_m_left_Click);
            // 
            // button_m_right
            // 
            this.button_m_right.Location = new System.Drawing.Point(161, 61);
            this.button_m_right.Name = "button_m_right";
            this.button_m_right.Size = new System.Drawing.Size(75, 23);
            this.button_m_right.TabIndex = 0;
            this.button_m_right.Text = "Right";
            this.button_m_right.UseVisualStyleBackColor = true;
            this.button_m_right.Click += new System.EventHandler(this.button_m_right_Click);
            // 
            // button_m_down
            // 
            this.button_m_down.Location = new System.Drawing.Point(88, 103);
            this.button_m_down.Name = "button_m_down";
            this.button_m_down.Size = new System.Drawing.Size(75, 23);
            this.button_m_down.TabIndex = 0;
            this.button_m_down.Text = "Down";
            this.button_m_down.UseVisualStyleBackColor = true;
            this.button_m_down.Click += new System.EventHandler(this.button_m_down_Click);
            // 
            // button_m_up
            // 
            this.button_m_up.Location = new System.Drawing.Point(88, 20);
            this.button_m_up.Name = "button_m_up";
            this.button_m_up.Size = new System.Drawing.Size(75, 23);
            this.button_m_up.TabIndex = 0;
            this.button_m_up.Text = "Up";
            this.button_m_up.UseVisualStyleBackColor = true;
            this.button_m_up.Click += new System.EventHandler(this.button_m_up_Click);
            // 
            // groupBox_Attack
            // 
            this.groupBox_Attack.Controls.Add(this.button_a_drink);
            this.groupBox_Attack.Controls.Add(this.button_a_left);
            this.groupBox_Attack.Controls.Add(this.button_a_down);
            this.groupBox_Attack.Controls.Add(this.button_a_right);
            this.groupBox_Attack.Controls.Add(this.button_a_up);
            this.groupBox_Attack.Location = new System.Drawing.Point(609, 154);
            this.groupBox_Attack.Name = "groupBox_Attack";
            this.groupBox_Attack.Size = new System.Drawing.Size(245, 131);
            this.groupBox_Attack.TabIndex = 2;
            this.groupBox_Attack.TabStop = false;
            this.groupBox_Attack.Text = "Attack";
            // 
            // button_a_drink
            // 
            this.button_a_drink.Location = new System.Drawing.Point(87, 59);
            this.button_a_drink.Name = "button_a_drink";
            this.button_a_drink.Size = new System.Drawing.Size(75, 23);
            this.button_a_drink.TabIndex = 5;
            this.button_a_drink.Text = "Drink";
            this.button_a_drink.UseVisualStyleBackColor = true;
            // 
            // button_a_left
            // 
            this.button_a_left.Location = new System.Drawing.Point(12, 59);
            this.button_a_left.Name = "button_a_left";
            this.button_a_left.Size = new System.Drawing.Size(75, 23);
            this.button_a_left.TabIndex = 1;
            this.button_a_left.Text = "Left";
            this.button_a_left.UseVisualStyleBackColor = true;
            // 
            // button_a_down
            // 
            this.button_a_down.Location = new System.Drawing.Point(88, 98);
            this.button_a_down.Name = "button_a_down";
            this.button_a_down.Size = new System.Drawing.Size(75, 23);
            this.button_a_down.TabIndex = 3;
            this.button_a_down.Text = "Down";
            this.button_a_down.UseVisualStyleBackColor = true;
            // 
            // button_a_right
            // 
            this.button_a_right.Location = new System.Drawing.Point(162, 59);
            this.button_a_right.Name = "button_a_right";
            this.button_a_right.Size = new System.Drawing.Size(75, 23);
            this.button_a_right.TabIndex = 2;
            this.button_a_right.Text = "Right";
            this.button_a_right.UseVisualStyleBackColor = true;
            // 
            // button_a_up
            // 
            this.button_a_up.Location = new System.Drawing.Point(88, 20);
            this.button_a_up.Name = "button_a_up";
            this.button_a_up.Size = new System.Drawing.Size(75, 23);
            this.button_a_up.TabIndex = 4;
            this.button_a_up.Text = "Up";
            this.button_a_up.UseVisualStyleBackColor = true;
            // 
            // label_Player
            // 
            this.label_Player.AutoSize = true;
            this.label_Player.Location = new System.Drawing.Point(609, 301);
            this.label_Player.Name = "label_Player";
            this.label_Player.Size = new System.Drawing.Size(41, 12);
            this.label_Player.TabIndex = 0;
            this.label_Player.Text = "Player";
            // 
            // label_Enemy1
            // 
            this.label_Enemy1.AutoSize = true;
            this.label_Enemy1.Location = new System.Drawing.Point(609, 325);
            this.label_Enemy1.Name = "label_Enemy1";
            this.label_Enemy1.Size = new System.Drawing.Size(51, 12);
            this.label_Enemy1.TabIndex = 3;
            this.label_Enemy1.Text = "Enemy1";
            // 
            // label_Enemy2
            // 
            this.label_Enemy2.AutoSize = true;
            this.label_Enemy2.Location = new System.Drawing.Point(609, 350);
            this.label_Enemy2.Name = "label_Enemy2";
            this.label_Enemy2.Size = new System.Drawing.Size(51, 12);
            this.label_Enemy2.TabIndex = 4;
            this.label_Enemy2.Text = "Enemy2";
            // 
            // label_Enemy3
            // 
            this.label_Enemy3.AutoSize = true;
            this.label_Enemy3.Location = new System.Drawing.Point(609, 376);
            this.label_Enemy3.Name = "label_Enemy3";
            this.label_Enemy3.Size = new System.Drawing.Size(51, 12);
            this.label_Enemy3.TabIndex = 5;
            this.label_Enemy3.Text = "Enemy3";
            // 
            // pictureBox_player
            // 
            this.pictureBox_player.Location = new System.Drawing.Point(79, 130);
            this.pictureBox_player.Name = "pictureBox_player";
            this.pictureBox_player.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_player.TabIndex = 6;
            this.pictureBox_player.TabStop = false;
            // 
            // pictureBox_inven1
            // 
            this.pictureBox_inven1.Location = new System.Drawing.Point(79, 325);
            this.pictureBox_inven1.Name = "pictureBox_inven1";
            this.pictureBox_inven1.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_inven1.TabIndex = 7;
            this.pictureBox_inven1.TabStop = false;
            this.pictureBox_inven1.Click += new System.EventHandler(this.pictureBox_inven1_Click);
            // 
            // pictureBox_inven2
            // 
            this.pictureBox_inven2.Location = new System.Drawing.Point(177, 325);
            this.pictureBox_inven2.Name = "pictureBox_inven2";
            this.pictureBox_inven2.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_inven2.TabIndex = 8;
            this.pictureBox_inven2.TabStop = false;
            // 
            // pictureBox_inven3
            // 
            this.pictureBox_inven3.Location = new System.Drawing.Point(285, 325);
            this.pictureBox_inven3.Name = "pictureBox_inven3";
            this.pictureBox_inven3.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_inven3.TabIndex = 9;
            this.pictureBox_inven3.TabStop = false;
            // 
            // pictureBox_inven4
            // 
            this.pictureBox_inven4.Location = new System.Drawing.Point(387, 325);
            this.pictureBox_inven4.Name = "pictureBox_inven4";
            this.pictureBox_inven4.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_inven4.TabIndex = 10;
            this.pictureBox_inven4.TabStop = false;
            // 
            // pictureBox_inven5
            // 
            this.pictureBox_inven5.Location = new System.Drawing.Point(487, 325);
            this.pictureBox_inven5.Name = "pictureBox_inven5";
            this.pictureBox_inven5.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_inven5.TabIndex = 11;
            this.pictureBox_inven5.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1111, 407);
            this.Controls.Add(this.pictureBox_inven5);
            this.Controls.Add(this.pictureBox_inven4);
            this.Controls.Add(this.pictureBox_inven3);
            this.Controls.Add(this.pictureBox_inven2);
            this.Controls.Add(this.pictureBox_inven1);
            this.Controls.Add(this.pictureBox_player);
            this.Controls.Add(this.label_Enemy3);
            this.Controls.Add(this.label_Enemy2);
            this.Controls.Add(this.label_Enemy1);
            this.Controls.Add(this.label_Player);
            this.Controls.Add(this.groupBox_Attack);
            this.Controls.Add(this.groupBox_Move);
            this.Controls.Add(this.pictureBox_dungeon);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_dungeon)).EndInit();
            this.groupBox_Move.ResumeLayout(false);
            this.groupBox_Attack.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_inven5)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_dungeon;
        private System.Windows.Forms.GroupBox groupBox_Move;
        private System.Windows.Forms.GroupBox groupBox_Attack;
        private System.Windows.Forms.Label label_Player;
        private System.Windows.Forms.Label label_Enemy1;
        private System.Windows.Forms.Label label_Enemy2;
        private System.Windows.Forms.Label label_Enemy3;
        private System.Windows.Forms.Button button_m_left;
        private System.Windows.Forms.Button button_m_right;
        private System.Windows.Forms.Button button_m_down;
        private System.Windows.Forms.Button button_m_up;
        private System.Windows.Forms.Button button_a_left;
        private System.Windows.Forms.Button button_a_down;
        private System.Windows.Forms.Button button_a_right;
        private System.Windows.Forms.Button button_a_up;
        private System.Windows.Forms.Button button_a_drink;
        private System.Windows.Forms.PictureBox pictureBox_player;
        private System.Windows.Forms.PictureBox pictureBox_inven1;
        private System.Windows.Forms.PictureBox pictureBox_inven2;
        private System.Windows.Forms.PictureBox pictureBox_inven3;
        private System.Windows.Forms.PictureBox pictureBox_inven4;
        private System.Windows.Forms.PictureBox pictureBox_inven5;
    }
}

