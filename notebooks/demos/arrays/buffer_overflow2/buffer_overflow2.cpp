// buffer overflow example 2
// TODO: Compile and run the program using given Makefile
// enter whatever username and about 20 As or more for passoword
// goal is to display the social security without using the hidden password
// volatile keyword forces compiler to not aggressivley optimize variables
// forces the variable actually exist in memory and not cached in CPU registers

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // volatile bool valid = false;
    bool valid = false;
    char username[10];
    char password[10];

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    // strcpy(passBuffer, password);

    if (string(username) == "backdoor" and strcmp(password, "123456") == 0)
        valid = true;

    // cout << valid << endl;
    if (valid)
    {
        cout << "You have now access to top secret part of the program!" << endl;
        cout << "Your SSN is 123-45-5678\n";
    }
    else
        cout << "Invalid username or password!" << endl;

    return 0;
}