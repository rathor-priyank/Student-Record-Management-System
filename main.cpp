#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

class Student {
public:
    string name, roll, branch, address, mobile, email;
    float cgpi;

    void inputData() {
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Roll Number: "; cin >> roll;
        cout << "Enter Branch: "; cin.ignore(); getline(cin, branch);
        cout << "Enter CGPI: "; cin >> cgpi;
        cout << "Enter Address: "; cin.ignore(); getline(cin, address);
        cout << "Enter Mobile Number: "; cin >> mobile;
        cout << "Enter Email: "; cin >> email;
    }

    void displayData() const {
        cout << "\nName: " << name
             << "\nRoll Number: " << roll
             << "\nBranch: " << branch
             << "\nCGPI: " << cgpi
             << "\nAddress: " << address
             << "\nMobile: " << mobile
             << "\nEmail: " << email << "\n";
    }
};

void saveToFile(const vector<Student>& students) {
    ofstream file("students.csv");
    file << "Name,Roll,Branch,CGPI,Address,Mobile,Email\n";
    for (const auto& s : students) {
        file << s.name << "," << s.roll << "," << s.branch << "," << s.cgpi << "," << s.address << "," << s.mobile << "," << s.email << "\n";
    }
    file.close();
}

void deleteStudent(vector<Student>& students) {
    string rollNumber;
    cout << "Enter Roll Number of student to delete: ";
    cin >> rollNumber;
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == rollNumber) {
            students.erase(it);
            cout << "Student record deleted successfully!\n";
            saveToFile(students);
            return;
        }
    }
    cout << "Error: Student record not found.\n";
}

void adminMenu(vector<Student>& students) {
    int choice;
    while (true) {
        cout << "\nAdmin Menu";
        cout << "\n1. Add Student\n2. View Students\n3. Delete Student\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.inputData();
            for (const auto& student : students) {
                if (student.name == s.name && student.roll == s.roll && student.branch == s.branch &&
                    student.cgpi == s.cgpi && student.address == s.address && student.mobile == s.mobile && student.email == s.email) {
                    cout << "Error: This student record already exists!\n";
                    return;
                }
            }
            students.push_back(s);
            saveToFile(students);
            cout << "Student added successfully!\n";
        } else if (choice == 2) {
            for (const auto& s : students) {
                s.displayData();
                this_thread::sleep_for(chrono::milliseconds(500)); // Smooth display delay
            }
        } else if (choice == 3) {
            deleteStudent(students);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again.";
        }
    }
}

void studentMenu(const vector<Student>& students) {
    string rollNumber;
    cout << "Enter your Roll Number: ";
    cin >> rollNumber;

    for (const auto& s : students) {
        if (s.roll == rollNumber) {
            s.displayData();
            return;
        }
    }
    cout << "Student record not found.";
}

int main() {
    vector<Student> students;
    string password;
    int userType;

    cout << "\nLogin as: \n1. Admin\n2. Student\nEnter choice: ";
    cin >> userType;

    if (userType == 1) {
        cout << "Enter Admin Password: ";
        cin >> password;
        if (password == "admin123") {
            adminMenu(students);
        } else {
            cout << "Incorrect Password. Exiting...";
        }
    } else if (userType == 2) {
        studentMenu(students);
    } else {
        cout << "Invalid choice. Exiting...";
    }
    return 0;
}
