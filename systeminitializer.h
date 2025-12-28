#ifndef SYSTEMINITIALIZER_H
#define SYSTEMINITIALIZER_H
#include "userfactory.h"
#include "hospitalmanager.h"

class SystemInitializer
{
public:
    static void initializeSystem()
    {
        HospitalManager *manager = HospitalManager::getInstance();
        User *defaultAdmin = UserFactory::createUser("Admin", "A001", "admin", "admin@hospital.com", "admin123");
        User *defaultDoctor1 = UserFactory::createUser("Doctor", "D001", "Dr. Usman", "usman@hospital.com", "mani123", "Psychatrist");
        User *defaultDoctor2 = UserFactory ::createUser("Doctor", "D002", "Dr. Ali", "ali@hospital.com", "bro456", "Neurology");
        User *defaultReceptionist = UserFactory::createUser("Receptionist", "R001", "Daniyal Adeeb", "daniyal@hospital.com", "dab123");
        User *defaultPatient = UserFactory::createUser("Patient", "P001", "Adan Hashmi", "adan@hospital.com", "adan123", "03027031383", "138-NFC-Lahore-Street#5");
        manager->addUser(defaultAdmin);
        manager->addUser(defaultDoctor1);
        manager->addUser(defaultDoctor2);
        manager->addUser(defaultReceptionist);
        manager->addUser(defaultPatient);
    }
};

#endif