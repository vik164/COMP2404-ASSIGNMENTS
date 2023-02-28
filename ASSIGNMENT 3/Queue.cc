#include "Queue.h"

//Constructor
Queue::Queue(){
  this->head = NULL;
  this->tail = NULL;
}


//Destructor
Queue::~Queue(){
  Node* nodeCurrent = head;
  Node* nodeNext = NULL;

  while(nodeCurrent != NULL){
      nodeNext = nodeCurrent->next;
      delete nodeCurrent;
      nodeCurrent = nodeNext;
  }
}


//Other functions
/*
  Function:  isEmpty
  Purpose:   Checks queue is empty
   return:   true if empty, otherwise false
*/
bool Queue::isEmpty() const{
  if(head == NULL){
    return true;
  }
  return false;
}

/*
  Function:  peekFirst
  Purpose:   get data in position one of queue
   in:       WHLocation pointee
   out:      return WHLocation data in position one
*/
void Queue::peekFirst(WHLocation** loc){
  if(head != NULL){
    *loc = head->data;
  }
  else{
      *loc = NULL;
  }
}

/*
  Function:  popFirst
  Purpose:   remove whLocation from position one in queue
   in:       WHLocation pointee
   out:      WHLocation is removed from queue
*/
void Queue::popFirst(WHLocation** loc){
  Node* nodeCurrent = head;

  if(nodeCurrent != NULL){
    *loc = nodeCurrent->data;
    head = nodeCurrent->next;
    delete nodeCurrent;
  }
  else{
      *loc = NULL;
  }
}

/*
  Function:  addLast
  Purpose:   add WHLocation to queue in last position
   in:       WHLocation
   out:      new WHLocation is added to queue in last position
*/
void Queue::addLast(WHLocation* loc){
  Node* nodeNew = new Node();
  nodeNew->data = loc;
  nodeNew->next = NULL;

  if(head == NULL){
    head = nodeNew;
    tail = nodeNew;
  }
  else{
    tail->next = nodeNew;
    tail = nodeNew;
  }
}

/*
  Function:  print
  Purpose:   Prints information in queue
   return:   nothing
*/
void Queue::print() const{
  Node* nodeCurrent = head;

  if(nodeCurrent == NULL){
    cout<<"LIST IS EMPTY!"<<endl;
  }
  else{
    while(nodeCurrent != NULL){
      nodeCurrent->data->print();
      nodeCurrent = nodeCurrent->next;
    }
  }
}

//DONE
