#include<iostream>
#include<fstream>
#include<cstring> //page 459 is a list of c functions.
#include<string> 
using namespace std;

int main() {

	bool validEncryptionFile = false;
	int encryptionFile = 0;
	char keepAlive = 'y';
	//When the application is run…
	//	Application asks for a filename to load
	//	Player enters a filename(ex: leve1.dat) and the application loads the file if available, or requests another filename if not available.
	//	The file should contain 10 lines of 50 characters each containing a random assortment of a - z characters plus the space character

	ifstream in_a;
	while (validEncryptionFile == false) {
		cout << "Which random encryption file do you want to open? Type 1, 2 or 3: ";
		cin >> encryptionFile;
		while (encryptionFile != 1 && encryptionFile != 2 && encryptionFile != 3) {
			cout << "Sorry, type 1, 2 or 3: ";
			cin >> encryptionFile;
		}
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
			cout << "Something went wrong. Defaulting to encryptionFile 1." << endl;
			in_a.open("1.dat");
		}

		if (in_a.fail()) {
			cout << "Unable to read/find the file, please choose a differnet one." << endl;
		}
		else { 
			validEncryptionFile = true;
		}
	}

	cout << "debug 1";
	in_a.close(); //always close the file when you are done reading it, prevent file corruption
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}
