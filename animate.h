#include <iostream>
#include <unistd.h> // for usleep()

using namespace std;

void loadingBar()
{
    system("clear");
    system("echo -e \"\\033[0;36m\""); // Change terminal text color
    char a = 177, b = 219;

    cout << "\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
    cout << "\n\t\t\t\t\tProject By Ajay Singh";
    cout << "\n\n\n\t\t\t\t\tLoading...\n";
    cout << endl;
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26; i++)
        cout << a;

    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << b;
        usleep(200000); // 0.2-second pause
    }
}
