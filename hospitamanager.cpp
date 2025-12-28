#include "hospitalmanager.h"
#include "Staff.h"

// Initialize static member
HospitalManager *HospitalManager::instance = nullptr;

void HospitalManager::displayAllPatients()
{
    cout << "=== ALL PATIENTS ===" << endl;
    bool found = false;

    for (int i = 0; i < userCount; ++i)
    {

        Patient *patient = dynamic_cast<Patient *>(users[i]);
        if (patient)
        {
            found = true;
            cout << "Patient ID: " << patient->getUserID() << endl;
            cout << "Name: " << patient->getName() << endl;
            cout << "Email: " << patient->getEmail() << endl;
            cout << "Phone: " << patient->getPhone() << endl;
            cout << "Address: " << patient->getAddress() << endl;
            cout << "------------------------" << endl;
        }
    }

    if (!found)
    {
        cout << "No patients found." << endl;
    }
}

void HospitalManager::updateUserProfile(const string &userId, const string &phone, const string &address)
{
    for (int i = 0; i < userCount; ++i)
    {
        if (users[i]->getUserID() == userId)
        {
            Patient *patient = dynamic_cast<Patient *>(users[i]);
            if (patient)
            {

                patient->setPhone(phone);
                patient->setAddress(address);
                cout << "Profile updated successfully for patient: " << userId << endl;
                return;
            }
        }
    }
    cout << "Patient not found!" << endl;
}

bool HospitalManager::assignRoom(string patientId, string roomNumber)
{
    for (int i = 0; i < roomCount; ++i)
    {
        if (rooms[i].getRoomNumber() == roomNumber && !rooms[i].getIsOccupied())
        {
            rooms[i].assignPatient(patientId);
            return true;
        }
    }
    return false;
}
