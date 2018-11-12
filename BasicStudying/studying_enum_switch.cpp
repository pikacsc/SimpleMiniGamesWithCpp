#include <iostream>

#define NUM_4 4

using namespace std;



enum NUM
{
	NUM_0, //if you don't input the name specifically then, automatically assign to 0 ~ 1
	NUM_1,
	NUM_2,
	NUM_3
};

int main()
{
	/*
	switch : check the value instead of condition

	switch(variable)
	{
		case num1:
			break;
		case num2:
			break;
		default:
			break;
	}
	*/

	int iNumber;
	cout << "input the number : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_1: //use enum instead of 0~ 1(number)
		cout << "input number is 1" << endl;
		break;
	case NUM_2:
		cout << "input number is 2" << endl;
		break;
	case NUM_4:
		cout << "input number is 4" << endl;
		break;
	default:
		cout << "You didn't input propery";
		break;
	}

	//Enumeration : put the name on specific number
	//enum can be similiar like personal class type

	NUM eNUM; //enum variable size is 4byte

	cout << typeid(eNUM).name() << endl;

	return 0;
}