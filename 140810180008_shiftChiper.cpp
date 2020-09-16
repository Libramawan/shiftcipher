/*
Nama    : Prayudha Adhitia Libramawan
NPM     : 140810180008
Kelas   : B
Deskripsi : PROGRAM Enkrypt dan Dekrypt menggunakan Kripto Shift Cipher (Caesar Cipher)
***************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string encrypt(string message, int s);

int main()
{
    string message;
    int s, choice;
    char loop;

    do
    {
        cout << "------------------------------------" << endl;
        cout << "-----------= WELCOME TO =-----------" << endl;
        cout << "------= SHIFT CIPHER PROGRAM= ------" << endl;
        cout << "------------------------------------" << endl;
        cout << "Please choose one between these methods" << endl;
        cout << "\n1. Encryption \n2. Decryption \n What method do you want to choose: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            cout << "**Message can only be alphabetic**" << endl;
            cout << "Enter Plain Message : ";
            getline(cin, message);
            cout << "Enter key (0-25) : ";
            cin >> s;

            cout << "\nErypted Message : " << encrypt(message, s);
        }
        else if (choice == 2)
        {
            string encpMsg;

            cout << "**Message can only be alphabetic**" << endl;
            cout << "Enter Encrypted Message: ";
            getline(cin, encpMsg);

            int dcyptKey;
            cout << "Enter key (0-25): ";
            cin >> dcyptKey;
            cin.ignore();

            string decryptedMsg = encpMsg;

            for (int i = 0; i < encpMsg.size(); i++)
            {
                if (encpMsg[i] == 32)
                {
                    continue; //ignoring space
                }
                else
                {
                    if ((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90)
                    {
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedMsg[i] = temp;
                    }
                    else if ((encpMsg[i] - dcyptKey) < 65)
                    {
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedMsg[i] = temp;
                    }
                    else
                    {
                        decryptedMsg[i] = encpMsg[i] - dcyptKey;
                    }
                }
            }

            cout << "\nDecrypted Message: " << decryptedMsg << endl;
        }
        cout << "\n\nGo to Main Menu(Y/N)? ";
        cin >> loop;
    } while (loop == 'Y' || loop == 'y');
    return 0;
}

string encrypt(string message, int s)
{

    string result = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (char(int(message[i])) == 32)
            continue; //ignoring space

        else if (isupper(message[i]))
            result += char(int(message[i] + s - 65) % 26 + 65);

        else
            result += char(int(message[i] + s - 97) % 26 + 97);
    }

    return result;
}