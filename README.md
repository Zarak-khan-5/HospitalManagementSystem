# Hospital Management System

A comprehensive console-based Hospital Management System built in C++ that manages patients, doctors, receptionists, appointments, medical records, billing, and room assignments.

## Overview

This system implements a role-based architecture where different users (Admin, Doctor, Patient, Receptionist) have access to specific functionalities. It uses object-oriented programming principles including inheritance, polymorphism, and design patterns like Singleton and Factory.

## Features

### User Roles and Capabilities

#### Admin
- Add and remove doctors and receptionists
- View all appointments across the system
- Access billing summaries for any patient
- Manage staff members

#### Doctor
- View personal appointment schedule
- Add medical records for patients
- View patient medical histories
- Record diagnoses and treatments

#### Patient
- Book appointments with doctors
- View personal appointments
- Cancel appointments
- Access medical records
- View billing information
- Update profile (phone number and address)

#### Receptionist
- Register new patients
- Schedule appointments
- Assign rooms to patients
- Handle payments and billing
- View all registered patients

## System Architecture

### Design Patterns

**Singleton Pattern**: The `HospitalManager` class ensures only one instance manages all hospital operations throughout the system.

**Factory Pattern**: The `UserFactory` class creates appropriate user objects based on role, handling the complexity of object creation with different parameter requirements.

### Core Components

**User Management**: Base `User` class with derived classes for Admin, Doctor, Patient, and Receptionist, implementing role-specific functionality through polymorphism.

**Appointment System**: Track and manage appointments between patients and doctors with status tracking.

**Medical Records**: Store patient diagnoses and treatments with doctor associations.

**Billing System**: Manage patient bills with payment status tracking.

**Room Management**: Handle room assignments with 20 pre-initialized rooms (R1-R20).

## File Structure

- `User.h` - Base user class and system constants
- `Staff.h` - Derived user classes (Doctor, Patient, Receptionist, Admin)
- `Functionalities.h` - Supporting classes (Appointment, MedicalRecord, Room, Billing)
- `hospitalmanager.h/cpp` - Singleton manager for all hospital operations
- `userfactory.h` - Factory pattern for user creation and authentication
- `systeminitializer.h` - System initialization with default users
- `main.cpp` - Application entry point and login loop

## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)
- Windows OS (for `system("cls")` and `system("pause")` commands)

### Compilation

```bash
g++ main.cpp hospitalmanager.cpp -o hospital_system
```

### Running the System

```bash
./hospital_system
```

## Default Users

The system initializes with the following default accounts:

| Role | Email | Password | ID |
|------|-------|----------|-----|
| Admin | admin@hospital.com | admin123 | A001 |
| Doctor | usman@hospital.com | mani123 | D001 |
| Doctor | ali@hospital.com | bro456 | D002 |
| Receptionist | daniyal@hospital.com | dab123 | R001 |
| Patient | adan@hospital.com | adan123 | P001 |

## System Capacity

- Maximum Users: 100
- Maximum Appointments: 200
- Maximum Medical Records: 300
- Maximum Bills: 400
- Total Rooms: 50 (20 initialized by default)

## Technical Details

### Memory Management

The system uses dynamic memory allocation for user objects, with proper cleanup in the `removeUser` function. The `HospitalManager` maintains arrays of users and other entities within predefined limits.

### Authentication

User authentication is handled through email and password verification, with the `HospitalManager` searching through all registered users to validate credentials.

### Data Persistence

Note: This is a console-based system without file I/O implementation. All data exists in memory during runtime and is lost when the program terminates.

## Usage Example

1. Run the application
2. Select "Login" option
3. Enter credentials (e.g., admin@hospital.com / admin123)
4. Navigate through role-specific menu options
5. Perform desired operations
6. Logout when finished


## Authors

Muhammad Zarak Khan - Academic Project

## License

This project is developed for educational purposes.
