#include <iostream>
#include <string>
using namespace std;

struct student {
    int id;
    string name;
    student* next = NULL;
};

struct queue {
    student* infront = NULL;
    student* behind = NULL;

    void enqueueIndex(student* newNode, int index) {
        if (index < 0) {
            cout << "Invalid index.\n\n";
            delete newNode;
            return;
        } //3shan lw 7d 7abbeb ytest value msh mawgooda -1 maselen

        if (index == 0) {
            newNode->next = infront;
            infront = newNode;
            if (behind == NULL) {
                behind = newNode;
            }
            cout << "Student " << newNode->name << " added at index 0.\n\n";
            return;
        } //first node option easiest and fastest format

        student* temp = infront;
        for (int i = 0; temp != NULL && i < index - 1; ++i) {
            temp = temp->next;
        } //search for it

        if (temp == NULL) {
            cout << "Index out of bounds. Adding at the end.\n\n";
            enqueue(newNode);
        } //msh mawgooda asasn el rakam dah, add a new one
        else {
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == NULL) {
                behind = newNode;
            }
            cout << "Student " << newNode->name << " added at index " << index << ".\n\n";
        } //tb mawgooda n3melo bka el enqueuing w nzok el queue kolha
    }

    //bshola bn3mel add l student gdeed
    void enqueue(student* newNode) {
        if (behind == NULL) {
            infront = behind = newNode;
        }
        else {
            behind->next = newNode;
            behind = newNode;
        }
    }

    void dequeue() {
        if (infront == NULL) {
            cout << "Empty Queue\n\n";
            return;
        }
        student* temp = infront;
        infront = infront->next;
        delete temp;
    }


    student* find(int id) {
        student* temp = infront;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void display() {
        if (infront == NULL) {
            cout << "The queue is empty!\n\n";
            return;
        }
        student* temp = infront;
        while (temp != NULL) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << "\n\n";
            temp = temp->next;
        }
    }
};

void menu() {
    cout << "Menu:\n";
    cout << "1. Enqueue a student\n";
    cout << "2. Enqueue at a specific index\n";
    cout << "3. Find a student by ID\n";
    cout << "4. Display all students\n";
    cout << "5. Dequeue a student\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    queue q;
    int choice, id, index;
    string name;

    do {
        menu();
        cin >> choice;
        student* n1 = new student{ 1, "Tantawy" };
        student* n2 = new student{ 2, "Masoud" };
        student* n3 = new student{ 3, "Omar" };

        switch (choice) {
        case 1:
            /*cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin >> name;
            q.enqueue(new student{ id, name });
            cout << "Student " << name << " added to the queue.\n\n";*/
            q.enqueue(n1);
            q.enqueue(n2);
            break;

        case 2:
            /*cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter index: ";
            cin >> index;
            q.enqueueIndex(new student{ id, name }, index);*/
            q.enqueueIndex(n3, 0);
            break;

        case 3:
            cout << "Enter student ID to search: ";
            cin >> id;
            student* found;
            found = q.find(id);
            if (found != NULL) {
                cout << "Student found: ID: " << found->id << ", Name: " << found->name << "\n\n";
            }
            else {
                cout << "Student with ID " << id << " not found.\n\n";
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            q.dequeue();
            break;

        case 6:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n\n";
            break;
        }
    } while (choice != 6);

    return 0;
}