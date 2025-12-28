#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Doctor : public User
{
private:
    string specialization;

public:
    Doctor() : User()
    {
        specialization = "";
    }

    Doctor(string id, string n, string e, string p, string spec)
        : User(id, n, e, p, "Doctor")
    {
        specialization = spec;
    }

    string getSpecialization() const
    {
        return specialization;
    }

    void display() override
    {
        int choice;
        do
        {
            cout << "\n=== DOCTOR MENU ===" << endl;
            cout << "1. View My Schedule" << endl;
            cout << "2. Add Medical Record" << endl;
            cout << "3. View Patient Records" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                system("cls");
                viewMySchedule();
                system("pause");
                break;
            case 2:
                system("cls");
                addMedicalRecord();
                system("pause");
                break;
            case 3:
                system("cls");
                viewPatientRecords();
                system("pause");
                break;
            case 4:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 4);
    }

    void viewMySchedule()
    {
        cout << "Viewing my schedule..." << endl;
        HospitalManager::getInstance()->viewAllAppointments();
    }

    void addMedicalRecord()
    {
        string patientName, diagnosis, treatment;
        cout << "Enter Patient Name: ";
        getline(cin, patientName);
        cout << "Enter Diagnosis: ";
        getline(cin, diagnosis);
        cout << "Enter Treatment: ";
        getline(cin, treatment);

        HospitalManager::getInstance()->addMedicalRecord(patientName, diagnosis, treatment, name);
        cout << "Medical record added successfully!" << endl;
    }

    void viewPatientRecords()
    {
        string patientName;
        cout << "Enter Patient Name: ";
        getline(cin, patientName);

        HospitalManager::getInstance()->viewMedicalRecords(patientName);
    }
};
class Patient : public User
{
private:
    string phone;
    string address;

public:
    Patient()
    {
        phone = "";
        address = "";
    }
    Patient(string id, string n, string e, string p, string ph, string addr) : User(id, n, e, p, "Patient")
    {
        phone = ph;
        address = addr;
    }

    // Getters
    string getPhone() const
    {
        return phone;
    }
    string getAddress() const
    {
        return address;
    }

    // Setters - Add these methods
    void setPhone(const string &ph)
    {
        phone = ph;
    }
    void setAddress(const string &addr)
    {
        address = addr;
    }

    void display() override
    {
        int choice;
        do
        {
            cout << "\n=== PATIENT MENU ===" << endl;
            cout << "1. Book Appointment" << endl;
            cout << "2. View My Appointments" << endl;
            cout << "3. Cancel Appointment" << endl;
            cout << "4. View Medical Records" << endl;
            cout << "5. View Bills" << endl;
            cout << "6. Update Profile" << endl;
            cout << "7. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                system("cls");
                bookAppointment();
                system("pause");
                break;
            case 2:
                system("cls");
                viewMyAppointments();
                system("pause");
                break;
            case 3:
                system("cls");
                cancelAppointment();
                system("pause");
                break;
            case 4:
                system("cls");
                viewMedicalRecords();
                system("pause");
                break;
            case 5:
                system("cls");
                viewBills();
                system("pause");
                break;
            case 6:
                system("cls");
                updateProfile();
                system("pause");
                break;
            case 7:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 7);
    }

    void bookAppointment()
    {
        string doctorId, date, time;
        cout << "Enter Doctor ID: ";
        getline(cin, doctorId);
        cout << "Enter Appointment Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Appointment Time (HH:MM): ";
        getline(cin, time);

        HospitalManager::getInstance()->addAppointment(userID, doctorId, date, time);
        cout << "Appointment booked successfully!" << endl;
    }
    void viewMyAppointments()
    {
        cout << "Viewing my appointments..." << endl;
        HospitalManager::getInstance()->viewAllAppointments();
    }
    void cancelAppointment()
    {
        string appointmentId;
        cout << "Enter Appointment ID to cancel: ";
        getline(cin, appointmentId);

        HospitalManager::getInstance()->cancelAppointment(appointmentId);
        cout << "Appointment cancelled successfully!" << endl;
    }
    void viewMedicalRecords()
    {
        cout << "Viewing my medical records..." << endl;
        HospitalManager::getInstance()->viewMedicalRecords(userID);
    }
    void viewBills()
    {
        cout << "Viewing my bills..." << endl;
        HospitalManager::getInstance()->viewBills(userID);
    }
    void updateProfile()
    {
        cout << "Updating profile..." << endl;
        cout << "Enter new phone number: ";
        getline(cin, phone);
        cout << "Enter new address: ";
        getline(cin, address);

        HospitalManager::getInstance()->updateUserProfile(userID, phone, address);

        cout << "Profile updated successfully!" << endl;
    }
};
class Receptionist : public User
{
public:
    Receptionist() {}
    Receptionist(string id, string n, string e, string p) : User(id, n, e, p, "Receptionist") {}
    void display() override
    {
        int choice;
        do
        {
            cout << "\n=== RECEPTIONIST MENU ===" << endl;
            cout << "1. Register New Patient" << endl;
            cout << "2. Schedule Appointment" << endl;
            cout << "3. Assign Room" << endl;
            cout << "4. Handle Payment" << endl;
            cout << "5. View All Patients" << endl;
            cout << "6. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                system("cls");
                RegisternewPatient();
                system("pause");
                break;
            case 2:
                system("cls");
                ScheduleAppointment();
                system("pause");
                break;
            case 3:
                system("cls");
                AssignRoom();
                system("pause");
                break;
            case 4:
                system("cls");
                HandlePayment();
                system("pause");
                break;
            case 5:
                system("cls");
                ViewAllPatients();
                system("pause");
                break;
            case 6:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 6);
    }
    void RegisternewPatient()
    {
        string id, name, email, password, phone, address;
        cout << "Enter Patient ID: ";
        getline(cin, id);
        cout << "Enter Patient Name: ";
        getline(cin, name);
        cout << "Enter Patient Email: ";
        getline(cin, email);
        cout << "Enter Patient Password: ";
        getline(cin, password);
        cout << "Enter Patient Phone: ";
        getline(cin, phone);
        cout << "Enter Patient Address: ";
        getline(cin, address);

        Patient *newPatient = new Patient(id, name, email, password, phone, address);
        HospitalManager::getInstance()->addUser(newPatient); // Assuming HospitalManager has a method to add users
        cout << "Patient registered successfully!" << endl;
    }
    void ScheduleAppointment()
    {
        string patientId, doctorId, date, time;
        cout << "Enter Patient ID: ";
        getline(cin, patientId);
        cout << "Enter Doctor ID: ";
        getline(cin, doctorId);
        cout << "Enter Appointment Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Appointment Time (HH:MM): ";
        getline(cin, time);

        HospitalManager::getInstance()->addAppointment(patientId, doctorId, date, time);
        cout << "Appointment scheduled successfully!" << endl;
    }
    bool AssignRoom()
    {
        string patientId, roomNumber;
        cout << "Enter Patient ID: ";
        getline(cin, patientId);
        cout << "Enter Room Number: ";
        getline(cin, roomNumber);

        HospitalManager::getInstance()->assignRoom(patientId, roomNumber);
        cout << "Room assigned successfully!" << endl;
    }
    void HandlePayment()
    {
        string patientId, billId;
        double amount;
        cout << "Enter Patient ID: ";
        getline(cin, patientId);
        cout << "Enter Bill ID: ";
        getline(cin, billId);
        cout << "Enter Amount: ";
        cin >> amount;
        cin.ignore();

        HospitalManager::getInstance()->addBill(patientId, amount);
        HospitalManager::getInstance()->processPayment(billId);
        cout << "Payment handled successfully!" << endl;
    }
    void ViewAllPatients()
    {
        cout << "Viewing all patients..." << endl;
        HospitalManager::getInstance()->displayAllPatients();
    }
};

class Admin : public User
{
public:
    Admin() {}
    Admin(string id, string n, string e, string p) : User(id, n, e, p, "Admin")
    {
        userID = id;
        name = n;
        email = e;
        password = p;
    }
    void display() override
    {
        int choice;
        do
        {

            cout << "\n === ADMIN MENU ===" << endl;
            cout << "1. Add Doctor " << endl;
            cout << "2. Add Receptionist " << endl;
            cout << "3. Remove Staff " << endl;
            cout << "4. View All Appoinments " << endl;
            cout << "5. View Billing Summary " << endl;
            cout << "6. Logout " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:

                system("cls");
                addDoctor();
                system("pause");
                break;
            case 2:

                system("cls");
                addReceptionist();
                system("pause");
                break;
            case 3:

                system("cls");
                removeStaff();
                system("pause");
                break;
            case 4:

                system("cls");
                viewAllAppointments();
                system("pause");
                break;
            case 5:

                system("cls");
                viewBillingSummary();
                system("pause");
                break;
            case 6:

                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 6);
    }

    void addDoctor()
    {
        string id, name, email, password, specialization;
        cout << "Enter Doctor ID: ";
        getline(cin, id);
        cout << "Enter Doctor Name: ";
        getline(cin, name);
        cout << "Enter Doctor Email: ";
        getline(cin, email);
        cout << "Enter Doctor Password: ";
        getline(cin, password);
        cout << "Enter Doctor Specialization: ";
        getline(cin, specialization);

        Doctor *newDoctor = new Doctor(id, name, email, password, specialization);
        HospitalManager::getInstance()->addUser(newDoctor);
        cout << "Doctor added successfully!" << endl;
    }
    void addReceptionist()
    {
        string id, name, email, password;
        cout << "Enter Receptionist ID: ";
        getline(cin, id);
        cout << "Enter Receptionist Name: ";
        getline(cin, name);
        cout << "Enter Receptionist Email: ";
        getline(cin, email);
        cout << "Enter Receptionist Password: ";
        getline(cin, password);

        Receptionist *newReceptionist = new Receptionist(id, name, email, password);
        HospitalManager::getInstance()->addUser(newReceptionist);
        cout << "Receptionist added successfully!" << endl;
    }

    void removeStaff()
    {
        string userId;
        cout << "Enter Staff ID to remove: ";
        getline(cin, userId);

        HospitalManager::getInstance()->removeUser(userId);
        cout << "Staff removed successfully!" << endl;
    }

    void viewAllAppointments()
    {

        cout << "Viewing all appointments..." << endl;
        HospitalManager::getInstance()->viewAllAppointments();
    }

    void viewBillingSummary()
    {
        cout << "Viewing billing summary..." << endl;
        cout << "Enter patient ID: ";
        string patientId;
        getline(cin, patientId);

        HospitalManager::getInstance()->viewBills(patientId);
    }
};

#endif