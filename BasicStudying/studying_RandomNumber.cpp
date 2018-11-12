// execution processing : compile-> build -> execution
// compile : translate to low level language(binary code)

//Build : Ctrl + Shift + B 

#include <iostream> //#include ¢º preprocessor, for including header file in code before compiling
#include <time.h>
#include <random>

// main() function 
int main()
{
	// std : most of c++ standard functions are in "std" namespace from iostream header file
	// namespace : scope for anti duplicate name
	// cout : Console OUTput, print on console

	std::cout << "Test Output" << std::endl;


	using namespace std;

	cout << "after using namespace std; then you can omit std::" << endl;

	const int iAttack = 0x00000001; // 1
	const int iArmor = 0x00000002; // 10
	const int iHP = 0x00000004; //100
	const int iMP = 0x00000008; // 1000
	const int iCritical = 0x00000010;//10000

	  //1 | 100  == 101 | 10000 == 10101
	int iBuf = iAttack | iHP | iCritical;


	// 10101 & 00001 = 10110
	cout << "Attack : " << (iBuf & iAttack) << endl;

	// 10101 & 00010 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << endl;


	//make random number table
	srand((unsigned int)time(0));

	cout << (rand() % 101) << endl; // 0~100
	cout << (rand() % 101 + 100) << endl; //100~200
	cout << (rand() % 10000 / 100.f) << endl;


	int iUpgrade = 0;
	cout << "input the base number of Upgrade : ";
	cin >> iUpgrade;


	//inchant 
	float fPercent = rand() % 10000 / 100.f;

	//upgrade 0~3 : 100%
	//4~6: 40%
	//7~9: 10%
	//10~13: 1%
	//14~15: 0.01%




	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "inchant success!" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "inchant success!" << endl;
		else
			cout << "inchant fail..." << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "inchant success!" << endl;
		else
			cout << "inchant fail..." << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "inchant success!" << endl;
		else
			cout << "inchant fail..." << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "inchant success!" << endl;
		else
			cout << "inchant fail..." << endl;
	}



	//<random>, recommended way
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(1, 25);
	cout << dice(mersenne) << endl;

	return 0;
}

