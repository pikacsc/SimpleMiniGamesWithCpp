#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
};


int main()
{
	/*
	pointer :pointing, normal variable contains value, pointer variable contains memory address,
	all kinds of variable can declare pointer variable, for example, int variable's address should be in
	int pointer variable, all type of pointer variable size are same
	in x86 solution platform, 4byte, in x64, 8byte

	memory address presented by Hexadeciaml

	pointer should have memory address of some variable, so that
	you can control value of the variable, that's the only purpose

	*/
	int a = 100;
	int *pNum; // int type pointer variable a, declaration, * is the key character of pointer variable
	int *pNum2 = &a; //pNum2 has address of variable a, now you can control variable a value

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << endl;

	cout << pNum2 << endl;
	cout << &pNum2 << endl;
	// however * is can be de-reference operator, if you use it with pointer variable, then you can see the value
	cout << *pNum2 << endl; // pNum2 == &a, *pNum2 == *&a == 100
	*pNum2 = 300; // change a value;
	cout << a << endl;


	/*
	array identifier is pointer
	array identifier is starting memory address
	*/

	int b[10] = { 1,2,3,4,5,6,7,8,9,10 }; // 40byte,
	cout << "b : " << b << endl;
	cout << "&b : " << &b << endl;
	cout << "&b[0] : " << &b[0] << endl;

	// you can assign array itself, cause array identifier is start address of the array
	int *pArray = b; //now you can control the array b

	cout << pArray[2] << endl; //b[2]

	/*
	pointer operating :you can do +, -, ++, --
	int * a
	*/
	cout << pArray + 1 << endl;
	cout << pArray + 2 << endl;
	cout << pArray + 3 << endl;
	cout << pArray + 4 << endl;
	cout << pArray + 5 << endl;
	cout << pArray + 6 << endl;


	const char *pText = "Test String";

	cout << pText << endl;
	cout << (int*)pText << endl;

	cout << endl;

	const char *pText2 = "Test String"; // same with pText, because it's a

	cout << pText2 << endl;
	cout << (int*)pText2 << endl;

	cout << endl;

	const char *pText3 = "Test String "; // different with above 

	cout << pText3 << endl;
	cout << (int*)pText3 << endl;

	cout << endl;


	char str[] = "Test String";
	cout << str << endl;
	cout << (int*)str << endl;

	cout << endl;


	char str2[] = "Test String";
	cout << str2 << endl;
	cout << (int*)str2 << endl;

	cout << endl;


	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent *pStudent = &tStudent;

	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;






	return 0;
}