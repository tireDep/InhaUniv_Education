using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace DogRace
{
    public partial class Form1 : Form
    {
        Random _randomizer;
        Dog[] _hounds;
        Guy[] _guys;

        public Form1()
        {
            InitializeComponent();

            _randomizer = new Random();

            _hounds = new Dog[4];
            _hounds[0] = new Dog() { StartingPosition = 31, RacetrackLength = 550, Location = 31, MyPictureBox = pictureBox_Dog1, Randomizer = _randomizer };
            _hounds[1] = new Dog() { StartingPosition = 31, RacetrackLength = 550, Location = 31, MyPictureBox = pictureBox_Dog2, Randomizer = _randomizer };
            _hounds[2] = new Dog() { StartingPosition = 31, RacetrackLength = 550, Location = 31, MyPictureBox = pictureBox_Dog3, Randomizer = _randomizer };
            _hounds[3] = new Dog() { StartingPosition = 31, RacetrackLength = 550, Location = 31, MyPictureBox = pictureBox_Dog4, Randomizer = _randomizer };

            _guys = new Guy[3];
            _guys[0] = new Guy() { Cash = 50, MyRadioButton = radioButton_Joe, Name = "Joe", MyLabel = Label_JoeMoney };
            _guys[1] = new Guy() { Cash = 75, MyRadioButton = radioButton_Bob, Name = "Bob", MyLabel = label_BobMoney };
            _guys[2] = new Guy() { Cash = 45, MyRadioButton = radioButton_Al, Name = "Al", MyLabel = label_AlMoney };
            
            for(int i = 0; i < 3; i++)
            {
                _guys[i].UpdateLabels();
            }

            pictureBox_Track.Load(@"D:\바탕화면\DogRace\DogRace\Image\Track.png");
            pictureBox_Track.SizeMode = PictureBoxSizeMode.StretchImage;

            pictureBox_Dog1.Load(@"D:\바탕화면\DogRace\DogRace\Image\Dog.png");
            pictureBox_Dog1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox_Dog2.Load(@"D:\바탕화면\DogRace\DogRace\Image\Dog.png");
            pictureBox_Dog2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox_Dog3.Load(@"D:\바탕화면\DogRace\DogRace\Image\Dog.png");
            pictureBox_Dog3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox_Dog4.Load(@"D:\바탕화면\DogRace\DogRace\Image\Dog.png");
            pictureBox_Dog4.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void button_Bet_Click(object sender, EventArgs e)
        {
            bool betSuccess;
            int amount = (int)numericUpDown_Bet.Value;
            int dogNum = (int)numericUpDown_Dog.Value;

            if(radioButton_Joe.Checked)
            {
                betSuccess = _guys[0].PlaceBet(amount, dogNum);
                _guys[0].UpdateLabels();
            }
            else if (radioButton_Bob.Checked)
            {
                betSuccess = _guys[1].PlaceBet(amount, dogNum);
                _guys[1].UpdateLabels();
            }
            else if (radioButton_Al.Checked)
            {
                betSuccess = _guys[2].PlaceBet(amount, dogNum);
                _guys[2].UpdateLabels();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool existWinner = false;
            int winner = 0;
            button_Bet.Enabled = false;
            button_race.Enabled = false;

            while(!existWinner)
            {
                for(int i=0;i<4;i++)
                {
                    existWinner = _hounds[i].Run();

                    if(existWinner)
                    {
                        winner = i + 1;
                        break;
                    }
                }

                this.Refresh();
            }

            MessageBox.Show("We have a Winner - Dog #" + winner);

            for(int i=0;i<4;i++)
            {
                _hounds[i].TakeStartingPosition();
            }

            for(int i=0;i<3;i++)
            {
                _guys[i].Collect(winner);
            }

            button_Bet.Enabled = true;
            button_race.Enabled = true;
        }

        private void radioButton_Joe_CheckedChanged_1(object sender, EventArgs e)
        {
            label_nowName.Text = "Joe";
        }

        private void radioButton_Bob_CheckedChanged_1(object sender, EventArgs e)
        {
            label_nowName.Text = "Bob";
        }

        private void radioButton_Al_CheckedChanged_1(object sender, EventArgs e)
        {
            label_nowName.Text = "Al";
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
    } // << : public partial class
}
