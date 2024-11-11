#include "header.h"
#include <iostream>
using namespace std;

Node::Node(int data) {
    this->data = data;
    next = nullptr;
}

LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    Node* current = head;
    Node* next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void LinkedList::insertAtBeginning(int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int val){
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::deleteFromBeginning(){
    if (head == nullptr)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromBack(){
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {  // Apenas um elemento
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    delete temp->next;    
    temp->next = nullptr; 
}

void LinkedList::display(){
    if (head == nullptr)
    {
        cout << "Lista vazia!" << endl;
    }
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}