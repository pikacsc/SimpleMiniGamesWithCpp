#include <iostream>
#include <random>

using namespace std;
enum AI_MODE
{
	EASY = 1,
	HARD = 2
};

enum LINE_NUMBER
{
	H1,
	H2,
	H3,
	H4,
	H5,
	V1,
	V2,
	V3,
	V4,
	V5,
	LT,
	RT,
};

#define X INT_MAX // marking

int GetRandomNumber(const int &iBegin, const int &iEnd);

int main()
{


	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	
	//Number Shuffling
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = GetRandomNumber(0, 24);
		idx2 = GetRandomNumber(0, 24);
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		idx1 = GetRandomNumber(0, 24);
		idx2 = GetRandomNumber(0, 24);
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAiMode;
	//choose game level(AI level)
	while (1)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "Choose game difficulty level : ";

		cin >> iAiMode;

		if (iAiMode >= AI_MODE::EASY && iAiMode <= AI_MODE::HARD)
			break;
	}



	/*
	AI Easy mode : AI select numbers in unmarked numbers randomly
	
	*/
	int iNoMark[25] = {};

	//store unmarked numbers
	int iNoMarkCount = 0;


	while (1)
	{
		system("cls");

		//print numbers with 5x5 size table 
		cout << "================== Player =================" << endl;
		for (int i = 0; i < 5; ++i)
		{ 
			for (int j = 0; j < 5; ++j)
			{ 
				if (iNumber[i * 5 + j] == X)
					cout << "X\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		
		cout << "Bing Line : "<< iBingo << endl << endl;

		cout << "=================== AI ====================" << endl;

		switch (iAiMode)
		{
		case AI_MODE::EASY:
			cout << "Easy Mode" << endl;
			break;
		case AI_MODE::HARD:
			cout << "Hard Mode" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == X)
					cout << "X\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "AI Bingo Line : " << iAIBingo << endl << endl;

		//Quit game at five Bingo Line
		if (iBingo >= 5)
		{
			cout << "Player Win!" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI Win!" << endl;
			break;
		}

		cout << "please input number(0 : quit game) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;


		//bool for checking called number or not
		//default : true(called already)
		bool bAcc = true; 


		//checking every numbers to find out called number
		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i]) 
			{
				bAcc = false; //the number has not been called yet, so false

				//for marking, assign special value INT_MAX
				iNumber[i] = X;
				break;
			}
		}

		if (bAcc)
			continue;

		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = X;
				break;
			}
		}

		//AI number calling(marking)
		switch (iAiMode)
		{
		case AI_MODE::EASY:
			// make unmarked number list
			iNoMarkCount = 0;
			for (int i = 0; i < 25; ++i)
			{
				if (iAINumber[i] != X)
				{
					iNoMark[iNoMarkCount] = iAINumber[i]; //you can use iNoMarkCount as an index of iNoMark[]
					++iNoMarkCount;
				}
			}
			iInput = iNoMark[GetRandomNumber(0, iNoMarkCount)];

			break;
		case AI_MODE::HARD:
			// AI will mark the number in the line which has most high possibility to become Bingo
			int iLine = 0;
			int iMarkCount = 0;
			int iSaveCount = 0;

			// find the row line which has many X(mark)
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == X)
						++iMarkCount;
				}

				// X should be lower then 5 cause it shouldn't be Bingo yet
				if (iMarkCount < 5 && iSaveCount < iMarkCount)
				{
					iLine = i;
					iSaveCount = iSaveCount;
				}
			}

			// after find the row line, compare with column line
			for (int i = 0; i < 5; ++i)
			{
				iMarkCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[j * 5 + i] == X)
						++iMarkCount;
				}

				if (iMarkCount < 5 && iSaveCount < iMarkCount)
				{
					iLine = i + 5;
					iSaveCount = iMarkCount;
				}
			}

			iMarkCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == X)
					++iMarkCount;
			}
			if (iMarkCount < 5 && iSaveCount < iMarkCount)
			{
				iLine = LINE_NUMBER::LT;
				iSaveCount = iMarkCount;
			}

			iMarkCount = 0;
			for (int i = 4; i < 20; i+=4)
			{
				if (iAINumber[i] == X)
					++iMarkCount;
			}
			if (iMarkCount < 5 && iSaveCount < iMarkCount)
			{
				iLine = LINE_NUMBER::RT;
				iSaveCount = iMarkCount;
			}

			//finally, in iLine, line number which has most high possibility to become Bingo
			//now select numbers in that line
			// in row line
			if (iLine <= LINE_NUMBER::H5)
			{
				//iLine 0 ~ 4
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[iLine * 5 + i] != X)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LINE_NUMBER::V5) // column line
			{
				//iLine 5 ~ 9
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != X)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LINE_NUMBER::LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != X)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine == LINE_NUMBER::RT)
			{
				for (int i = 4; i <= 20; i += 4)
				{
					if (iAINumber[i] != X)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		dafault:
			break;
		}


		//AI selected 
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = X;
				break;
			}
		}

		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = X;
				break;
			}
		}



		//Every time input the number, checking Bingo Line again
		iBingo = 0; //so intialize Bingo line to 0 
		iAIBingo = 0;

		int iMark1 = 0, iMark2 = 0;
		int iAIMark1 = 0, iAIMark2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			iMark1 = iMark2 = 0;
			iAIMark1 = iAIMark2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//checking X, in rows
				if (iNumber[i * 5 + j] == X)
					++iMark1;

				//checking X, in columns
				if (iNumber[j * 5 + i] == X)
					++iMark2;

				//AI
				if (iAINumber[i * 5 + j] == X)
					++iAIMark1;

				if (iAINumber[j * 5 + j] == X)
					++iAIMark2;
			}

			if (iMark1 == 5)
				++iBingo;
			if (iMark2 == 5)
				++iBingo;
			if (iAIMark1 == 5)
				++iAIBingo;
			if (iAIMark2 == 5)
				++iAIBingo;
		}

		// checking diagonal Bingo Line
		iMark1 = 0;
		iAIMark1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == X)
				++iMark1;
			if (iAINumber[i] == X)
				++iAIMark1;
		}
		if (iMark1 == 5)
			++iBingo;

		if (iAIBingo == 5)
			++iAIBingo;

		iMark1 = 0;
		iAIMark1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == X)
				++iMark1;
			if (iAINumber[i] == X)
				++iAIMark1;
		}
		if (iMark1 == 5)
			++iBingo;
		if (iAIMark1 == 5)
			++iBingo;

	}


	return 0;
}

int GetRandomNumber(const int &iBegin, const int &iEnd)
{
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(iBegin, iEnd);
	return dice(mersenne);
}