#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "�� ������� ������� �����." << endl;
        return 1;
    }
    string line1, line2;
    int lineNumber = 0;
    while (getline(file1, line1) && getline(file2, line2))
    {
        lineNumber++;
        if (line1 != line2)
        {
            cout << "����� " << lineNumber << " �� ��������:" << endl;
            cout << "���� 1: " << line1 << endl;
            cout << "���� 2: " << line2 << endl;
        }
    }
    if (getline(file1, line1) || getline(file2, line2))
    {
        cout << "����� ����� ���� ������� �����." << endl;
    }
    else
    {
        cout << "����� ��������." << endl;
    }
    file1.close();
    file2.close();
    return 0;
}
