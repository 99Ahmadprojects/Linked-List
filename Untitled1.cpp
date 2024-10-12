#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int sap_id;
    Student* next;
};

void insertStudent(Student*& head, string name, int sap_id) {
    Student* newStudent = new Student();
    newStudent->name = name;
    newStudent->sap_id = sap_id;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void deleteStudentAtPosition(Student*& head, int position) {
    if (head == nullptr) return;

    Student* temp = head;

    if (position == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return;

    Student* next = temp->next->next;

    delete temp->next;
    temp->next = next;
}

void printStudents(Student* head) {
    Student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", SAP_ID: " << temp->sap_id << endl;
        temp = temp->next;
    }
}

int main() {
    Student* head = nullptr;
    int numberOfStudents = 5;

    for (int i = 1; i <= numberOfStudents; i++) {
        string name;
        int sap_id;
        cout << "Enter Name of student " << i << ": ";
        cin >> name;
        cout << "Enter SAP_ID of student " << i << ": ";
        cin >> sap_id;
        insertStudent(head, name, sap_id);
    }

    cout << "\nList of students after insertion:\n";
    printStudents(head);

    deleteStudentAtPosition(head, 2);
    deleteStudentAtPosition(head, 5);

    cout << "\nList of students after deleting 2nd and 5th student:\n";
    printStudents(head);

    return 0;
}
