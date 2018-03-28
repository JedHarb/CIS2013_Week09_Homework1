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
		cout << "(you typed something that isn't character or space)";
	}
	return value;
}

char intValueToChar(int i) {
	char x = 'a';
	switch (i) {
	case 1:
		x = 'a';
		break;
	case 2:
		x = 'b';
		break;
	case 3:
		x = 'c';
		break;
	case 4:
		x = 'd';
		break;
	case 5:
		x = 'e';
		break;
	case 6:
		x = 'f';
		break;
	case 7:
		x = 'g';
		break;
	case 8:
		x = 'h';
		break;
	case 9:
		x = 'i';
		break;
	case 10:
		x = 'j';
		break;
	case 11:
		x = 'k';
		break;
	case 12:
		x = 'l';
		break;
	case 13:
		x = 'm';
		break;
	case 14:
		x = 'n';
		break;
	case 15:
		x = 'o';
		break;
	case 16:
		x = 'p';
		break;
	case 17:
		x = 'q';
		break;
	case 18:
		x = 'r';
		break;
	case 19:
		x = 's';
		break;
	case 20:
		x = 't';
		break;
	case 21:
		x = 'u';
		break;
	case 22:
		x = 'v';
		break;
	case 23:
		x = 'w';
		break;
	case 24:
		x = 'x';
		break;
	case 25:
		x = 'y';
		break;
	case 26:
		x = 'z';
		break;
	case 27:
		x = ' ';
		break;
	default:
		cout << "You shouldn't see this";
	}
	return x;
}

int main() {

	bool validEncryptionFile = false;
	int encryptionFile = 0;
	char keepAlive = 'y';
	bool validCrypt = false;
	bool programContinue = true;
	char crypt = 'y';
	string userInput;
	int x = 0;
	char matchFile[500];
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

	for (i = 0; i < 500; i++) { //set our array to match the one time pad
		in_a >> matchFile[i];
		//cout << matchFile[i]; //verify output. I spent 4 hours trying to make this work with the blank space character and failed. Gotta cut my losses and move on at some point. Setting all .dat file text to alphabetic-only and modulus 26 later on.
	}



	while (programContinue == true) {

		while (validCrypt == false) {
			cout << "Type e to Encrypt, type d to Decrypt, or type x to exit: ";
			cin >> crypt;
			if (crypt == 'e' || crypt == 'd' || crypt == 'x') {
				validCrypt = true;
			}
		}

		if (crypt == 'e') {
			cout << endl << "ENCRYPTION. Please type the message you wish to encrypt. Letters and spaces only, and under 500 characters please or this thing will break: " << endl;
			cin.ignore();
			getline(cin, userInput);
			// cout << endl << "That is " << userInput.length() << " characters long." << endl; //legnth test
			cout << "Encryption complete. Your new message is: " << endl;
			for (i = 0; i < userInput.length(); i++) {
				charValue = charToIntValue(userInput[i]); //calulate the numerical value of each character in the user input
				charValue = charValue + charToIntValue(matchFile[i]); // add the value of the user character to the value of the random character from the file
				// cout << charValue << " "; // Your message translated to numbers, plus the encryption key file translated to numbers.
				if (charValue > 27) {
					charValue = charValue - 27;
				}
				cout << intValueToChar(charValue);
			}
			cout << endl;
		}
		//### Decrypt
		//The application asks for the secret message you want to “decrypt.”  The user types in the message.
		//Reverse the process from the encrypt instructions and print the original message to the screen.
		if (crypt == 'd') {
			cout << endl << "DECRYPTION. Type your encrypted message here: " << endl;
			cin.ignore();
			getline(cin, userInput);
			cout << "Decryption complete. Your message is: " << endl;
			for (i = 0; i < userInput.length(); i++) {
				charValue = charToIntValue(userInput[i]); //calulate the numerical value of each character in the user input
				charValue = charValue - charToIntValue(matchFile[i]); // subtract the value of the user character to the value of the random character from the file
				if (charValue < 1) {
					charValue = charValue + 27;
				}
				cout << intValueToChar(charValue);
			}
			cout << endl;
		}

		if (crypt == 'x') {
			programContinue = false;
		}

		validCrypt = false;
	}

	in_a.close(); //always close the file when you are done reading it, prevent file corruption
	cout << " End of program ";
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}

