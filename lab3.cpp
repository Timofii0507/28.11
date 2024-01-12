#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int maxLines = 1000;
    string inputFileName = "input3.txt";
    string outputFileName = "output3.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile) 
    {
        cerr << "Не вдалося відкрити вхідний файл: " << inputFileName << endl;
        return 1;
    }
    string lines[maxLines];
    int lineCount = 0;
    string line;
    while (getline(inputFile, line) && lineCount < maxLines) 
    {
        lines[lineCount++] = line;
    }
    inputFile.close();
    ofstream outputFile(outputFileName);
    if (!outputFile) 
    {
        cerr << "Не вдалося відкрити вихідний файл: " << outputFileName << endl;
        return 1;
    }
    for (int i = lineCount - 1; i >= 0; --i) {
        outputFile << lines[i] << endl;
    }
    outputFile.close();
    cout << "Операція виконана успішно." << endl;
    return 0;
}
