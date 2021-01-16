using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheQuest
{
    class Weapon
    {
        private string name = "";
        public string WeaponName
        {
            get { return name; }
        }

        private int range;
        public int WeaponRange
        {
            get { return range; }
            set { range = value; }
        }

        private int demage;
        public int WeaponDamage
        {
            get { return demage; }
            set { demage = value; }
        }

        private int recovery;
        public int WeaponRecovery
        {
            get { return recovery; }
            set { recovery = value; }
        }

        public Weapon(int _demage = 1, int _range = 10, string weaponName = "Bow")
        {
            demage = _demage;
            range = _range;
            name = weaponName;
        }
    }
}
