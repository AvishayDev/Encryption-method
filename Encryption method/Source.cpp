#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
using namespace std;

int const MIN_CODE = 32;
int const z_ASCII = 122;
int const MAX_CODE = 91;

char deCode(char C, int Rand);
char code(char C, int Rand);
int main()
{
	string TextCoded;
	char handle;
	int choose = 1;
	fstream fileCode;
	fileCode.open("CodeText.txt");
	
	cout << "Choose Code & deCode Key:\n";
	cin >> choose;
	srand(choose);

	cout << "Choose 1 for code\nChoose 2 for deCode\n";
	cin >> choose;

	switch (choose)
	{
	case 1:
		fileCode.get(handle);
		while (!fileCode.eof())
		{
			TextCoded += code(handle, rand() % MAX_CODE);
			fileCode.get(handle);
		}
		break;
	case 2:
		fileCode.get(handle);
		while (!fileCode.eof())
		{
			TextCoded += deCode(handle, rand() % MAX_CODE);
			fileCode.get(handle);
		}
		break;
	default:
		cout << "Please Choose only 1 or 2!\n";
		cin >> choose;
		break;
	}

	fileCode.close();
	fileCode.open("CodeText.txt");
	fileCode << TextCoded;


	fileCode.close();
	//system("pause");
	return 0;

}

char deCode(char C, int Rand)
{
	return C - Rand < MIN_CODE ? C - Rand + MAX_CODE : C - Rand;

}
//code the chars by random number
char code(char C, int Rand)
{
	//if over 'z' return to 'A'
	return C + Rand > z_ASCII ? C + Rand - MAX_CODE : C + Rand;
}


