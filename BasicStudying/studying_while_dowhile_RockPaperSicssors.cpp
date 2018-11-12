#include <iostream>
#include <time.h>
#include <random>
using namespace std;

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};


int main()
{
	srand((unsigned int)time(NULL));
	int iNumber = 0;
	int iPlayer = 0;
	int iComputer = 0;


	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(1, 3);


	while (iNumber < 10)
	{
		cout << iNumber++ << endl;
	}

	system("cls");


	cout << "Hello! let's play rock paper scissors" << endl;
	while (1)
	{
		cout << "1.Scissors" << endl;
		cout << "2.Rock" << endl;
		cout << "3.Paper" << endl;
		cout << "4.exit" << endl;
		cout << endl;
		cout << "input the number : ";
		cin >> iPlayer;

		if (iPlayer < SRP::SRP_S || iPlayer > SRP::SRP_END)
		{
			cout << "Wrong input" << endl;
			system("pause");
			continue;
		}

		else if (iPlayer == SRP::SRP_END) break;




		//Computer select
		iComputer = dice(mersenne);

		switch (iComputer)
		{
		case SRP_S:
			cout << "Computer : Scissors" << endl;
			break;
		case SRP_R:
			cout << "Computer : Rock" << endl;
			break;
		case SRP_P:
			cout << "Computer : Paper" << endl;
			break;
		}

		int iWin = iPlayer - iComputer;

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "You win!" << endl;
			break;
		case 0:
			cout << "draw!" << endl;
			break;
		default:
			cout << "Computer win!, you lose!" << endl;
			break;
		}
	}

	return 0;
}
