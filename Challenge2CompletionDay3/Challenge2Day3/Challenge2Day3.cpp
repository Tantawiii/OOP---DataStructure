#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    Employee* prev;
    Employee* next;

    Employee(int empId, string empName)
        : id(empId), name(empName), prev(nullptr), next(nullptr) {}
};

void addEmployee(Employee*& head, int id, string name) {
    Employee* heyheyEmp = new Employee(id, name);
    if (!head) {
        head = heyheyEmp;
    }
    else {
        Employee* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = heyheyEmp;
        heyheyEmp->prev = temp;
    }
}

void deleteEmployee(Employee*& head, int id) {
    Employee* byebyeEmp = head;
    while (byebyeEmp && byebyeEmp->id != id) {
        byebyeEmp = byebyeEmp->next;
    }
    if (byebyeEmp) {
        if (byebyeEmp->prev) byebyeEmp->prev->next = byebyeEmp->next;
        if (byebyeEmp->next) byebyeEmp->next->prev = byebyeEmp->prev;
        if (byebyeEmp == head) head = byebyeEmp->next;
        delete byebyeEmp;
    }
    else {
        cout << "Employee with ID " << id << " not found!" << endl;
    }
}

Employee* findEmployee(Employee* head, int id) {
    Employee* temp = head;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void replaceEmployee(Employee*& head, int id, string newName, int newId) {
    Employee* emp = findEmployee(head, id);
    if (emp) {
        Employee* prev = emp->prev;
        Employee* next = emp->next;
        deleteEmployee(head, id);
        Employee* newEmp = new Employee(newId, newName);
        newEmp->prev = prev;
        newEmp->next = next;
        if (prev) prev->next = newEmp;
        if (next) next->prev = newEmp;
        if (emp == head) head = newEmp;
    }
    else {
        cout << "Employee with ID " << id << " not found!" << endl;
    }
}


void printAll(Employee* head) {
    Employee* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    Employee* head = nullptr;

    addEmployee(head, 3, "Umar");
    addEmployee(head, 1, "Omar");
    addEmployee(head, 2, "Omer");

    cout << "All Employees:" << endl;
    printAll(head);
    replaceEmployee(head, 2, "Omr", 8);

    cout << "\nAfter Replacing Omer with Omr:" << endl;
    printAll(head);

    Employee* temp = findEmployee(head, 1);
    if (temp) {
        cout << "\nAfter Deleting: " << temp->name << endl;
        deleteEmployee(head, 1);
    }
    else {
        cout << "Employee with ID 1 not found!" << endl;
    }

    printAll(head);

    return 0;
}
