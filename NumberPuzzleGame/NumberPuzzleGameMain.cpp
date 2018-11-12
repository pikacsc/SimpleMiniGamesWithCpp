#include <iostream>
#include <random>

#include <conio.h>// get Key input in console 
using namespace std;


int GetRandomNumber(const int &iBegin, const int &iEnd);


enum KEY_INPUT
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	HOLD = 104,
	RELEASE = 114
};


int main()
{

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	//last index number will be special number, INT_MAX
	iNumber[24] = INT_MAX;

	//star position 
	int iStarIndex = 24;



	//shuffling from 1 to 24, except 25,

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = GetRandomNumber(0, 23);
		idx2 = GetRandomNumber(0, 23);

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}


	while (1)
	{
		system("cls");
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{

				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					// when i == 0, j == 0 ~ 4, 0*5+(0~4) so index will be 0, 1, 2, 3, 4
					// when i == 1, j == 0 ~ 4, 1*5+(0~4) so index will be 5, 6, 7, 8, 9
					// when i == 2, j == 0 ~ 4, 2*5+(0~4) so index will be 10, 11, 12, 13, 14
					// when i == 3, j == 0 ~ 4, 3*5+(0~4) so index will be 15, 16, 17, 18, 19
					// when i == 4, j == 0 ~ 4, 4*5+(0~4) so index will be 20, 21, 22, 23, 24
					// columnindex * rowCount + rowindex
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}


		bool bWin = true;

		//checking solved or not
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "Congratulation! You solved puzzle!" << endl;
			break;
		}


		cout << "     UP : ก่" << endl;;
		cout << "LEFT : ก็    กๆ : RIGHT" << endl;
		cout << "   DOWN : ก้" << endl;
		cout << "Q : Quit Game";

		// _getch() is get one char only, you don't need "Enter"
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q')
			break;
		switch (cInput)
		{
		case KEY_INPUT::UP:
		case 'w':
		case 'W':
			//most top position, it shouldn't go above, make a wall
			if (iStarIndex <= 4) continue;
			//current star position, assign above number
			iNumber[iStarIndex] = iNumber[iStarIndex - 5];

			//at the above, assign INT_MAX(*), so swap both
			iNumber[iStarIndex - 5] = INT_MAX;

			//Star goes to index 20, so it should be iStarIndex - 5;
			iStarIndex -= 5;
			break;

		case KEY_INPUT::DOWN:
		case 's':
		case 'S':
			if (iStarIndex > 20) continue; //make a wall
			iNumber[iStarIndex] = iNumber[iStarIndex + 5];
			iNumber[iStarIndex + 5] = INT_MAX;
			iStarIndex += 5;
			break;

		case KEY_INPUT::LEFT:
		case 'a':
		case 'A':
			if (iStarIndex % 5 == 0) continue;
			iNumber[iStarIndex] = iNumber[iStarIndex - 1];
			iNumber[iStarIndex - 1] = INT_MAX;
			iStarIndex -= 1;
			break;

		case KEY_INPUT::RIGHT:
		case 'd':
		case 'D':
			if ((iStarIndex + 1) % 5 == 0) continue;
			iNumber[iStarIndex] = iNumber[iStarIndex + 1];
			iNumber[iStarIndex + 1] = INT_MAX;
			iStarIndex += 1;
			break;

		default:
			continue;
		}
	}
	cout << endl << "Quit the game, Good Bye~" << endl;


	return 0;
}


int GetRandomNumber(const int &iBegin, const int &iEnd)
{
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(iBegin, iEnd);
	return dice(mersenne);
}