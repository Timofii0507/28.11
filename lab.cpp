#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "��������� ������� �������� ����." << endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) 
    {
        cerr << "��������� ������� �������� ����." << endl;
        inputFile.close();
        return 1;
    }
    string word;
    while (inputFile >> word) 
    {
        if (word.length() >= 7)
        {
            outputFile << word << " ";
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "����� �� ���� �� ����� ���� ���� ������� � ���� output.txt." << endl;
    return 0;
}
