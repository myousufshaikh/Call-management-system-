
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For system("cls")
#include <conio.h> // For getch()
#include <ctime> // For getting current date & time
using namespace std;

// Struct to represent a contact
struct Contact {
    string name;
    string phoneNumber;
};

// Vector to store all the contacts
vector<Contact> contacts = {
    {"Abeera", "123-456-7890"},
    {"Maryam", "234-567-8901"},
    {"Haram", "345-678-9012"},
    {"Anisha", "456-789-0123"}
};

// Function to get current date & time
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

// Function to add a new contact
void addContact(string name, string phoneNumber) {
    contacts.push_back({name, phoneNumber});
    cout << " Contact added successfully!" << endl;
}

// Function to display all stored contacts
void displayContacts() {
    if (contacts.empty()) {
        return;
    }

    cout << "\nStored Contacts:\n";
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". Name: " << contacts[i].name << ", Phone Number: " << contacts[i].phoneNumber << endl;
    }
}

// Function to send a message to a contact
void sendMessage(string contactName, string message) {
    for (auto &contact : contacts) {
        if (contact.name == contactName) {
            cout << "Sending message to " << contact.name << ": " << message << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

// Function to make a call to a contact
void makeCall(string contactName) {
    for (auto &contact : contacts) {
        if (contact.name == contactName) {
            cout << "Calling " << contact.name << " at " << contact.phoneNumber << "...\n";
            cout << "Call time: " << getCurrentTime() << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

// Function to delete a contact
void deleteContact(string contactName) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == contactName) {
            contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

// Function to check password
bool checkPassword() {
    string password;
    cout << "Enter password to access the system: ";
    cin >> password;
    if (password == "1234") {
        cout << "Access granted!\n";
        return true;
    } else {
        cout << "Incorrect password! Exiting program...\n";
        return false;
    }
}

// Main function
int main() {
    if (!checkPassword()) {
        return 0;
    }

    int choice;
    string name, phoneNumber, message, contactName;

    while (true) {
        system("cls"); // Clear screen (Windows)
        cout << "\nWelcome to My Call Management System\n";
        cout << "\nMenu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Send Message\n";
        cout << "4. Make Call\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, phoneNumber);
                addContact(name, phoneNumber);
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                cout << "Enter contact name to message: ";
                cin.ignore();
                getline(cin, contactName);
                cout << "Enter message: ";
                getline(cin, message);
                sendMessage(contactName, message);
                break;

            case 4:
                cout << "Enter contact name to call: ";
                cin.ignore();
                getline(cin, contactName);
                makeCall(contactName);
                break;

            case 5:
                cout << "Enter contact name to delete: ";
                cin.ignore();
                getline(cin, contactName);
                deleteContact(contactName);
                break;

            case 6:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
        getch(); // Wait for user input before clearing the screen
    }
}