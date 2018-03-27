#include<iostream>
#include<fstream>
#include<cstring> //page 459 is a list of c functions.
#include<string> 
using namespace std;

int charToIntValue(char i)
{
	int value = 0;
	switch (i) {
	case 'a':
	case 'A':
		value = 1;
		break;
	case 'b':
	case 'B':
		value = 2;
		break;
	case 'c':
	case 'C':
		value = 3;
		break;
	case 'd':
	case 'D':
		value = 4;
		break;
	case 'e':
	case 'E':
		value = 5;
		break;
	case 'f':
	case 'F':
		value = 6;
		break;
	case 'g':
	case 'G':
		value = 7;
		break;
	case 'h':
	case 'H':
		value = 8;
		break;
	case 'i':
	case 'I':
		value = 9;
		break;
	case 'j':
	case 'J':
		value = 10;
		break;
	case 'k':
	case 'K':
		value = 11;
		break;
	case 'l':
	case 'L':
		value = 12;
		break;
	case 'm':
	case 'M':
		value = 13;
		break;
	case 'n':
	case 'N':
		value = 14;
		break;
	case 'o':
	case 'O':
		value = 15;
		break;
	case 'p':
	case 'P':
		value = 16;
		break;
	case 'q':
	case 'Q':
		value = 17;
		break;
	case 'r':
	case 'R':
		value = 18;
		break;
	case 's':
	case 'S':
		value = 19;
		break;
	case 't':
	case 'T':
		value = 20;
		break;
	case 'u':
	case 'U':
		value = 21;
		break;
	case 'v':
	case 'V':
		value = 22;
		break;
	case 'w':
	case 'W':
		value = 23;
		break;
	case 'x':
	case 'X':
		value = 24;
		break;
	case 'y':
	case 'Y':
		value = 25;
		break;
	case 'z':
	case 'Z':
		value = 26;
		break;
	case ' ':
		value = 27;
		break;
	default:
		cout << "(not a character or space)";
	}
	return value;
}


int main() {

	bool validEncryptionFile = false;
	int encryptionFile = 0;
	char keepAlive = 'y';
	bool validCrypt = false;
	char crypt = 'y';
	string userInput;
	int x = 0;
	char y[500];
	int i = 0;
	int charValue = 0;

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
//	After loading the file, the application will ask if you want to “encrypt” or “decrypt” a message. Depending on the selection the application will :
//  ### Encrpyt
//	The application asks for the message you want to “encrypt.”  The user types in the message.
//		The application will then use file characters as values and add those values to the message characters.  (a = 1, b = 2, c = 3, z = 26, space = 27, etc..)

	while (validCrypt == false) {
		cout << "Type e to Encrypt or type d to Decrypt: ";
		cin >> crypt;
		if (crypt == 'e' || crypt == 'd') {
			validCrypt = true;
		}
	}
	if (crypt == 'e') {
		for (x = 0; x < 500; x++) {
			in_a >> y[x]; //set our array to match the ecryption file
			cout << y[x]; //this is just a test. Currently does not output spaces, even if we set array y to be a string.
		}
		cout << endl << "ENCRYPTION. Please type the message you wish to encrypt: " << endl;
		cin.ignore();
		getline(cin, userInput);
		cout << endl << "That is " << userInput.length() << " characters long." << endl;
		cout << "Your message translated to numbers is: " << endl;
		for (i = 0; i < userInput.length(); i++) {
			charValue = charToIntValue(userInput[i]);
			//charValue = charValue + charToIntValue(); // need to add the value of the user character to the value of the random character from the file
			cout << charValue <<" ";
		} 
	}


	in_a.close(); //always close the file when you are done reading it, prevent file corruption
	cout << " debug 1 ";
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}
