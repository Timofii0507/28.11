#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("input5.txt");
    if (!inputFile) 
    {
        cerr << "Не вдалося відкрити вхідний файл." << endl;
        return 1;
    }
    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;
    char ch;
    while (inputFile.get(ch))
    {
        charCount++;

        if (ch == '\n') 
        {
            lineCount++;
        }
        else if (isalpha(ch)) 
        {
            char lowercaseCh = tolower(ch);
            if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
                vowelCount++;
            }
            else 
            {
                consonantCount++;
            }
        }
        else if (isdigit(ch)) 
        {
            digitCount++;
        }
    }
    inputFile.close();
    ofstream outputFile("output5.txt");
    if (!outputFile)
    {
        cerr << "Не вдалося відкрити вихідний файл." << endl;
        return 1;
    }
    outputFile << "Кількість символів: " << charCount << endl;
    outputFile << "Кількість рядків: " << lineCount << endl;
    outputFile << "Кількість голосних букв: " << vowelCount << endl;
    outputFile << "Кількість приголосних букв: " << consonantCount << endl;
    outputFile << "Кількість цифр: " << digitCount << endl;
    cout << "Статистика успішно записана у файл 'output.txt'." << endl;
    return 0;
}
