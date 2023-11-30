// SecretSecretProject.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const string filePath = "PUT_YOUR_FILE_PATH_HERE";

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
