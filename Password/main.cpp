#include <iostream>
#include "sha256.h"
#include <string>
#include <Windows.h>
#include <conio.h>
#include <map>

using namespace std;

int main() {
    map <string, string> passwords;
    bool islogined = false;
    main:;
    if (!islogined) {
        system("cls");
        cout << "1. Sign in\n2. Registration\n3. View the passwords database\n\nEnter the action number: ";
        char c = _getch();
        if (c == '1') {
            log:;
            system("cls");
            string login, password;
            cout << "Enter username: ";
            cin >> login;
            if (passwords[login] == "") {
                cout << "This username is not registered\n";
                Sleep(1000);
                goto log;
            }
            pass:;
            cout << "Enter password: ";
            cin >> password;
            password = sha256(password.c_str());
            if (passwords[login] == password) {
                cout << "Successful login!";
                islogined = true;
                Sleep(1000);
                goto main;
            }
            else {
                cout << "The password is incorrect";
                Sleep(1000);
                system("cls");
                cout << "Enter username: " << login << '\n';
                goto pass;
            }
        }
        else if (c == '2') {
            reg:;
            system("cls");
            string login, password;
            cout << "Enter username: ";
            cin >> login;
            if (passwords[login] != "") {
                cout << "This username is already registered";
                Sleep(1000);
                goto reg;
            }
            cout << "Enter password: ";
            cin >> password;
            password = sha256(password);
            passwords[login] = password;
            cout << "Successful login!";
            islogined = true;
            Sleep(1000);
            goto main;
        }
        else if (c == '3') {
            system("cls");
            for (auto i : passwords) {
                cout << i.first << ": " << i.second << '\n';
            }
            cout << '\n';
            cout << "Return to the main screen: ";
            char _ = _getch();
            goto main;
        }
    }
    else {
        system("cls");
        cout << "1. Sign out\n2. View the passwords database\n\nEnter the action number: ";
        char c = _getch();
        if (c == '1') {
            islogined = false;
            goto main;
        }
        else if (c == '2') {
            system("cls");
            for (auto i : passwords) {
                cout << i.first << ": " << i.second << '\n';
            }
            cout << '\n';
            cout << "Return to the main screen: ";
            char _ = _getch();
            goto main;
        }
    }
    return 0;
}
