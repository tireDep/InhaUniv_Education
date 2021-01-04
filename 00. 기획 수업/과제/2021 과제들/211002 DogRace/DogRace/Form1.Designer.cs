namespace DogRace
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
            this.pictureBox_Track = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.numericUpDown_Dog = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_Bet = new System.Windows.Forms.NumericUpDown();
            this.button_race = new System.Windows.Forms.Button();
            this.button_Bet = new System.Windows.Forms.Button();
            this.radioButton_Al = new System.Windows.Forms.RadioButton();
            this.radioButton_Bob = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.label_nowName = new System.Windows.Forms.Label();
            this.label_AlMoney = new System.Windows.Forms.Label();
            this.label_BobMoney = new System.Windows.Forms.Label();
            this.radioButton_Joe = new System.Windows.Forms.RadioButton();
            this.Label_JoeMoney = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label_MinBet = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox_Dog1 = new System.Windows.Forms.PictureBox();
            this.pictureBox_Dog2 = new System.Windows.Forms.PictureBox();
            this.pictureBox_Dog3 = new System.Windows.Forms.PictureBox();
            this.pictureBox_Dog4 = new System.Windows.Forms.PictureBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.button3 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Track)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Dog)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Bet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog4)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox_Track
            // 
            this.pictureBox_Track.Location = new System.Drawing.Point(12, 14);
            this.pictureBox_Track.Name = "pictureBox_Track";
            this.pictureBox_Track.Size = new System.Drawing.Size(600, 200);
            this.pictureBox_Track.TabIndex = 0;
            this.pictureBox_Track.TabStop = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.numericUpDown_Dog);
            this.groupBox1.Controls.Add(this.numericUpDown_Bet);
            this.groupBox1.Controls.Add(this.button_race);
            this.groupBox1.Controls.Add(this.button_Bet);
            this.groupBox1.Controls.Add(this.radioButton_Al);
            this.groupBox1.Controls.Add(this.radioButton_Bob);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label_nowName);
            this.groupBox1.Controls.Add(this.label_AlMoney);
            this.groupBox1.Controls.Add(this.label_BobMoney);
            this.groupBox1.Controls.Add(this.radioButton_Joe);
            this.groupBox1.Controls.Add(this.Label_JoeMoney);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label_MinBet);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 220);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(600, 182);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Betting Parlor";
            // 
            // numericUpDown_Dog
            // 
            this.numericUpDown_Dog.Location = new System.Drawing.Point(359, 151);
            this.numericUpDown_Dog.Name = "numericUpDown_Dog";
            this.numericUpDown_Dog.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown_Dog.TabIndex = 7;
            // 
            // numericUpDown_Bet
            // 
            this.numericUpDown_Bet.Location = new System.Drawing.Point(129, 153);
            this.numericUpDown_Bet.Name = "numericUpDown_Bet";
            this.numericUpDown_Bet.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown_Bet.TabIndex = 6;
            // 
            // button_race
            // 
            this.button_race.Font = new System.Drawing.Font("Gulim", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.button_race.Location = new System.Drawing.Point(488, 138);
            this.button_race.Name = "button_race";
            this.button_race.Size = new System.Drawing.Size(106, 35);
            this.button_race.TabIndex = 5;
            this.button_race.Text = "Race ";
            this.button_race.UseVisualStyleBackColor = true;
            this.button_race.Click += new System.EventHandler(this.button1_Click);
            // 
            // button_Bet
            // 
            this.button_Bet.Location = new System.Drawing.Point(48, 151);
            this.button_Bet.Name = "button_Bet";
            this.button_Bet.Size = new System.Drawing.Size(75, 23);
            this.button_Bet.TabIndex = 5;
            this.button_Bet.Text = "Bet";
            this.button_Bet.UseVisualStyleBackColor = true;
            this.button_Bet.Click += new System.EventHandler(this.button_Bet_Click);
            // 
            // radioButton_Al
            // 
            this.radioButton_Al.AutoSize = true;
            this.radioButton_Al.Location = new System.Drawing.Point(9, 109);
            this.radioButton_Al.Name = "radioButton_Al";
            this.radioButton_Al.Size = new System.Drawing.Size(59, 16);
            this.radioButton_Al.TabIndex = 4;
            this.radioButton_Al.TabStop = true;
            this.radioButton_Al.Text = "Al has";
            this.radioButton_Al.UseVisualStyleBackColor = true;
            this.radioButton_Al.CheckedChanged += new System.EventHandler(this.radioButton_Al_CheckedChanged_1);
            // 
            // radioButton_Bob
            // 
            this.radioButton_Bob.AutoSize = true;
            this.radioButton_Bob.Location = new System.Drawing.Point(9, 83);
            this.radioButton_Bob.Name = "radioButton_Bob";
            this.radioButton_Bob.Size = new System.Drawing.Size(70, 16);
            this.radioButton_Bob.TabIndex = 4;
            this.radioButton_Bob.TabStop = true;
            this.radioButton_Bob.Text = "Bob has";
            this.radioButton_Bob.UseVisualStyleBackColor = true;
            this.radioButton_Bob.CheckedChanged += new System.EventHandler(this.radioButton_Bob_CheckedChanged_1);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Gulim", 9F);
            this.label2.Location = new System.Drawing.Point(213, 156);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(129, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "bucks on dog number";
            // 
            // label_nowName
            // 
            this.label_nowName.AutoSize = true;
            this.label_nowName.Font = new System.Drawing.Font("Gulim", 9F);
            this.label_nowName.Location = new System.Drawing.Point(7, 156);
            this.label_nowName.Name = "label_nowName";
            this.label_nowName.Size = new System.Drawing.Size(29, 12);
            this.label_nowName.TabIndex = 3;
            this.label_nowName.Text = "now";
            // 
            // label_AlMoney
            // 
            this.label_AlMoney.AutoSize = true;
            this.label_AlMoney.Font = new System.Drawing.Font("Gulim", 9F);
            this.label_AlMoney.Location = new System.Drawing.Point(357, 113);
            this.label_AlMoney.Name = "label_AlMoney";
            this.label_AlMoney.Size = new System.Drawing.Size(55, 12);
            this.label_AlMoney.TabIndex = 3;
            this.label_AlMoney.Text = "AlMoney";
            // 
            // label_BobMoney
            // 
            this.label_BobMoney.AutoSize = true;
            this.label_BobMoney.Font = new System.Drawing.Font("Gulim", 9F);
            this.label_BobMoney.Location = new System.Drawing.Point(357, 87);
            this.label_BobMoney.Name = "label_BobMoney";
            this.label_BobMoney.Size = new System.Drawing.Size(66, 12);
            this.label_BobMoney.TabIndex = 3;
            this.label_BobMoney.Text = "BobMoney";
            // 
            // radioButton_Joe
            // 
            this.radioButton_Joe.AutoSize = true;
            this.radioButton_Joe.Location = new System.Drawing.Point(9, 56);
            this.radioButton_Joe.Name = "radioButton_Joe";
            this.radioButton_Joe.Size = new System.Drawing.Size(68, 16);
            this.radioButton_Joe.TabIndex = 2;
            this.radioButton_Joe.TabStop = true;
            this.radioButton_Joe.Text = "Joe has";
            this.radioButton_Joe.UseVisualStyleBackColor = true;
            this.radioButton_Joe.CheckedChanged += new System.EventHandler(this.radioButton_Joe_CheckedChanged_1);
            // 
            // Label_JoeMoney
            // 
            this.Label_JoeMoney.AutoSize = true;
            this.Label_JoeMoney.Font = new System.Drawing.Font("Gulim", 9F);
            this.Label_JoeMoney.Location = new System.Drawing.Point(357, 60);
            this.Label_JoeMoney.Name = "Label_JoeMoney";
            this.Label_JoeMoney.Size = new System.Drawing.Size(64, 12);
            this.Label_JoeMoney.TabIndex = 1;
            this.Label_JoeMoney.Text = "JoeMoney";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Gulim", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label3.Location = new System.Drawing.Point(356, 30);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(39, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "Bets";
            // 
            // label_MinBet
            // 
            this.label_MinBet.AutoSize = true;
            this.label_MinBet.Font = new System.Drawing.Font("Gulim", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label_MinBet.Location = new System.Drawing.Point(119, 30);
            this.label_MinBet.Name = "label_MinBet";
            this.label_MinBet.Size = new System.Drawing.Size(23, 13);
            this.label_MinBet.TabIndex = 1;
            this.label_MinBet.Text = "$5";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Gulim", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(6, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(117, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Minimum bet : ";
            // 
            // pictureBox_Dog1
            // 
            this.pictureBox_Dog1.Location = new System.Drawing.Point(19, 21);
            this.pictureBox_Dog1.Name = "pictureBox_Dog1";
            this.pictureBox_Dog1.Size = new System.Drawing.Size(75, 20);
            this.pictureBox_Dog1.TabIndex = 2;
            this.pictureBox_Dog1.TabStop = false;
            // 
            // pictureBox_Dog2
            // 
            this.pictureBox_Dog2.Location = new System.Drawing.Point(19, 73);
            this.pictureBox_Dog2.Name = "pictureBox_Dog2";
            this.pictureBox_Dog2.Size = new System.Drawing.Size(75, 20);
            this.pictureBox_Dog2.TabIndex = 3;
            this.pictureBox_Dog2.TabStop = false;
            // 
            // pictureBox_Dog3
            // 
            this.pictureBox_Dog3.Location = new System.Drawing.Point(19, 125);
            this.pictureBox_Dog3.Name = "pictureBox_Dog3";
            this.pictureBox_Dog3.Size = new System.Drawing.Size(75, 20);
            this.pictureBox_Dog3.TabIndex = 4;
            this.pictureBox_Dog3.TabStop = false;
            // 
            // pictureBox_Dog4
            // 
            this.pictureBox_Dog4.Location = new System.Drawing.Point(19, 181);
            this.pictureBox_Dog4.Name = "pictureBox_Dog4";
            this.pictureBox_Dog4.Size = new System.Drawing.Size(75, 20);
            this.pictureBox_Dog4.TabIndex = 5;
            this.pictureBox_Dog4.TabStop = false;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.numericUpDown1);
            this.groupBox2.Controls.Add(this.button3);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.numericUpDown2);
            this.groupBox2.Controls.Add(this.button1);
            this.groupBox2.Controls.Add(this.button2);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Location = new System.Drawing.Point(618, 14);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(196, 388);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Setting";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Location = new System.Drawing.Point(9, 44);
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown2.TabIndex = 6;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Gulim", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.button1.Location = new System.Drawing.Point(488, 138);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(106, 35);
            this.button1.TabIndex = 5;
            this.button1.Text = "Race ";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(115, 42);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 5;
            this.button2.Text = "Bet";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Gulim", 9F);
            this.label4.Location = new System.Drawing.Point(213, 156);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(129, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "bucks on dog number";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Gulim", 9F);
            this.label7.Location = new System.Drawing.Point(357, 87);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(66, 12);
            this.label7.TabIndex = 3;
            this.label7.Text = "BobMoney";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Gulim", 9F);
            this.label8.Location = new System.Drawing.Point(357, 60);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(64, 12);
            this.label8.TabIndex = 1;
            this.label8.Text = "JoeMoney";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Gulim", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label9.Location = new System.Drawing.Point(356, 30);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(39, 13);
            this.label9.TabIndex = 1;
            this.label9.Text = "Bets";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Gulim", 10F);
            this.label11.Location = new System.Drawing.Point(6, 22);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(88, 14);
            this.label11.TabIndex = 0;
            this.label11.Text = "Minimum bet";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(9, 109);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown1.TabIndex = 9;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(115, 107);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 8;
            this.button3.Text = "Bet";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Gulim", 10F);
            this.label5.Location = new System.Drawing.Point(6, 87);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(78, 14);
            this.label5.TabIndex = 7;
            this.label5.Text = "Dog Count";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(826, 414);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.pictureBox_Dog4);
            this.Controls.Add(this.pictureBox_Dog3);
            this.Controls.Add(this.pictureBox_Dog2);
            this.Controls.Add(this.pictureBox_Dog1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox_Track);
            this.Name = "Form1";
            this.Text = "A Day at the Races";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Track)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Dog)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Bet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Dog4)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_Track;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label_MinBet;
        private System.Windows.Forms.RadioButton radioButton_Joe;
        private System.Windows.Forms.RadioButton radioButton_Bob;
        private System.Windows.Forms.RadioButton radioButton_Al;
        private System.Windows.Forms.Label label_nowName;
        private System.Windows.Forms.Button button_Bet;
        private System.Windows.Forms.NumericUpDown numericUpDown_Bet;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown numericUpDown_Dog;
        private System.Windows.Forms.Button button_race;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox pictureBox_Dog1;
        private System.Windows.Forms.PictureBox pictureBox_Dog2;
        private System.Windows.Forms.PictureBox pictureBox_Dog3;
        private System.Windows.Forms.PictureBox pictureBox_Dog4;
        private System.Windows.Forms.Label label_AlMoney;
        private System.Windows.Forms.Label label_BobMoney;
        private System.Windows.Forms.Label Label_JoeMoney;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label5;
    }
}

