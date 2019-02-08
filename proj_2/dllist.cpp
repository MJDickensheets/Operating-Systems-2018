/************************
 * Implementation file for dllist class
 * **********************/

#include "dllist.h"
#include <ctime>
#include <cstdlib>

Node* randNode();


Dllist::Dllist(){
    
    // Initialize random seed
    srand (time(NULL));
    this->first = randNode();
    Node* second = randNode();
    Node* third = randNode();

    first->setNext(second);
    second->setPrev(first);
    second->setNext(third);
    third->setPrev(second);
    
    this->head = third; 

};

Dllist::~Dllist() {
    Node* iter = first;
    while(iter != nullptr){
        Node* prev = iter;
        iter=iter->getNext();
        delete prev;
    }
}

// Create odd or even node
void Dllist::produce(bool even){
    // Check if full
    if(length() > 30){
        std::cout << "Buffer full!!" << std::endl;
        return;
    }
    if(first == nullptr){
        if(even){
            first = new Node(nullptr, true);
        }
        else{
            first = new Node(nullptr, false);
        } 
        head = first;
    }
    else{
        if(even){
            head->setNext(new Node(head, true));
        }
        else{
            head->setNext(new Node(head, false));
        }
        head = head->getNext();
    }
}

// Delete odd or even node
void Dllist::consume(bool even){
   
    // Buffer is empty
    if(first == nullptr){
        std::cout << "Buffer empty. Standing by." << std::endl;
        return;
    }
    
    // One node
    if(first==head){
       delete first;
       first = nullptr;
       head = nullptr;
       return;
    } 
    Node* old = first;

    while(true){
        if(even){
            if(old->getValue()%2 == 0) break;
        }
        else{
            if(old->getValue()%2 != 0) break;
        }
        // Catch end of buffer
        if(old->getNext() == nullptr){
            std::cout << "No matching values to consume." << std::endl;
            return;
        }
        old = old->getNext();
    }
    if(old->getPrev() != nullptr){
        old->getPrev()->setNext(old->getNext());
    }
    // Old is first
    else{
        first = old->getNext();
        first->setPrev(nullptr);
    }
    if(old->getNext() != nullptr){
        old->getNext()->setPrev(old->getPrev());
    }
    // Old is head
    else{
        head = old->getPrev();
        head->setNext(nullptr);
    }

    delete old;

}

// Return length of buffer
int Dllist::length(){
    int length = 0;
    Node* iter = first;
    while(iter != nullptr){
        length++;
        iter = iter->getNext();
    }
    return length;
}

// Print contents of buffer
void Dllist::print(){
    Node* iter = first;
    int i = 0;
    while(iter != nullptr && i < 30){
        ++i;
        std::cout << iter->getValue() << " ";
        iter = iter->getNext();
    }
    std::cout << std::endl;
}

// Helper function to create odd or even node
Node* randNode(){

    if(rand() % 2){
        return new Node(nullptr, true);
    }
    return new Node(nullptr, false);
}
