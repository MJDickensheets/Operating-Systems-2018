/***********************
 * Header file for Node class
 * ********************/

class Node {
public:
    
    // Constructor
    Node(Node*, bool);
    
    // Member functions
    void setNext(Node*);
    void setPrev(Node*);
    Node* getNext();
    Node* getPrev();
    int getValue();

private:
    Node *prev;
    Node *next;
    int value;
};
