#include <iostream>
#include <fstream>

using namespace std;

void languageMaker();
void dencrypter(string source);

int main(void)
{
	char process;
	string message, codedMessage; 
	char continu;
	
	cout << "\t\t\t\tWELCOME TO" << endl;
	
	cout << "---------------------------------------------------------------------------" << endl;
 	cout << "   *****  ****** *    *  ****  *****  *   * *****  ******* ****** *****" << endl;
 	cout << "    *   * *      **   * *    *  *   *  * *   *   *    *    *       *   *" << endl;
 	cout << "    *   * ***    * *  * *       ****    *    ****     *    ***     ****" << endl;
 	cout << "    *   * *      *  * * *    *  *  *    *    *        *    *       *  *" << endl;
 	cout << "   *****  ****** *   **  ****   *   *   *    *        *    ******  *   *" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
	
	do 
	{
		cout << "Enter the process to be executed                  : " << endl;
		cout << "(Make a Language - L / Encrypt - E / Decrypt - D) : ";
		cin >> process;
		
		cin.ignore();
		
		if (process == 'L')
		{
			cout << endl << "Language Maker: " << endl;					
			languageMaker();
		}
		else if (process == 'E')
		{
			cout << endl << "Encryptor: " << endl ;
			cout << endl << "Enter the message      : ";
			getline(cin, message);
			
			dencrypter(message);
		}
		else if (process == 'D')
		{
			cout << endl << "Decryptor: " << endl;
			cout << endl << "Enter the coded message: ";
			getline(cin, codedMessage);
			
			dencrypter(codedMessage);
		}
		
		cout << endl << endl << "Do you want to continue(Y/N): ";
		cin >> continu;
		cout << "---------------------------------------------" << endl << endl;
		
	}while (continu == 'Y');
	
	return 0;
}

void languageMaker()
{
	char letter1, letter2;
	
	ofstream file("language_source_code.txt");
	
	if (!file.is_open())
	{
		cerr << "Error: Unable to open the file!!!";
	}
	
	cout << endl << "Enter the letter combinations below." << endl << endl;
	
	cout << "1.) Make your code language with 13 letter combinations from the 26 letters in the alphabet." << endl;
	cout << "2.) The 2 letters in a combination should represent each other in the code language." << endl;
	cout << "3.) Example: a <---> b - Here 'a' represents 'b' and 'b represents 'a' in the code language." << endl;
	cout << "4.) Likewise create your own 13 unique letter combinations and enter the combinations below(Seperate the 2 letters with a space when enterring.)." << endl << endl;
	
	for (int i = 0; i < 13; i++)
	{
		cout << "Letter combination " << i+1 << " : ";
		cin >> letter1 >> letter2;
		
		file << letter1 << " " << letter2 << endl;
	}
	
	file.close();
}

void dencrypter(string source)
{
	char letter1, letter2;
	
	ifstream file("language_source_code.txt");
	
	if (!file.is_open())
	{
		cerr << "Error: Unable to open the file!!!";
	}
	
	cout << "The encyrpted message  : ";
	for (int i = 0; i < source.size(); i++)
	{
		char c  = source[i];
		
		while(file >> letter1 >> letter2)
		{
			if(c == ' ')
			{
				cout << " ";
				break;
			}
			else if (c == letter1)
			{
				cout << letter2;
				break;
			}	
			else if (c == letter2)
			{
				cout << letter1;
				break;
			}		
		}
		
		file.clear();
		file.seekg(0, ios::beg);
	}
}
