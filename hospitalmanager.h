#ifndef HOSPITALMANAGER_H
#define HOSPITALMANAGER_H

#include "User.h"
#include "Functionalities.h"

using namespace std;

class Doctor;
class Receptionist;
class Patient;
class Admin;

class HospitalManager
{
private:
    User *users[TOTAL_USERS];
    Appointment appointments[TOTAL_APPOINTMENTS];
    MedicalRecord medicalRecords[TOTAL_RECORDS];
    Billing bills[TOTAL_BILLS];
    Room rooms[TOTAL_ROOMS];

    int userCount;
    int appointmentCount;
    int recordCount;
    int billCount;
    int roomCount;

    static HospitalManager *instance;

    HospitalManager() : userCount(0), appointmentCount(0), recordCount(0), billCount(0), roomCount(0)
    {

        for (int i = 1; i <= 20; i++)
        {
            rooms[roomCount++] = Room("R" + to_string(i));
        }
    }

public:
    static HospitalManager *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new HospitalManager();
        }
        return instance;
    }

    User *authenticateUser(string email, string password)
    {
        for (int i = 0; i < userCount; ++i)
        {
            if (users[i]->login(email, password))
            {
                return users[i];
            }
        }
        return nullptr;
    }

    void addUser(User *user)
    {
        if (userCount < TOTAL_USERS)
        {
            users[userCount++] = user;
        }
        else
        {
            cout << "User limit reached!" << endl;
        }
    }

    void removeUser(string userId)
    {
        for (int i = 0; i < userCount; ++i)
        {
            if (users[i]->getUserID() == userId)
            {
                delete users[i];
                for (int j = i; j < userCount - 1; ++j)
                {
                    users[j] = users[j + 1];
                }
                userCount--;
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    void addAppointment(string patientId, string doctorId, string date, string time)
    {
        if (appointmentCount < TOTAL_APPOINTMENTS)
        {
            appointments[appointmentCount++] = Appointment("A" + to_string(appointmentCount + 1), patientId, doctorId, date, time);
        }
        else
        {
            cout << "Appointment limit reached!" << endl;
        }
    }

    void viewAllAppointments()
    {
        for (int i = 0; i < appointmentCount; ++i)
        {
            appointments[i].display();
        }
    }

    void cancelAppointment(string appointmentId)
    {
        for (int i = 0; i < appointmentCount; ++i)
        {
            if (appointments[i].getAppointmentId() == appointmentId)
            {
                for (int j = i; j < appointmentCount - 1; ++j)
                {
                    appointments[j] = appointments[j + 1];
                }
                appointmentCount--;
                return;
            }
        }
        cout << "Appointment not found!" << endl;
    }

    void addMedicalRecord(string patientId, string doctorId, string diagnosis, string treatment)
    {
        if (recordCount < TOTAL_RECORDS)
        {
            medicalRecords[recordCount++] = MedicalRecord("R" + to_string(recordCount + 1), patientId, doctorId, "2025-06-23", diagnosis, treatment);
        }
        else
        {
            cout << "Medical record limit reached!" << endl;
        }
    }

    void viewMedicalRecords(string patientId)
    {
        for (int i = 0; i < recordCount; ++i)
        {
            if (medicalRecords[i].getPatientId() == patientId)
            {
                medicalRecords[i].display();
            }
        }
    }

    void addBill(string patientId, double amount)
    {
        if (billCount < TOTAL_BILLS)
        {
            bills[billCount++] = Billing("B" + to_string(billCount + 1), patientId, amount, "2025-06-23");
        }
        else
        {
            cout << "Billing limit reached!" << endl;
        }
    }

    void viewBills(string patientId)
    {
        for (int i = 0; i < billCount; ++i)
        {
            if (bills[i].getPatientId() == patientId)
            {
                bills[i].display();
            }
        }
    }

    void processPayment(string billId)
    {
        for (int i = 0; i < billCount; ++i)
        {
            if (bills[i].getBillId() == billId)
            {
                bills[i].setStatus("Paid");
                return;
            }
        }
        cout << "Bill not found!" << endl;
    }

    bool assignRoom(string patientId, string roomNumber);

    void viewAvailableRooms()
    {
        for (int i = 0; i < roomCount; ++i)
        {
            if (!rooms[i].getIsOccupied())
            {
                rooms[i].display();
            }
        }
    }

    User **getUsers()
    {
        return users;
    }

    int getUserCount() const
    {
        return userCount;
    }

    void displayAllPatients();
    void updateUserProfile(const string &userId, const string &phone, const string &address);
};

#endif