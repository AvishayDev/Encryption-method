#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
using namespace std;

//const numbers for good understanding
int const MIN_CODE = 32;
int const z_ASCII = 122;
int const MAX_CODE = 91;

char deCode(char C, int Rand);
char code(char C, int Rand);
int main()
{
	string TextCoded;
	char handle;
	int choose;
	fstream fileCode;
	//the file with the text to code/decode
	fileCode.open("CodeText.txt");
	
	//key for code/decode
	cout << "Choose Code & deCode Key:\n";
	cin >> choose;
	srand(choose);
	
	//choose code or decode for the text
	//*can be auto for sender and getter
	cout << "Choose 1 for code\nChoose 2 for deCode\n";
	choose = 0;
	while( choose < 1 || choose > 2 )
	{
		cin >> choose;
		switch (choose)
		{
		case 1:
			//read all chars from file and code them
			fileCode.get(handle);
			while (!fileCode.eof())
			{
				TextCoded += code(handle, rand() % MAX_CODE);
				fileCode.get(handle);
			}
			break;
		case 2:
			//read all chars from file and decode them
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
	}
	//close and open the file for write in it
	fileCode.close();
	fileCode.open("CodeText.txt");
	//reset the new text coded/decoded
	fileCode << TextCoded;

	//finish
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


