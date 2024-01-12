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
        cerr << "�� ������� ������� ������� ����." << endl;
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
        cerr << "�� ������� ������� �������� ����." << endl;
        return 1;
    }
    outputFile << "ʳ������ �������: " << charCount << endl;
    outputFile << "ʳ������ �����: " << lineCount << endl;
    outputFile << "ʳ������ �������� ����: " << vowelCount << endl;
    outputFile << "ʳ������ ����������� ����: " << consonantCount << endl;
    outputFile << "ʳ������ ����: " << digitCount << endl;
    cout << "���������� ������ �������� � ���� 'output.txt'." << endl;
    return 0;
}
