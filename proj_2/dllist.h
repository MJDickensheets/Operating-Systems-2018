/*******************
 * Header file for dllist class
 * ****************/
#include <iostream>
#include <cstdio>
#include "node.h"

class Dllist{

public:
    
    // Member variables
    Node* first;
    Node* head;

    // Constructor
    Dllist();

    // Destructor
    ~Dllist();
    // Member functions
    void produce(bool);
    void consume(bool);
    int length();
    void print();
    
};
