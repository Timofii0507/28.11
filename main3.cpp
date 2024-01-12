#include <iostream>
#include <fstream>
#include <cctype>
#include <Windows.h>

using namespace std;

string encryptCaesarCipher(const string& text, int key) {
    string result = "";
    for (char ch : text) 
    {
        if (isalpha(ch))
        {
            char base = (isupper(ch)) ? 'A' : 'a';
            result += static_cast<char>((ch - base + key) % 26 + base);
        }
        else 
        {
            result += ch;
        }
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("input6.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "Не вдалося відкрити вхідний файл." << endl;
        return 1;
    }
    ofstream outputFile("output6.txt");
    if (!outputFile.is_open()) 
    {
        cerr << "Не вдалося відкрити вихідний файл." << endl;
        return 1;
    }
    string inputText((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    int key = 3;
    string encryptedText = encryptCaesarCipher(inputText, key);
    outputFile << encryptedText << endl;
    inputFile.close();
    outputFile.close();
    cout << "Текст успішно зашифровано та записано у вихідний файл." << endl;
    return 0;
}
