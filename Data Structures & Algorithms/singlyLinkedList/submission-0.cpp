#include<iostream>

struct Node {
    int data;
    Node* link;

    Node(int val) : data(val),link(nullptr){}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    int get(int index) {
        Node* temp = head;
        int idx = 0;
        while((idx++ < index) && (temp != nullptr)) {
            temp=temp->link;
        }
        if(temp == nullptr) return -1;
        return temp->data;

    }

    void insertHead(int val) {
        Node* newNode = new Node(val);        
        newNode->link = head;
        head = newNode;               
    }
    
    void insertTail(int val) {       
        Node* newNode = new Node(val);
        newNode->link = nullptr;        
        Node* temp = head;
        if(temp==nullptr)
        {
            head = newNode;
        }
        else {
            while(temp->link != nullptr) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }

    bool remove(int index) {
       if( head == nullptr) return false;

       Node* temp = head;
       if(index == 0) {  
        head = head->link;      
        delete temp;       
        return true;
       }
        Node* curr = head->link;
        Node* prev = head;
        int idx = 1;
        while((idx++ < index) && (curr != nullptr)) {
            prev = curr;
            curr=curr->link;
        }
        if(curr == nullptr) return false;
        prev->link = (curr->link);
        delete curr;
        return true;
       
        
    }

    vector<int> getValues() {     
        std::vector<int> arr;       
        Node* temp1=head;
        while(temp1!=nullptr){
            arr.push_back(temp1->data);
            temp1=temp1->link;
        }
        return arr;        
    }
};
