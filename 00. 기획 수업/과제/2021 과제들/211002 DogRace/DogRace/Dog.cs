using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DogRace
{
    class Dog
    {
        public int StartingPosition;
        public int RacetrackLength;
        public PictureBox MyPictureBox = null;
        public int Location = 0;
        public Random Randomizer;

        public bool Run()
        {
            int move = Randomizer.Next(4) + 1;
            Location += move;
            MyPictureBox.Location = new System.Drawing.Point(StartingPosition + Location, MyPictureBox.Location.Y);

            if (Location > RacetrackLength - StartingPosition)
                return true;
            else
                return false;
        }

        public void TakeStartingPosition()
        {
            MyPictureBox.Location = new System.Drawing.Point(StartingPosition, MyPictureBox.Location.Y);
            Location = 0;
        }


    } // << : Dog
}
