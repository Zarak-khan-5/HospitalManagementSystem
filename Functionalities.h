#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <string>
using namespace std;

class Appointment
{
    
private:
    string appointmentId;
    string patientId;
    string doctorId;
    string date;
    string time;
    string status;

public:
    Appointment()
    {
        appointmentId = "";
        patientId = "";
        doctorId = "";
        date = "";
        time = "";
        status = "";
    }
    Appointment(string appId, string pId, string dId, string d, string t)
    {
        appointmentId = appId;
        patientId = pId;
        doctorId = dId;
        date = d;
        time = t;
        status = "Scheduled";
    }

    string getAppointmentId() const
    {
        return appointmentId;
    }
    string getPatientId() const
    {
        return patientId;
    }
    string getDoctorId() const
    {
        return doctorId;
    }
    string getDate() const
    {
        return date;
    }
    string getTime() const
    {
        return time;
    }
    string getStatus() const
    {
        return status;
    }

    void setStatus(string s)
    {
        status = s;
    }

    void display() const
    {
        cout << "ID: " << appointmentId << ", Patient: " << patientId
             << ", Doctor: " << doctorId << ", Date: " << date
             << ", Time: " << time << ", Status: " << status << endl;
    }
};
class MedicalRecord
{
private:
    string recordId;
    string patientId;
    string doctorId;
    string date;
    string diagnosis;
    string treatment;

public:
    MedicalRecord()
    {
        recordId = "";
        patientId = "";
        doctorId = "";
        date = "";
        diagnosis = "";
        treatment = "";
    }
    MedicalRecord(string rId, string pId, string dId, string d, string diag, string treat)
    {
        recordId = rId;
        patientId = pId;
        doctorId = dId;
        date = d;
        diagnosis = diag;
        treatment = treat;
    }

    string getPatientId() const
    {
        return patientId;
    }
    string getDoctorId() const
    {
        return doctorId;
    }

    void display() const
    {
        cout << "Record ID: " << recordId << ", Date: " << date
             << ", Diagnosis: " << diagnosis << ", Treatment: " << treatment << endl;
    }
};
class Room
{
private:
    string roomNumber;
    string patientId;
    bool isOccupied;

public:
    Room()
    {
        roomNumber = "";
        patientId = "";
        isOccupied = false;
    }
    Room(string rNum)
    {
        roomNumber = rNum;
        patientId = "";
        isOccupied = false;
    }

    string getRoomNumber() const
    {
        return roomNumber;
    }
    string getPatientId() const
    {
        return patientId;
    }
    bool getIsOccupied() const
    {
        return isOccupied;
    }

    void assignPatient(string pId)
    {
        patientId = pId;
        isOccupied = true;
    }

    void releaseRoom()
    {
        patientId = "";
        isOccupied = false;
    }

    void display() const
    {
        cout << "Room: " << roomNumber << ", Status: "
             << (isOccupied ? "Occupied by " + patientId : "Available") << endl;
    }
};
class Billing
{
private:
    string billId;
    string patientId;
    double amount;
    string status;
    string date;

public:
    Billing()
    {
        billId = "";
        patientId = "";
        amount = 0.0;
        status = "";
        date = "";
    }
    Billing(string bId, string pId, double amt, string d)
    {
        billId = bId;
        patientId = pId;
        amount = amt;
        status = "Unpaid";
        date = d;
    }

    string getBillId() const
    {
        return billId;
    }
    string getPatientId() const
    {
        return patientId;
    }
    double getAmount() const
    {
        return amount;
    }
    string getStatus() const
    {
        return status;
    }

    void setStatus(string s)
    {
        status = s;
    }

    void display() const
    {
        cout << "Bill ID: " << billId << ", Amount: $" << amount
             << ", Status: " << status << ", Date: " << date << endl;
    }
};

#endif