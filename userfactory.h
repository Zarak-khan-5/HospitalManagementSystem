#ifndef USERFACTORY_H
#define USERFACTORY_H
#include <iostream>
#include <string>
#include "User.h"
#include "hospitalmanager.h"
#include "Staff.h"

class UserFactory
{
public:
    static User *loginUser(const string &email, const string &password)
    {
        HospitalManager *manager = HospitalManager::getInstance();
        User *user = manager->authenticateUser(email, password);

        if (user)
        {
            return user;
        }
        else
        {
            cout << "Invalid credentials! Please try again." << endl;
            return nullptr;
        }
    }

    static User *createUser(string role, string id, string name, string email, string password)
    {
        if (role == "Admin")
        {
            return new Admin(id, name, email, password);
        }
        else if (role == "Receptionist")
        {
            return new Receptionist(id, name, email, password);
        }
        return nullptr;
    }

    static User *createUser(string role, string id, string name, string email, string password, string specialization)
    {
        if (role == "Doctor")
        {
            return new Doctor(id, name, email, password, specialization);
        }
        return nullptr;
    }

    static User *createUser(string role, string id, string name, string email, string password, string phone, string address)
    {
        if (role == "Patient")
        {
            return new Patient(id, name, email, password, phone, address);
        }
        return nullptr;
    }
};

#endif
