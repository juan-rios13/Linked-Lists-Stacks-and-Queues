//
// Author : Juan Rios
//
// Programming Assignment Number 4
//
// Spring 2022 - CS 3358 - 252
//
// Due Date : 3/11/2022
//
// Instructor: Husain Gholoom.
//
/* Write a C++ program that will simulate a ADT stack / queue
using a linked List ADT with actual pointers that performs various functions */

#include <iostream>

using namespace std;

class stack
{
    private:
            struct Node
            {
                char data; //holds letter value of node
                Node *link; //ptr to next node
            };
            Node* top; //head of node
            Node* temp; //temp variable to hold node

    public:
            void createStack(); //done
            void displayStack(); //done
            void insertW();
            void insertX ();
            void pop();
            void deleteStack();
            void removeW();

};

class queue
{
    private:
            struct Node
            {
                char data; //holds letter value in node
                Node *link; //ptr to next node
            };
            Node* front=NULL; //head of queue
            Node* rear=NULL; //rear of queue
            Node* temp;      //temp variable to hold node
    public:
            void displayQueue(); 
            void createQueue(); 
            void insertXqueue();
            void insertAqueue();
            void dequeue();
            void remove4thqueue();
            void minMax();
            void deleteQueue();
            void removeX();




};



void stack::displayStack()
{

     if (top==NULL)
    {
        cout << "stack is empty"<<endl;

    }
    else
    {
    	temp = top;
    	cout<<"The stack currently contains: ";
    	while(temp!=NULL)
    {
           cout << temp->data << " , ";
           temp = temp->link;
    }
    }

}





void queue::displayQueue()
{
   temp = front;
   if (temp == NULL)
    {
      cout<<"Queue is empty"<<endl;
    }
   else
   {
   cout<<"Queue elements are: ";
   while (temp != NULL) 
   {
      cout<<temp->data<<" , ";
      temp = temp->link;
   }
   cout<<endl;
   }
}

void queue:: createQueue()
{
    cout<<"Queue being generated..."<<endl;
    cout<<endl;
    cout<<"Enter 5 uppercase letters between H and S"<<endl;
    int counter=0; //counter variable to determine and validate letter entires
    char letter; //user entered letts to insert into queue
    while (counter!=5)
    {
        cin>>letter;
        if(letter>='H' && letter<='S')
        {
   if (rear == NULL) 
   {
      rear = (Node *)malloc(sizeof(Node));
      rear->link = NULL;
      rear->data = letter;
      front = rear;
   } 
   else 
   {
      temp=(Node *)malloc(sizeof(Node));
      rear->link = temp;
      temp->data = letter;
      temp->link = NULL;
      rear = temp;
   }
   counter++;
        }
    else
        {
            cout<<"Invalid entry. Please try again."<<endl;
        }

    }
}

void stack::createStack()
{
    cout<<endl;
    cout<<"Stack being generated..."<<endl;
    cout<<endl;
    cout<<"Enter 5 uppercase letters between C and K"<<endl;
    int counter=0; //counter variable to determine and validate letter entires
    char letter;  //user entered letts to insert into queue
    while(counter!=5 )
    {
        cin>>letter;
        if(letter>='C' && letter<='K')
        {

             
    Node* temp = new Node(); //dyanmically allocated new node

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "stack is full"<<endl;
        
    }

    temp->data = letter;
    temp->link = top;
    top = temp;
    counter++;
        }
         else
        {
            cout<<"Invalid entry. Please try again."<<endl;
        }
    }

}

void queue::insertXqueue()
{
    cout<<"Inserting X into queue..."<<endl;
    char letter='X'; //Letter to insert into queue
    if (rear == NULL) {
      rear = (Node *)malloc(sizeof(Node));
      rear->link = NULL;
      rear->data = letter;
      front = rear;
   } else {
      temp=(Node *)malloc(sizeof(Node));
      rear->link = temp;
      temp->data = letter;
      temp->link = NULL;
      rear = temp;
   }
}

void stack::insertW()
{
    cout<<"Inserting W into stack..."<<endl;
    char letter='W'; //letter to insert into stack
     Node* temp = new Node();
    if (!temp)
    {
        cout << "Stack is full"<<endl;
    }

    temp->data = letter;
    temp->link = top;
    top = temp;
}

void stack::insertX()
{
     cout<<"Inserting X into stack..."<<endl;
     char letter='X'; //letter to insert into stack
     Node* temp = new Node();
    if (!temp)
    {
        cout << "Stack is full"<<endl;
        
    }
    temp->data = letter;
    temp->link = top;
    top = temp;
}

void stack::pop()
{
    cout<<"Removing first element of stack"<<endl;
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
        
    }
    else
    {
        temp = top;
        top = top->link;
	delete(temp);
    }
}



void queue:: insertAqueue()
{
    cout<<"Inserting A into second position in the queue..."<<endl;
    int counter=0; //counter variable to validate position of value to be inserted
    char letter='A'; //value to be inserted
    Node *newNode; // ptr to new node
    Node *nodePtr; // ptr to traverse list
    Node *previousNode; // node previous to nodePtr
    newNode = new Node;
    newNode->data = letter;
    nodePtr = front;
    previousNode = NULL;
    while (counter!=1) {
    previousNode = nodePtr; // save
    nodePtr = nodePtr->link; // advance
    counter++;
}
 if (previousNode == NULL) { //insert before first
front = newNode;
newNode->link = nodePtr;
 }
 else { //insert after previousNode
previousNode->link = newNode;
newNode->link = nodePtr;
 }
}

void queue:: dequeue() {
  Node* temp = front; //temp ptr ot head
   if (temp == NULL) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   else
   if (temp->link != NULL) {
      temp = temp->link;
      cout<<"Element being deleted from queue is : "<<front->data<<endl;
      delete(front);
      front = temp;
   } else {
      cout<<"Element being deleted from queue is : "<<front->data<<endl;
      front=front->link;
      delete(front);
   }
}


void queue:: remove4thqueue()
{
    cout<<"Fourth position in queue being removed..."<<endl;
     Node* nodeTodelete; //node to be removed
     temp = front; 
    for(int i = 0; i < 2; i++) {
      if(temp != NULL) {
        temp = temp->link;



      }
    }
        nodeTodelete = temp->link;
        temp->link = temp->link->link;
        delete(nodeTodelete);
    }

void queue::minMax()
{
        temp=front;
        char max=front->data; //variable to hold max ASCII value
        char min=front->data; //varibael to hold min ASCII value
    while(temp!=NULL)
    {
        if (max<temp->data)
            max=temp->data;
        if(min>temp->data)
            min=temp->data;
        temp=temp->link;

    }

    cout<<"Max value in queue is "<<max<<endl;;
    cout<<"Min value in queue is "<<min<<endl;
}


void stack::deleteStack() {
    cout<<"Stack being emptied..."<<endl;
    temp=top;
     while(temp!=NULL) // as I am considering tail->next = NULL
{   
    top->link = temp->link;
    temp->link = NULL;
    delete(temp);
    temp = top->link;
}
top=NULL;
    }
 


void queue::deleteQueue() {
    cout<<"Queue being emptied..."<<endl;
 Node*nodePtr; // traversal ptr
 Node *nextNode; // saves the next node
 nodePtr = front; //start at head of list
 while (nodePtr) {
nextNode = nodePtr->link; // save the next
delete nodePtr; // delete current
nodePtr = nextNode; // advance ptr
 }
 front=NULL;
 rear=NULL;
}

void stack:: removeW()
{
    cout<<"W being removed from stack..."<<endl;
    Node *nodePtr=top;
    Node *previousPtr;

if(top==NULL)
{
    cout<<"Error: Stack is empty."<<endl;
}

 else if (top->data == 'W')
{   // if first node is num
nodePtr = top;
top = nodePtr->link;
delete nodePtr;
 }
else
{
  while ( nodePtr->data!='W')
  {
      previousPtr=nodePtr;
      nodePtr=nodePtr->link;

  }
  previousPtr->link=nodePtr->link;
  delete(nodePtr);
}
}



void queue:: removeX()
{
    cout<<"X being removed from queue..."<<endl;
    Node *nodePtr=front; //traversal ptr
    Node *previousPtr; //ptr to previous value

if(nodePtr==NULL )
{
    cout<<"Error: Queue is empty."<<endl;
}

else if (front->data == 'X')
{ // if first node is num
nodePtr = front;
front = nodePtr->link;
delete nodePtr;
 }
else
{
  while (nodePtr && nodePtr->data!='X')
  {
      previousPtr=nodePtr;
      nodePtr=nodePtr->link;

  }
  previousPtr->link=nodePtr->link;
  delete(nodePtr);
}

}


int main()
{
    cout << "Linked List, Stack, Queue Operations" << endl;
    char choice; //choice to end or continue program
    while (choice!='X')
    {
    stack letterStack; //stack holding variable
    queue letterQueue; //queue holding variable
    letterStack.createStack();
    letterQueue.createQueue();
    letterStack.insertW();
    letterStack.insertX();
    letterStack.pop();
    letterQueue.insertXqueue();
    letterQueue.insertAqueue();
    letterQueue.dequeue();
    letterQueue.remove4thqueue();
    letterStack.displayStack();
    letterQueue.displayQueue();
    letterQueue.minMax();
    letterStack.deleteStack();
    letterStack.displayStack();
    letterQueue.displayQueue();
    letterStack.removeW();
    letterQueue.deleteQueue();
    letterStack.displayStack();
    letterQueue.displayQueue();
    letterQueue.removeX();
    cout<<"Would you like to continue the program? Enter X to exit and any other character to continue:";
    cin>>choice;
    cout<<endl;
    }

    cout<<"LL / Stack & Queue Program is Implemented By : Juan Rios"<<endl;
    cout<<"Husain Gholoom - March 11th, 2022"<<endl;

    return 0;
}
