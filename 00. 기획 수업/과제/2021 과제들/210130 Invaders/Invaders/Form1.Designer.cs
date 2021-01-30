namespace Invaders
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
            this.components = new System.ComponentModel.Container();
            this.pictureBox_Background = new System.Windows.Forms.PictureBox();
            this.label_Score = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox_playerSpeed = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_EnemySpeed = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox_Bullet = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Background)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox_Background
            // 
            this.pictureBox_Background.Location = new System.Drawing.Point(0, -1);
            this.pictureBox_Background.Name = "pictureBox_Background";
            this.pictureBox_Background.Size = new System.Drawing.Size(592, 513);
            this.pictureBox_Background.TabIndex = 0;
            this.pictureBox_Background.TabStop = false;
            // 
            // label_Score
            // 
            this.label_Score.AutoSize = true;
            this.label_Score.Font = new System.Drawing.Font("Gulim", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label_Score.Location = new System.Drawing.Point(21, 23);
            this.label_Score.Name = "label_Score";
            this.label_Score.Size = new System.Drawing.Size(135, 24);
            this.label_Score.TabIndex = 3;
            this.label_Score.Text = "PlayerScore";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(609, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 12);
            this.label1.TabIndex = 7;
            this.label1.Text = "Player Status";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(609, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "PlayerSpeed";
            // 
            // textBox_playerSpeed
            // 
            this.textBox_playerSpeed.Location = new System.Drawing.Point(710, 35);
            this.textBox_playerSpeed.Name = "textBox_playerSpeed";
            this.textBox_playerSpeed.Size = new System.Drawing.Size(86, 21);
            this.textBox_playerSpeed.TabIndex = 8;
            this.textBox_playerSpeed.TextChanged += new System.EventHandler(this.textBox_playerSpeed_TextChanged);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(609, 158);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(84, 12);
            this.label3.TabIndex = 9;
            this.label3.Text = "Enemy Status";
            // 
            // textBox_EnemySpeed
            // 
            this.textBox_EnemySpeed.Location = new System.Drawing.Point(710, 176);
            this.textBox_EnemySpeed.Name = "textBox_EnemySpeed";
            this.textBox_EnemySpeed.Size = new System.Drawing.Size(86, 21);
            this.textBox_EnemySpeed.TabIndex = 11;
            this.textBox_EnemySpeed.TextChanged += new System.EventHandler(this.textBox_EnemySpeed_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(609, 179);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 12);
            this.label4.TabIndex = 10;
            this.label4.Text = "Speed";
            // 
            // textBox_Bullet
            // 
            this.textBox_Bullet.Location = new System.Drawing.Point(710, 62);
            this.textBox_Bullet.Name = "textBox_Bullet";
            this.textBox_Bullet.Size = new System.Drawing.Size(86, 21);
            this.textBox_Bullet.TabIndex = 13;
            this.textBox_Bullet.TextChanged += new System.EventHandler(this.textBox_Bullet_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(609, 65);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(72, 12);
            this.label5.TabIndex = 12;
            this.label5.Text = "BulletSpeed";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(808, 509);
            this.Controls.Add(this.textBox_Bullet);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBox_EnemySpeed);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox_playerSpeed);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label_Score);
            this.Controls.Add(this.pictureBox_Background);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Background)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_Background;
        private System.Windows.Forms.Label label_Score;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox_playerSpeed;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_EnemySpeed;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox_Bullet;
        private System.Windows.Forms.Label label5;
    }
}

