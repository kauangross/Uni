#include <iostream>
#include "header.h"
using namespace std;

// Criar uma lista encadeada comm template e remover o último elemento

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display();

    list.deleteFromBeginning();
    list.insertAtEnd(10);
    list.display();

    list.deleteFromBack();
    list.display();
    return 0;
}