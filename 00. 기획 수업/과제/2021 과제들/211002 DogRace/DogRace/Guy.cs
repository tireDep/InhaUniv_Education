using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DogRace
{
    class Guy
    {
        public string Name;
        public Bet MyBet;
        public int Cash;

        public RadioButton MyRadioButton;
        public Label MyLabel;

        public void UpdateLabels()
        {
            MyRadioButton.Text = Name + " has " + Cash + " bucks";

            if (MyBet != null)
                MyLabel.Text = MyBet.GetDescription();
        }

        public void ClearBet()
        {
            MyBet = null;
            UpdateLabels();
        }

        public bool PlaceBet(int Amount, int Dog)
        {
            if (Amount > Cash || MyBet != null)
                return false;

            MyBet = new Bet()
            {
                Amount = Amount,
                Dog = Dog,
                Bettor = this
            };

            Cash -= Amount;
            UpdateLabels();

            return true;
        }

        public void Collect(int Winner)
        {
            if (MyBet != null)
                Cash += MyBet.PayOut(Winner);

            ClearBet();
        }
    }
}
