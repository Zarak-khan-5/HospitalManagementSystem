#ifndef USER_H
#define USER_H

const int TOTAL_USERS = 100;
const int TOTAL_APPOINTMENTS = 200;
const int TOTAL_RECORDS = 300;
const int TOTAL_BILLS = 400;
const int TOTAL_ROOMS = 50;

#include <string>
using namespace std;
class User
{
protected:
    string userID;
    string name;
    string email;
    string password;
    string role;

public:
    User()
    {
        userID = "";
        name = "";
        email = "";
        password = "";
        role = "";
    }
    User(string id, string n, string e, string p, string r)
    {
        userID = id;
        name = n;
        email = e;
        password = p;
        role = r;
    }
    virtual ~User() {}
    string getUserID() const
    {
        return userID;
    }
    string getName() const
    {
        return name;
    }
    string getEmail() const
    {
        return email;
    }
    string getRole() const
    {
        return role;
    }
    bool checkPassword(string pass)
    {
        return password == pass;
    }
    virtual bool login(string email, string password)
    {
        return this->email == email && this->password == password;
    }
    virtual void display() = 0;
};

#endif