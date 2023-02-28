#include "List.h"

//Constructor
List::List(): head(NULL){}


//Destructor
List::~List(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}


//Other functions
void List::add(Product* prod){
    Node* newNode = new Node();
    newNode->data = prod;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->getName() < currNode->data->getName()){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;
}

void List::remove(const string& name, Product** prod){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *prod = NULL;
        return;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *prod = currNode->data;
    delete currNode;
}

void List::get(const string& name, Product** prod){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *prod = NULL;
        return;
    }
    //currNode is not NULL
    *prod = currNode->data;
}

void List::removeUpTo(const string& name){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (name < currNode->data->getName()){
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }

    head = currNode;
}

void List::print() const{
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

/*
  Function:  isEmpty
  Purpose:   Check if list is empty
   return:   true if list is empty, otherwise false
*/
bool List::isEmpty() const{
  if(head == NULL){
    return true;
  }
  return false;
}

/*
  Function:  findProduct
  Purpose:   find product in list
   in:       product name
   in:       product pointee
   out:      return product if found
*/
void List::findProduct(const string& name, Product** prod) const{
  Node* nodeCurrent = head;
  bool found = false;

  while(nodeCurrent != NULL){
    if(nodeCurrent->data->getName() == name){
      *prod = nodeCurrent->data;
      found = true;
    }
    nodeCurrent = nodeCurrent->next;
  }
  if(found == false){
    *prod = NULL;
  }
}

//DONE
