#ifndef HEADER_H
#define HEADER_H

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    ~LinkedList();

    void insertAtBeginning(int val);

    void insertAtEnd(int val);

    void deleteFromBeginning();

    void deleteFromBack();

    void display();
};

#endif