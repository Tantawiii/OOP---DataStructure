#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool flag = false;

struct Student {
    int id;
    string name;
    string direction;
    Student* left = NULL;
    Student* right = NULL;
};

vector<Student*> insertionOrder;

Student* insert(Student* student, int id, string name, string direction = "Center", string parentName = "") {
    if (student == NULL) {
        string fullDirection = (direction == "Center") ? "Center (Root)" : direction + " of " + parentName;
        Student* newStudent = new Student{ id, name, fullDirection };
        insertionOrder.push_back(newStudent);
        cout << "Inserted student: " << name << " with ID: " << id << " as " << fullDirection << "\n";
        return newStudent;
    }

    if (id < student->id) {
        student->left = insert(student->left, id, name, "Left", student->name);
    }
    else if (id > student->id) {
        student->right = insert(student->right, id, name, "Right", student->name);
    }
    else {
        cout << "Student with ID " << id << " already exists.\n";
    }
    return student;
}


Student* find(Student* student, int id) {
    if (student == NULL || student->id == id) {
        return student;
    }
    if (id < student->id) {
        return find(student->left, id);
    }
    else {
        return find(student->right, id);
    }
}

Student* remove(Student* student, int id) {
    if (student == NULL) return NULL;

    if (id < student->id) {
        student->left = remove(student->left, id);
    }
    else if (id > student->id) {
        student->right = remove(student->right, id);
    }
    else {
        if (student->left == NULL && student->right == NULL) {
            delete student;
            return NULL;
        }
        else if (student->left != NULL && student->right == NULL) {
            Student* temp = student->left;
            delete student;
            return temp;
        }
        else if (student->left == NULL && student->right != NULL) {
            Student* temp = student->right;
            delete student;
            return temp;
        }
        else {
            Student* temp = student->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            student->id = temp->id;
            student->name = temp->name;
            student->direction = temp->direction;
            student->right = remove(student->right, temp->id);
        }
    }
    return student;
}

void display() {
    int nodeCount;
    if(flag == false)
        nodeCount = insertionOrder.size();
    else
        nodeCount = insertionOrder.size() - 1;
    cout << "\nNumber of nodes in tree: " << nodeCount << "\n";
    cout << "Students in tree:\n";

    for (int i = 0; i < nodeCount; ++i) {
        Student* student = insertionOrder[i];
        if (student != NULL) {
            cout << "ID: " << student->id << ", Name: " << student->name
                << ", Direction: " << student->direction << "\n";
        }
    }
}


int main() {
    Student* student = NULL;
    student = insert(student, 3, "Masoud");
    student = insert(student, 1, "Omar");
    student = insert(student, 2, "Tantawy");
    student = insert(student, 4, "Umar");
    display();

    int tempID = 2;
    Student* found = find(student, tempID);
    if (found != NULL) {
        cout << "\nStudent found: ID: " << found->id << ", Name: " << found->name
            << ", Direction: " << found->direction << "\n";
    }
    else {
        cout << "\nStudent with ID " << tempID << " not found.\n";
    }

    tempID = 4;
    flag = true;
    student = remove(student, tempID);
    cout << "\nTree after removing student with ID " << tempID << ":\n";
    display();

    return 0;
}
