// SecretSecretProject.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#define LIMIT 3
int main()
{

    srand(time(NULL));
    const string filePath = "C:/Users/czarn/Desktop/REDD.txt";

    fstream file;
    file.open(filePath, std::ios::in);

    if (file.is_open())
        std::cout << "IsOpened\n";
    else {
        std::cout << "ERR_NotOpened\n";
        return -9;
    }

    string line;
    string chromeCommand = "start chrome ";

    for (string line; getline(file, line);) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        string command = chromeCommand + line;
        const char* com = command.c_str();
        system(com);
    }

    file.close();
}
