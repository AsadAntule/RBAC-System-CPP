#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
public:
    string username;
    string role;

    void createUser()
    {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Role (Admin/Manager/Employee): ";
        cin >> role;

        ofstream file("users.txt", ios::app);
        file << username << " " << role << endl;
        file.close();

        cout << "User Created Successfully!\n";
    }
};

void viewUsers()
{
    ifstream file("users.txt");
    string username, role;

    cout << "\n--- Registered Users ---\n";

    while (file >> username >> role)
    {
        cout << "Username: " << username << " | Role: " << role << endl;
    }

    file.close();
}

string getRole(string username)
{

    ifstream file("users.txt");
    string user, role;

    while (file >> user >> role)
    {
        if (user == username)
            return role;
    }

    return "None";
}

void showPermissions()
{

    cout << "\n--- Role Permissions ---\n";

    cout << "Admin -> Read, Write, Delete\n";
    cout << "Manager -> Read, Write\n";
    cout << "Employee -> Read Only\n";
}

void checkAccess(string role)
{

    int choice;

    cout << "\nSelect Operation\n";
    cout << "1. Read Data\n";
    cout << "2. Write Data\n";
    cout << "3. Delete Data\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if (role == "Admin")
    {
        cout << "Access Granted\n";
    }

    else if (role == "Manager")
    {
        if (choice == 1 || choice == 2)
            cout << "Access Granted\n";
        else
            cout << "Access Denied\n";
    }

    else if (role == "Employee")
    {
        if (choice == 1)
            cout << "Access Granted\n";
        else
            cout << "Access Denied\n";
    }
}

int main()
{

    int choice;
    User u;
    string username;

    do
    {

        cout << "\n===== RBAC SYSTEM =====\n";
        cout << "1. Create User\n";
        cout << "2. View Users\n";
        cout << "3. Login & Check Access\n";
        cout << "4. View Role Permissions\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            u.createUser();
            break;

        case 2:
            viewUsers();
            break;

        case 3:
            cout << "Enter Username: ";
            cin >> username;

            {
                string role = getRole(username);

                if (role == "None")
                    cout << "User Not Found!\n";
                else
                {
                    cout << "Logged in as: " << role << endl;
                    checkAccess(role);
                }
            }

            break;

        case 4:
            showPermissions();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}