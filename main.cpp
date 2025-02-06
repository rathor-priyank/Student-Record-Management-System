#include <iostream>
#include "loading.h"
#include <string>
#include "adminFunction.h"

using namespace std;

void passwordVerification();
void mainMenu();

void passwordVerification()
{
    system("clear");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\tEnter Password: ";
    while (true)
    {
        cin >> password;

        if (password == "password")
        {
            mainMenu();
            return;
        }
        else if (password == "quit" || password == "exit")
        {
            system("clear");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
            for (int i = 0; i < 4; i++)
            {
                usleep(1000000); // 1-second pause
                cout << ".";
            }
            exit(0);
        }
        else
        {
            cout << "\nIncorrect password. Try again: ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    loadingBar();
    system("echo -e \"\\033[0m\""); // Reset terminal text color
    passwordVerification();
    return 0;
}
