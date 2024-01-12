#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("input4.txt");
    if (!inputFile.is_open())
    {
        cerr << "Не вдалося відкрити вхідний файл.\n";
        return 1;
    }
    string line, lastNonSpaceLine;
    size_t index = 0;
    while (getline(inputFile, line)) 
    {
        if (line.find(' ') == string::npos) 
        {
            lastNonSpaceLine = line;
            index = inputFile.tellg();
        }
    }
    inputFile.clear();
    inputFile.seekg(0);
    ofstream outputFile("output4.txt");
    if (!outputFile.is_open()) 
    {
        cerr << "Не вдалося відкрити вихідний файл.\n";
        return 1;
    }
    while (getline(inputFile, line)) 
    {
        outputFile << line << '\n';
        if (inputFile.tellg() == index)
        {
            outputFile << "------------\n";
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "Операція виконана успішно.\n";
    return 0;
}
