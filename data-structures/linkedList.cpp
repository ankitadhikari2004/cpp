#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            return;
        }
        Node* currentNode = this->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    void deleteNode(int data)
    {
        if (this->head == NULL)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        // If the head node is to be deleted
        if (this->head->data == data)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }

        Node *currentNode = this->head;
        Node *prevNode = NULL;

        // Traverse the list to find the node to delete
        while (currentNode != NULL && currentNode->data != data)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        // If the node is not found
        if (currentNode == NULL)
        {
            cout << "Node with value " << data << " not found." << endl;
            return;
        }

        // Remove the node
        prevNode->next = currentNode->next;
        delete currentNode;
    }

    void printList() {
        Node* currentNode = this->head;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.printList();
    list.deleteNode(3);
    list.printList();
    return 0;
}