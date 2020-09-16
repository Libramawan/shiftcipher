/*
Nama    : Prayudha Adhitia Libramawan
NPM     : 140810180008
Kelas   : B
Deskripsi : Fungsi enkripsi menggunakan Shift Chiper
*/

#include <iostream>
using namespace std;

string encrypt(string text, int s);

int main()
{
    string text = "ANJAY";
    int s = 30;
    cout << "Plain Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher Text : " << encrypt(text, s);
    return 0;
}

string encrypt(string text, int s)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    return result;
}