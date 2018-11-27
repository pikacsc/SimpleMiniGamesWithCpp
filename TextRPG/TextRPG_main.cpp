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


enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};


enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};


#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPONE_MAX 3
#define STORE_ARMOR_MAX 3
struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem tItem[INVENTORY_MAX];
	int		iItemCount;
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
	
	//construct store item list
	_tagItem tStoreWeapon[STORE_WEAPONE_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	//set item info
	strcpy_s(tStoreWeapon[0].strName, "Doran Blade");
	strcpy_s(tStoreWeapon[0].strTypeName, "Blade");
	strcpy_s(tStoreWeapon[0].strDesc, "This doran blade is pretty normal but quite useful.");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 2;
	tStoreWeapon[0].iMax = 5;
	tStoreWeapon[0].iPrice = 5000;
	tStoreWeapon[0].iSell = 3000;

	strcpy_s(tStoreWeapon[1].strName, "Sin Orb");
	strcpy_s(tStoreWeapon[1].strTypeName, "Orb");
	strcpy_s(tStoreWeapon[1].strDesc, "Shining and beautiful Orb for Wizard but even Knight can use it.");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 3;
	tStoreWeapon[1].iMax = 50;
	tStoreWeapon[1].iPrice = 50000;
	tStoreWeapon[1].iSell = 30000;


	strcpy_s(tStoreWeapon[2].strName, "Chaos Axe");
	strcpy_s(tStoreWeapon[2].strTypeName, "Axe");
	strcpy_s(tStoreWeapon[2].strDesc, "Sharp and heavy Axe.");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 10;
	tStoreWeapon[2].iMax = 20;
	tStoreWeapon[2].iPrice = 7000;
	tStoreWeapon[2].iSell = 5000;



	strcpy_s(tStoreArmor[0].strName, "Chain Mail");
	strcpy_s(tStoreArmor[0].strTypeName, "Armor");
	strcpy_s(tStoreArmor[0].strDesc, "light but firm armor");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 5;
	tStoreArmor[0].iMax = 8;
	tStoreArmor[0].iPrice = 2000;
	tStoreArmor[0].iSell = 1000;

	strcpy_s(tStoreArmor[1].strName, "Field Plate");
	strcpy_s(tStoreArmor[1].strTypeName, "Armor");
	strcpy_s(tStoreArmor[1].strDesc, "Nice quality armor");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 3000;
	tStoreArmor[1].iSell = 2000;

	strcpy_s(tStoreArmor[2].strName, "Gothic Plate");
	strcpy_s(tStoreArmor[2].strTypeName, "Armor");
	strcpy_s(tStoreArmor[2].strDesc, "Heavy, firm, Good quality armor");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 40;
	tStoreArmor[2].iMax = 50;
	tStoreArmor[2].iPrice = 50000;
	tStoreArmor[2].iSell = 10000;


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
			while (1)
			{
				system("cls");
				cout << "================= store =================" << endl;
				cout << "1. weapon store" << endl;
				cout << "2. armor store" << endl;
				cout << "3. back" << endl;
				cout << "select store : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (1)
					{
						system("cls");

						//show selling items
						cout << "================= weapon store =================" << endl;
						for (int i = 0; i < STORE_WEAPONE_MAX; ++i)
						{
							cout << i + 1 << "." << tStoreWeapon[i].strName << "\t type : " << tStoreWeapon[i].strTypeName << endl;
							cout << "plus damage : " << tStoreWeapon[i].iMin << "-" << tStoreWeapon[i].iMax << endl;
							cout << "original price : " << tStoreWeapon[i].iPrice << "G" << "\tPurchase : " << tStoreWeapon[i].iSell << "G"<< endl;
							cout << tStoreWeapon[i].strDesc << endl;
							cout << endl;
						}
						cout << STORE_WEAPONE_MAX + 1 << ".go Back to store menu" << endl;
						cout << endl;
						cout << "Inventory Gold : " << tPlayer.tInventory.iGold << "G" << endl;
						cout << "Inventory space : " << tPlayer.tInventory.iItemCount << "/" << INVENTORY_MAX << endl;
						cout << "Select item to purchase : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_WEAPONE_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPONE_MAX + 1)
						{
							cout << "Wrong input." << endl;
							system("pause");
							continue;
						}

						
						int iWeaponIndex = iMenu - 1;


						//Check inventory is full
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "Inventory is full." << endl;
							system("pause");
							continue;
						}

						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "Not enough Gold." << endl;
							system("pause");
							continue;
						}

						//when purchase item, item go to inventory[0], count become 1 and 
						//next purchase item go to inventory[1]
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreWeapon[iWeaponIndex];
						++tPlayer.tInventory.iItemCount;

						//decrease Gold
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " purchased." << endl;
						system("pause");
					}
					break;
				case SM_ARMOR:
					while (1)
					{
						system("cls");

						//show selling items
						cout << "================= armor store =================" << endl;
						for (int i = 0; i < STORE_ARMOR_MAX; ++i)
						{
							cout << i + 1 << "." << tStoreArmor[i].strName << "\t type : " << tStoreArmor[i].strTypeName << endl;
							cout << "plus damage : " << tStoreArmor[i].iMin << "-" << tStoreArmor[i].iMax << endl;
							cout << "original price : " << tStoreArmor[i].iPrice << "G" << "\tPurchase : " << tStoreArmor[i].iSell << "G" << endl;
							cout << tStoreArmor[i].strDesc << endl;
							cout << endl;
						}
						cout << STORE_ARMOR_MAX + 1 << ".go Back to store menu" << endl;
						cout << endl;
						cout << "Inventory Gold : " << tPlayer.tInventory.iGold << "G" << endl;
						cout << "Inventory space : " << tPlayer.tInventory.iItemCount << "/" << INVENTORY_MAX << endl;
						cout << "Select item to purchase : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
						{
							cout << "Wrong input." << endl;
							system("pause");
							continue;
						}


						int iArmorIndex = iMenu - 1;


						//Check inventory is full
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "Inventory is full." << endl;
							system("pause");
							continue;
						}

						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "Not enough Gold." << endl;
							system("pause");
							continue;
						}

						//when purchase item, item go to inventory[0], count become 1 and 
						//next purchase item go to inventory[1]
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreArmor[iArmorIndex];
						++tPlayer.tInventory.iItemCount;

						//decrease Gold
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << " purchased." << endl;
						system("pause");
					}
					break;
				}
			}
			break;
		case MM_INVENTORY:
			system("cls");
			cout << "************************ inventory ************************" << endl;
			cout << "======================= Player =======================" << endl;
			cout << "name : " << tPlayer.strName << "\tJob : " << tPlayer.strJobName << endl;
			cout << "level : " << tPlayer.iLevel << "\tExp : " << tPlayer.iExp << endl;
			cout << "Attack : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << endl;
			cout << "Defense : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
			cout << "HP : " << tPlayer.iHP << "/" << tPlayer.iHPMax << "\tMP : " << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;
			cout << "Gold : " << tPlayer.tInventory.iGold << "G" << endl;
			if (tPlayer.tInventory.iItemCount == 0)
			{
				cout << "You have no item in inventory" << endl;
				system("pause");
				break;
			}
			for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i)
			{
				cout << i + 1 << "." << tPlayer.tInventory.tItem[i].strName << "\t" << tPlayer.tInventory.tItem[i].strTypeName << endl;
				cout << "plus damage : " << tPlayer.tInventory.tItem[i].iMin << "-" << tPlayer.tInventory.tItem[i].iMax << endl;
				cout << tPlayer.tInventory.tItem[i].strDesc << endl;
				cout << endl;
			}
			system("pause");
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

