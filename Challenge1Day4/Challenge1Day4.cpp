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

int main() {
    queue q;
    q.display();

    student* n1 = new student{ 1, "Tantawy" };
    student* n2 = new student{ 2, "Masoud" };
    student* n3 = new student{ 3, "Omar" };

    q.enqueue(n1);
    q.enqueue(n2);
    q.display();

    q.enqueueIndex(n3, 0);
    q.display();

    q.enqueueIndex(n3, -1);

    return 0;
}