#include <iostream>
#include <random>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK

};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};


enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SIZE 32

struct _tagInventory
{
	int		iGold;

};


struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	_tagInventory tInventory;
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};


int GetRandomNumber(const int& a, const int& b);

int main()
{
	_tagPlayer tPlayer = {};

	//get player name
	cout << "player name : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);// NAME_SIZE-1 : To add NULL at the end

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. Knight" << endl;
		cout << "2. Archer" << endl;
		cout << "3. Wizard" << endl;
		cout << "Select character's class : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;

	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "Knight");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "Archer");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "Wizard");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break; 
	}

	//construct Monster
	_tagMonster tMonsterArr[MT_BACK - 1] = {};


	//Goblin
	strcpy_s(tMonsterArr[0].strName, "Goblin");
	tMonsterArr[0].iArmorMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	//Troll
	strcpy_s(tMonsterArr[1].strName, "Troll");
	tMonsterArr[1].iArmorMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	//Troll
	strcpy_s(tMonsterArr[2].strName, "Dragon");
	tMonsterArr[2].iArmorMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;


	while (1)
	{
		cout << "================= LOBBY =================" << endl;
		system("cls");
		cout << "1. map" << endl;
		cout << "2. store" << endl;
		cout << "3. inventory" << endl;
		cout << "4. exit" << endl;
		cout << "select menu : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (1)
			{
				system("cls");
				cout << "================= MAP =================" << endl;
				cout << "1. easy" << endl;
				cout << "2. normal" << endl;
				cout << "3. hard" << endl;
				cout << "4. go back" << endl;
				cout << "select map : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MT_BACK) //To go back to main menu
					break;


				//selected menu -1 == tMonsterArr index
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (1)
				{
					system("cls");
					switch (iMenu)
					{
					case MT_EASY:
						cout << "================= Easy ===================" << endl;
						break;
					case MT_NORMAL:
						cout << "================= Normal =================" << endl;
						break;
					case MT_HARD:
						cout << "================== Hard ==================" << endl;
						break;
					}

					//print player info
					cout << "======================= Player =======================" << endl;
					cout << "name : " << tPlayer.strName << "\tJob : " << tPlayer.strJobName << endl;
					cout << "level : " << tPlayer.iLevel << "\tExp : " << tPlayer.iExp << endl;
					cout << "Attack : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << endl;
					cout << "Defense : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "HP : " << tPlayer.iHP << "/" << tPlayer.iHPMax << "\tMP : " << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;
					cout << "Gold : " << tPlayer.tInventory.iGold << "G" << endl;
					cout << endl;

					//print monster info
					cout << "======================= Monster =======================" << endl;
					cout << "name : " << tMonster.strName << endl;
					cout << "level : " << tMonster.iLevel << endl;
					cout << "Attack : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax << endl;
					cout << "Defense : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "HP : " << tMonster.iHP << "/" << tMonster.iHPMax << "\tMP : " << tMonster.iMP << "/" << tMonster.iMPMax << endl;
					cout << "obtain Exp : " << tMonster.iExp << "\tobtain Gold : " << tMonster.iGoldMin << "/" << tMonster.iGoldMax << endl;
					cout << endl;

					cout << "1.Attack" << endl;
					cout << "2.Run" << endl;
					cout << "select menu : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
						int iAttack = GetRandomNumber(tPlayer.iAttackMin, tPlayer.iAttackMax);
						int iArmor = GetRandomNumber(tMonster.iArmorMin, tMonster.iArmorMax);
						int iDamage = iAttack - iArmor;
						iDamage = (iDamage < 1) ? 1 : iDamage; // minimum damage


						//Decrease monster HP
						tMonster.iHP -= iDamage;
						cout << tPlayer.strName << " attacked " << tMonster.strName << endl;
						cout << iDamage << "damage!" << endl;

						//when monster died
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " died" << endl;
							tPlayer.iExp += tMonster.iExp;
							int iGold = GetRandomNumber(tMonster.iGoldMin, tMonster.iGoldMax);
							tPlayer.tInventory.iGold += iGold;
							cout << tMonster.iExp << "exp obtained." << endl;
							cout << iGold << "G obtained" << endl;


							//reset Monster HP,MP
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}


						//Monster attack
						iAttack = GetRandomNumber(tMonster.iAttackMin, tMonster.iAttackMax);
						iArmor = GetRandomNumber(tPlayer.iArmorMin, tPlayer.iArmorMax);
						iDamage = iAttack - iArmor;
						iDamage = (iDamage < 1) ? 1 : iDamage; // minimum damage


						//Decrease player HP
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " attacked " << tPlayer.strName << endl;
						cout << iDamage << "damage!" << endl;

						//when player died
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " died" << endl;
							int iExp = static_cast<int>(tPlayer.iExp * 0.1f);
							int iGold = static_cast<int>(tPlayer.tInventory.iGold * 0.1f);
							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << "exp lost " << endl;
							cout << iGold << "G lost" << endl;

							//reset player HP,MP 
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
				}
					break;	
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "Wrong input, please try again" << endl;
			break;
		}
	}

	return 0;
}

//return random number from int a to int b
int GetRandomNumber(const int& a,const int& b)
{
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(a, b);
	return dice(mersenne);
}

