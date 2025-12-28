#include <iostream>
#include "userfactory.h"
#include "hospitalmanager.h"
#include "SystemInitializer.h"

using namespace std;

int main()
{
    SystemInitializer::initializeSystem();
    cout << "=== WELCOME TO HOSPITAL MANAGEMENT SYSTEM ===" << endl;

    while (true)
    {
        cout << "\n1. Login" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string email, password;
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter password: ";
            getline(cin, password);

            User *user = UserFactory::loginUser(email, password);

            if (user)
            {
                cout << "Login successful! Welcome, " << user->getName() << endl;
                user->display();
                user = nullptr;
            }
        }
        else if (choice == 2)
        {
            cout << "Thank you for using Hospital Management System!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}
