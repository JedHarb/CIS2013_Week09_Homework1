#include<iostream>
#include<fstream>
#include<cstring> //page 459 is a list of c functions.
#include<string> 
using namespace std;

int main() {

	int encryptionFile = 0;
	char keepAlive = 'y';
	//When the application is run…
	//	Application asks for a filename to load
	//	Player enters a filename(ex: leve1.dat) and the application loads the file if available, or requests another filename if not available.
	//	The file should contain 10 lines of 50 characters each containing a random assortment of a - z characters plus the space character


	ifstream in_a;

	//get the encryptionFile, close the program if the file is inaccessible
	cout << "Which random encryption file do you want to open? Type 1, 2 or 3: ";
	cin >> encryptionFile;
	switch (encryptionFile) {
	case 1:
		in_a.open("1.dat");
		break;
	case 2:
		in_a.open("2.dat");
		break;
	case 3:
		in_a.open("3.dat");
		break;
	default:
		cout << "Sorry, I didn't get that. Defaulting to encryptionFile 1." << endl;
		in_a.open("1.dat");
	}
	if (in_a.fail()) {
		cout << "Unable to read file, the program will now close." << endl;
		cin >> keepAlive; //keep the program from closing the window until the user inputs something
		exit(1);
	}


	return 0;
}
