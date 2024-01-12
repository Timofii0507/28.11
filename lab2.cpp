#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
 
using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("input2.txt");

    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� ������� ����." << endl;
        return 1;
    }

    ofstream outputFile("output2.txt");

    if (!outputFile.is_open()) {
        cerr << "�� ������� ������� �������� ����." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "��������� ��������� ������." << endl;

    return 0;
}