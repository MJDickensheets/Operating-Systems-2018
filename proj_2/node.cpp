/************************
 * Implementation file for Node class
 * *********************/

#include "node.h"
#include <cstdlib>

Node::Node(Node* prev, bool even):prev(prev){
    this->value = rand() % 50;
    if(even){
        if(this->value % 2 != 0){
            this->value --;
        }
    }
    else{
        if(this->value % 2 == 0){
            this->value ++;
        }
    }
};

void Node::setNext(Node* sNext){ next = sNext; }
void Node::setPrev(Node* sPrev) { prev = sPrev; }
Node* Node::getNext(){ return next; }
Node* Node::getPrev(){ return prev; }
int Node::getValue(){ return value; }
