#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    //cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <typename T>
class DoublyLL
{
private:
    nodeDL<T> *First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);        
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <typename T>
DoublyLL<T>::DoublyLL()
{
    //cout << "Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <typename T>
void DoublyLL<T>::Display()
{
    nodeDL<T> *temp = First;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <typename T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <typename T>
void DoublyLL<T>::InsertFirst(T No)
{
    nodeDL<T> *newn = new nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <typename T>
void DoublyLL<T>::InsertLast(T No)
{
    nodeDL<T> *newn = new nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeDL<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <typename T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
    }
    else if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        nodeDL<T> *newn = new nodeDL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        nodeDL<T> *temp1 = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        nodeDL<T> *temp2 = temp1->next;

        temp1->next = newn;
        newn->prev = temp1;
        newn->next = temp2;
        temp2->prev = newn;

        iCount++;
    }
}

template <typename T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        nodeDL<T> *temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
        iCount--;
    }
}

template <typename T>
void DoublyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        nodeDL<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
        iCount--;
    }
}

template <typename T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid Position\n";
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        nodeDL<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        nodeDL<T> *tempDelete = temp->next;
        temp->next = tempDelete->next;
        tempDelete->next->prev = temp;
        delete tempDelete;
        iCount--;
    }
}




/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
struct nodeSC {
  T data;
  struct nodeSC * next;
};

template <typename T>
class SinglyCLL {
private:
    int iCount;
    nodeSC<T> * First;
    nodeSC<T> * Last;

public:
    SinglyCLL();

    void Display();
    int Count();

    void InsertLast(T No);
    void InsertFirst(T No);
    void InsertAtPos(T No, int Pos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int Pos);
};

template <typename T>
SinglyCLL<T>::SinglyCLL() {
  First = NULL;
  Last = NULL;
  iCount = 0;
}

template <typename T>
void SinglyCLL<T>::Display() {
  if (First == NULL) {
    cout << "Linked List is empty" << endl;
    return;
  }

  nodeSC<T> * temp = First;
  do {
    cout << "|" << temp->data << "|-> ";
    temp = temp->next;
  } while (temp != Last->next);
  cout << endl;
}

template <typename T>
int SinglyCLL<T>::Count() {
  return iCount;
}

template <typename T>
void SinglyCLL<T>::InsertFirst(T No) {
  nodeSC<T> * newn = new nodeSC<T>;

  newn->data = No;
  newn->next = NULL;

  if (First == NULL) {
    First = newn;
    Last = newn;
  } else {
    newn->next = First;
    First = newn;
  }
  Last->next = First;
  iCount++;
}

template <typename T>
void SinglyCLL<T>::InsertLast(T No) {
  nodeSC<T> * newn = new nodeSC<T>;

  newn->data = No;
  newn->next = NULL;

  if ((First == NULL) && (Last == NULL)) {
    First = newn;
    Last = newn;
  } else {
    Last->next = newn;
    Last = newn;
  }
  Last->next = First;
  iCount++;
}

template <typename T>
void SinglyCLL<T>::InsertAtPos(T No, int Pos) {
  if ((Pos < 1) || (Pos > (iCount + 1))) {
    cout << "Invalid Position" << endl;
    return;
  }

  if (Pos == 1) {
    InsertFirst(No);
  } else if (Pos == (iCount + 1)) {
    InsertLast(No);
  } else {
    nodeSC<T> * newn = new nodeSC<T>;
    nodeSC<T> * temp = First;
    int i = 0;
    newn->data = No;
    newn->next = NULL;

    for (i = 1; i < (Pos - 1); i++) {
      temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;

    iCount++;
  }
}

template <typename T>
void SinglyCLL<T>::DeleteFirst() {
  if ((First == NULL) && (Last == NULL)) {
    cout << "Linked List is already empty" << endl;
    return;
  } else if (First == Last) {
    delete First;
    First = NULL;
    Last = NULL;
  } else {
    nodeSC<T> * temp = First;
    First = First->next;
    delete temp;
    Last->next = First;
  }
  iCount--;
}

template <typename T>
void SinglyCLL<T>::DeleteLast() {
  if ((First == NULL) && (Last == NULL)) {
    cout << "Linked List is already empty" << endl;
    return;
  } else if (First == Last) {
    delete First;
    First = NULL;
    Last = NULL;
  } else {
    nodeSC<T> * temp = First;
    while (temp->next != Last) {
      temp = temp->next;
    }
    delete Last;
    Last = temp;
    Last->next = First;
  }
  iCount--;
}

template <typename T>
void SinglyCLL<T>::DeleteAtPos(int Pos) {
  if (Pos < 1 || Pos > iCount) {
    cout << "Invalid Position" << endl;
    return;
  }

  if (Pos == 1) {
    DeleteFirst();
  } else if (Pos == iCount) {
    DeleteLast();
  } else {
    nodeSC<T> * temp1 = First;
    nodeSC<T> * temp2 = NULL;
    int i = 0;
    for (i = 1; i < (Pos - 1); i++) {
      temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;

    iCount--;
  }
}




/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <typename T>
class Stack
{
private:
    nodeS<T>* First;
    int iCount;

public:
    Stack();
    void Display();
    int Count();
    void Push(T No);  // InsertFirst()
    T Pop();   // DeleteFirst()
};

template <typename T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <typename T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";
    nodeS<T>* temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

template <typename T>
int Stack<T>::Count()
{
    return iCount;
}

template <typename T>
void Stack<T>::Push(T No)
{
    nodeS<T>* newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <typename T>
T Stack<T>::Pop()
{
    if (First == NULL)
    {
        cout << "Unable to pop the element as stack is empty\n";
        return T();  // Return default value for type T
    }
    else
    {
        nodeS<T>* temp = First;
        T iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;
        return iValue;
    }
}




/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <typename T>
class Queue
{
private:
    nodeQ<T>* First;
    int iCount;

public:
    Queue();
    void Display();
    int Count();
    void EnQueue(T No);  // InsertLast()
    T DeQueue();   // DeleteFirst()
};

template <typename T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <typename T>
void Queue<T>::Display()
{
    cout << "Elements of Queue are : \n";
    nodeQ<T>* temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <typename T>
int Queue<T>::Count()
{
    return iCount;
}

template <typename T>
void Queue<T>::EnQueue(T No)
{
    nodeQ<T>* newn = new nodeQ<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeQ<T>* temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <typename T>
T Queue<T>::DeQueue()
{
    if (First == NULL)
    {
        cout << "Unable to remove the element as queue is empty\n";
        return T();  // Return default value for type T
    }
    else
    {
        nodeQ<T>* temp = First;
        T iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;
        return iValue;
    }
}


using namespace std;

int main() {
    int choice1 = 0, choice2 = 0, pos = 0;
    int data;
    cout<<"----------------------------------------------------------------------\n";
    cout<<"------------------- Welcome To LinkedListLibrary ---------------------\n";
    cout<<"----------------------------------------------------------------------\n";
    // Instantiate the data structures
    SinglyLL<int> sll;
    DoublyLL<int> dll;
    DoublyCL<int> dcl;
    SinglyCLL<int> scl;
    Stack<int> stack;
    Queue<int> queue;

    while (true) {
        cout << "\nChoose a data structure to work with:\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Doubly Circular Linked List\n";
        cout << "4. Singly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        if (choice1 == 7) break;

        while (true) {
            cout << "\nChoose an operation:\n";
            cout << "1. Insert First\n";
            cout << "2. Insert Last\n";
            cout << "3. Insert at Position\n";
            cout << "4. Delete First\n";
            cout << "5. Delete Last\n";
            cout << "6. Delete at Position\n";
            cout << "7. Display\n";
            cout << "8. Count\n";
            cout << "9. Go Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            if (choice2 == 9) break;

            switch (choice2) {
                case 1:
                    cout << "Enter data: ";
                    cin >> data;
                    switch (choice1) {
                        case 1: sll.InsertFirst(data); break;
                        case 2: dll.InsertFirst(data); break;
                        case 3: dcl.InsertFirst(data); break;
                        case 4: scl.InsertFirst(data); break;
                        case 5: stack.Push(data); break;
                        case 6: queue.EnQueue(data); break;
                    }
                    break;

                case 2:
                    cout << "Enter data: ";
                    cin >> data;
                    switch (choice1) {
                        case 1: sll.InsertLast(data); break;
                        case 2: dll.InsertLast(data); break;
                        case 3: dcl.InsertLast(data); break;
                        case 4: scl.InsertLast(data); break;
                        case 6: queue.EnQueue(data); break;
                    }
                    break;

                case 3:
                    cout << "Enter data: ";
                    cin >> data;
                    cout << "Enter position: ";
                    cin >> pos;
                    switch (choice1) {
                        case 1: sll.InsertAtPos(data, pos); break;
                        case 2: dll.InsertAtPos(data, pos); break;
                        case 3: dcl.InsertAtPos(data, pos); break;
                        case 4: scl.InsertAtPos(data, pos); break;
                    }
                    break;

                case 4:
                    switch (choice1) {
                        case 1: sll.DeleteFirst(); break;
                        case 2: dll.DeleteFirst(); break;
                        case 3: dcl.DeleteFirst(); break;
                        case 4: scl.DeleteFirst(); break;
                        case 5: stack.Pop(); break;
                        case 6: queue.DeQueue(); break;
                    }
                    break;

                case 5:
                    switch (choice1) {
                        case 1: sll.DeleteLast(); break;
                        case 2: dll.DeleteLast(); break;
                        case 3: dcl.DeleteLast(); break;
                        case 4: scl.DeleteLast(); break;
                    }
                    break;

                case 6:
                    cout << "Enter position: ";
                    cin >> pos;
                    switch (choice1) {
                        case 1: sll.DeleteAtPos(pos); break;
                        case 2: dll.DeleteAtPos(pos); break;
                        case 3: dcl.DeleteAtPos(pos); break;
                        case 4: scl.DeleteAtPos(pos); break;
                    }
                    break;

                case 7:
                    switch (choice1) {
                        case 1: sll.Display(); break;
                        case 2: dll.Display(); break;
                        case 3: dcl.Display(); break;
                        case 4: scl.Display(); break;
                        case 5: stack.Display(); break;
                        case 6: queue.Display(); break;
                    }
                    break;

                case 8:
                    switch (choice1) {
                        case 1: cout << "Count: " << sll.Count() << endl; break;
                        case 2: cout << "Count: " << dll.Count() << endl; break;
                        case 3: cout << "Count: " << dcl.Count() << endl; break;
                        case 4: cout << "Count: " << scl.Count() << endl; break;
                        case 5: cout << "Count: " << stack.Count() << endl; break;
                        case 6: cout << "Count: " << queue.Count() << endl; break;
                    }
                    break;
            }
        }
    }
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"------------------- Thank You For Using LinkedListLibrary ---------------------\n";
    cout<<"-------------------------------------------------------------------------------\n";
    return 0;
}



// int main()
// {
//     // Singly Linked List of integers
//     cout << "-------------- Singly Linked List of Integers --------------\n";

//     SinglyLL<int> *iobj = new SinglyLL<int>();

//     int iRet = 0;

//     iobj->InsertFirst(51);
//     iobj->InsertFirst(21);
//     iobj->InsertFirst(11);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->InsertLast(101);
//     iobj->InsertLast(111);
//     iobj->InsertLast(121);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->InsertAtPos(105, 5);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->DeleteAtPos(5);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->DeleteFirst();
//     iobj->DeleteLast();

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete iobj;

//     // Doubly Linked List of integers
//     cout << "-------------- Doubly Linked List of Integers --------------\n";

//     DoublyLL<int> *dobj = new DoublyLL<int>();

//     dobj->InsertFirst(51);
//     dobj->InsertFirst(21);
//     dobj->InsertFirst(11);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->InsertLast(101);
//     dobj->InsertLast(111);
//     dobj->InsertLast(121);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->InsertAtPos(105, 5);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->DeleteAtPos(5);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->DeleteFirst();
//     dobj->DeleteLast();

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete dobj;

//     // Doubly Circular Linked List of integers
//     cout << "-------------- Doubly Circular Linked List of Integers --------------\n";

//     DoublyCL<int> *dcobj = new DoublyCL<int>();

//     dcobj->InsertFirst(51);
//     dcobj->InsertFirst(21);
//     dcobj->InsertFirst(11);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->InsertLast(101);
//     dcobj->InsertLast(111);
//     dcobj->InsertLast(121);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->InsertAtPos(105, 5);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->DeleteAtPos(5);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->DeleteFirst();
//     dcobj->DeleteLast();

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete dcobj;

//     // Singly Circular Linked List of integers
//     cout << "-------------- Singly Circular Linked List of Integers --------------\n";

//     SinglyCLL<int> *scobj = new SinglyCLL<int>();

//     scobj->InsertFirst(51);
//     scobj->InsertFirst(21);
//     scobj->InsertFirst(11);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->InsertLast(101);
//     scobj->InsertLast(111);
//     scobj->InsertLast(121);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->InsertAtPos(105, 5);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->DeleteAtPos(5);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->DeleteFirst();
//     scobj->DeleteLast();

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete scobj;

//     // Stack of integers
//     cout << "-------------- Stack of Integers --------------\n";

//     Stack<int> *sobj = new Stack<int>();

//     sobj->Push(11);
//     sobj->Push(21);
//     sobj->Push(51);
//     sobj->Push(101);

//     sobj->Display();
//     iRet = sobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     int iValue = sobj->Pop();
//     cout << "Popped element is : " << iValue << endl;

//     sobj->Display();
//     iRet = sobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete sobj;

//     // Queue of integers
//     cout << "-------------- Queue of Integers --------------\n";

//     Queue<int> *qobj = new Queue<int>();

//     qobj->EnQueue(11);
//     qobj->EnQueue(21);
//     qobj->EnQueue(51);
//     qobj->EnQueue(101);

//     qobj->Display();
//     iRet = qobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iValue = qobj->DeQueue();
//     cout << "Dequeued element is : " << iValue << endl;

//     qobj->Display();
//     iRet = qobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete qobj;


//     // Singly Linked List of characters
//     cout << "-------------- Singly Linked List of Characters --------------\n";

//     SinglyLL<char> *cSLL = new SinglyLL<char>();

//     cSLL->InsertFirst('A');
//     cSLL->InsertFirst('B');
//     cSLL->InsertFirst('C');

//     cSLL->Display();
//     int iRet = cSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSLL->InsertLast('D');
//     cSLL->InsertLast('E');
//     cSLL->InsertLast('F');

//     cSLL->Display();
//     iRet = cSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSLL->InsertAtPos('X', 3);

//     cSLL->Display();
//     iRet = cSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSLL->DeleteAtPos(3);

//     cSLL->Display();
//     iRet = cSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSLL->DeleteFirst();
//     cSLL->DeleteLast();

//     cSLL->Display();
//     iRet = cSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cSLL;

//     // Doubly Linked List of characters
//     cout << "-------------- Doubly Linked List of Characters --------------\n";

//     DoublyLL<char> *cDLL = new DoublyLL<char>();

//     cDLL->InsertFirst('P');
//     cDLL->InsertFirst('Q');
//     cDLL->InsertFirst('R');

//     cDLL->Display();
//     iRet = cDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDLL->InsertLast('S');
//     cDLL->InsertLast('T');
//     cDLL->InsertLast('U');

//     cDLL->Display();
//     iRet = cDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDLL->InsertAtPos('Y', 4);

//     cDLL->Display();
//     iRet = cDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDLL->DeleteAtPos(4);

//     cDLL->Display();
//     iRet = cDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDLL->DeleteFirst();
//     cDLL->DeleteLast();

//     cDLL->Display();
//     iRet = cDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cDLL;

//     // Doubly Circular Linked List of characters
//     cout << "-------------- Doubly Circular Linked List of Characters --------------\n";

//     DoublyCL<char> *cDCL = new DoublyCL<char>();

//     cDCL->InsertFirst('X');
//     cDCL->InsertFirst('Y');
//     cDCL->InsertFirst('Z');

//     cDCL->Display();
//     iRet = cDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDCL->InsertLast('A');
//     cDCL->InsertLast('B');
//     cDCL->InsertLast('C');

//     cDCL->Display();
//     iRet = cDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDCL->InsertAtPos('W', 4);

//     cDCL->Display();
//     iRet = cDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDCL->DeleteAtPos(4);

//     cDCL->Display();
//     iRet = cDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cDCL->DeleteFirst();
//     cDCL->DeleteLast();

//     cDCL->Display();
//     iRet = cDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cDCL;

//     // Singly Circular Linked List of characters
//     cout << "-------------- Singly Circular Linked List of Characters --------------\n";

//     SinglyCLL<char> *cSCL = new SinglyCLL<char>();

//     cSCL->InsertFirst('K');
//     cSCL->InsertFirst('L');
//     cSCL->InsertFirst('M');

//     cSCL->Display();
//     iRet = cSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSCL->InsertLast('N');
//     cSCL->InsertLast('O');
//     cSCL->InsertLast('P');

//     cSCL->Display();
//     iRet = cSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSCL->InsertAtPos('J', 4);

//     cSCL->Display();
//     iRet = cSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSCL->DeleteAtPos(4);

//     cSCL->Display();
//     iRet = cSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cSCL->DeleteFirst();
//     cSCL->DeleteLast();

//     cSCL->Display();
//     iRet = cSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cSCL;

//     // Stack of characters
//     cout << "-------------- Stack of Characters --------------\n";

//     Stack<char> *cStack = new Stack<char>();

//     cStack->Push('A');
//     cStack->Push('B');
//     cStack->Push('C');
//     cStack->Push('D');

//     cStack->Display();
//     iRet = cStack->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     char cValue = cStack->Pop();
//     cout << "Popped element is : " << cValue << endl;

//     cStack->Display();
//     iRet = cStack->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cStack;

//     // Queue of characters
//     cout << "-------------- Queue of Characters --------------\n";

//     Queue<char> *cQueue = new Queue<char>();

//     cQueue->EnQueue('E');
//     cQueue->EnQueue('F');
//     cQueue->EnQueue('G');
//     cQueue->EnQueue('H');

//     cQueue->Display();
//     iRet = cQueue->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     cValue = cQueue->DeQueue();
//     cout << "Dequeued element is : " << cValue << endl;

//     cQueue->Display();
//     iRet = cQueue->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete cQueue;

//     // Singly Linked List of floats
//     cout << "-------------- Singly Linked List of Floats --------------\n";

//     SinglyLL<float> *fSLL = new SinglyLL<float>();

//     fSLL->InsertFirst(1.1f);
//     fSLL->InsertFirst(2.2f);
//     fSLL->InsertFirst(3.3f);

//     fSLL->Display();
//     iRet = fSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSLL->InsertLast(4.4f);
//     fSLL->InsertLast(5.5f);
//     fSLL->InsertLast(6.6f);

//     fSLL->Display();
//     iRet = fSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSLL->InsertAtPos(7.7f, 4);

//     fSLL->Display();
//     iRet = fSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSLL->DeleteAtPos(4);

//     fSLL->Display();
//     iRet = fSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSLL->DeleteFirst();
//     fSLL->DeleteLast();

//     fSLL->Display();
//     iRet = fSLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fSLL;

//     // Doubly Linked List of floats
//     cout << "-------------- Doubly Linked List of Floats --------------\n";

//     DoublyLL<float> *fDLL = new DoublyLL<float>();

//     fDLL->InsertFirst(9.9f);
//     fDLL->InsertFirst(8.8f);
//     fDLL->InsertFirst(7.7f);

//     fDLL->Display();
//     iRet = fDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDLL->InsertLast(6.6f);
//     fDLL->InsertLast(5.5f);
//     fDLL->InsertLast(4.4f);

//     fDLL->Display();
//     iRet = fDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDLL->InsertAtPos(3.3f, 4);

//     fDLL->Display();
//     iRet = fDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDLL->DeleteAtPos(4);

//     fDLL->Display();
//     iRet = fDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDLL->DeleteFirst();
//     fDLL->DeleteLast();

//     fDLL->Display();
//     iRet = fDLL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fDLL;

//     // Doubly Circular Linked List of floats
//     cout << "-------------- Doubly Circular Linked List of Floats --------------\n";

//     DoublyCL<float> *fDCL = new DoublyCL<float>();

//     fDCL->InsertFirst(5.5f);
//     fDCL->InsertFirst(4.4f);
//     fDCL->InsertFirst(3.3f);

//     fDCL->Display();
//     iRet = fDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDCL->InsertLast(2.2f);
//     fDCL->InsertLast(1.1f);
//     fDCL->InsertLast(0.0f);

//     fDCL->Display();
//     iRet = fDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDCL->InsertAtPos(8.8f, 4);

//     fDCL->Display();
//     iRet = fDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDCL->DeleteAtPos(4);

//     fDCL->Display();
//     iRet = fDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fDCL->DeleteFirst();
//     fDCL->DeleteLast();

//     fDCL->Display();
//     iRet = fDCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fDCL;

//     // Singly Circular Linked List of floats
//     cout << "-------------- Singly Circular Linked List of Floats --------------\n";

//     SinglyCLL<float> *fSCL = new SinglyCLL<float>();

//     fSCL->InsertFirst(7.7f);
//     fSCL->InsertFirst(6.6f);
//     fSCL->InsertFirst(5.5f);

//     fSCL->Display();
//     iRet = fSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSCL->InsertLast(4.4f);
//     fSCL->InsertLast(3.3f);
//     fSCL->InsertLast(2.2f);

//     fSCL->Display();
//     iRet = fSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSCL->InsertAtPos(1.1f, 4);

//     fSCL->Display();
//     iRet = fSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSCL->DeleteAtPos(4);

//     fSCL->Display();
//     iRet = fSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fSCL->DeleteFirst();
//     fSCL->DeleteLast();

//     fSCL->Display();
//     iRet = fSCL->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fSCL;

//     // Stack of floats
//     cout << "-------------- Stack of Floats --------------\n";

//     Stack<float> *fStack = new Stack<float>();

//     fStack->Push(1.1f);
//     fStack->Push(2.2f);
//     fStack->Push(3.3f);
//     fStack->Push(4.4f);

//     fStack->Display();
//     iRet = fStack->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     float fValue = fStack->Pop();
//     cout << "Popped element is : " << fValue << endl;

//     fStack->Display();
//     iRet = fStack->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fStack;

//     // Queue of floats
//     cout << "-------------- Queue of Floats --------------\n";

//     Queue<float> *fQueue = new Queue<float>();

//     fQueue->EnQueue(1.1f);
//     fQueue->EnQueue(2.2f);
//     fQueue->EnQueue(3.3f);
//     fQueue->EnQueue(4.4f);

//     fQueue->Display();
//     iRet = fQueue->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     fValue = fQueue->DeQueue();
//     cout << "Dequeued element is : " << fValue << endl;

//     fQueue->Display();
//     iRet = fQueue->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete fQueue;

//      // Singly Linked List of doubles
//     cout << "-------------- Singly Linked List of Doubles --------------\n";

//     SinglyLL<double> *iobj = new SinglyLL<double>();

    

//     iobj->InsertFirst(51.1);
//     iobj->InsertFirst(21.2);
//     iobj->InsertFirst(11.3);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->InsertLast(101.4);
//     iobj->InsertLast(111.5);
//     iobj->InsertLast(121.6);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->InsertAtPos(105.7, 5);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->DeleteAtPos(5);

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     iobj->DeleteFirst();
//     iobj->DeleteLast();

//     iobj->Display();
//     iRet = iobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete iobj;

//     // Doubly Linked List of doubles
//     cout << "-------------- Doubly Linked List of Doubles --------------\n";

//     DoublyLL<double> *dobj = new DoublyLL<double>();

//     dobj->InsertFirst(51.1);
//     dobj->InsertFirst(21.2);
//     dobj->InsertFirst(11.3);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->InsertLast(101.4);
//     dobj->InsertLast(111.5);
//     dobj->InsertLast(121.6);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->InsertAtPos(105.7, 5);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->DeleteAtPos(5);

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dobj->DeleteFirst();
//     dobj->DeleteLast();

//     dobj->Display();
//     iRet = dobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete dobj;

//     // Doubly Circular Linked List of doubles
//     cout << "-------------- Doubly Circular Linked List of Doubles --------------\n";

//     DoublyCL<double> *dcobj = new DoublyCL<double>();

//     dcobj->InsertFirst(51.1);
//     dcobj->InsertFirst(21.2);
//     dcobj->InsertFirst(11.3);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->InsertLast(101.4);
//     dcobj->InsertLast(111.5);
//     dcobj->InsertLast(121.6);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->InsertAtPos(105.7, 5);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->DeleteAtPos(5);

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dcobj->DeleteFirst();
//     dcobj->DeleteLast();

//     dcobj->Display();
//     iRet = dcobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete dcobj;

//     // Singly Circular Linked List of doubles
//     cout << "-------------- Singly Circular Linked List of Doubles --------------\n";

//     SinglyCLL<double> *scobj = new SinglyCLL<double>();

//     scobj->InsertFirst(51.1);
//     scobj->InsertFirst(21.2);
//     scobj->InsertFirst(11.3);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->InsertLast(101.4);
//     scobj->InsertLast(111.5);
//     scobj->InsertLast(121.6);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->InsertAtPos(105.7, 5);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->DeleteAtPos(5);

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     scobj->DeleteFirst();
//     scobj->DeleteLast();

//     scobj->Display();
//     iRet = scobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete scobj;

//     // Stack of doubles
//     cout << "-------------- Stack of Doubles --------------\n";

//     Stack<double> *sobj = new Stack<double>();

//     sobj->Push(11.1);
//     sobj->Push(21.2);
//     sobj->Push(51.3);
//     sobj->Push(101.4);

//     sobj->Display();
//     iRet = sobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     double dValue = sobj->Pop();
//     cout << "Popped element is : " << dValue << endl;

//     sobj->Display();
//     iRet = sobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete sobj;

//     // Queue of doubles
//     cout << "-------------- Queue of Doubles --------------\n";

//     Queue<double> *qobj = new Queue<double>();

//     qobj->EnQueue(11.1);
//     qobj->EnQueue(21.2);
//     qobj->EnQueue(51.3);
//     qobj->EnQueue(101.4);

//     qobj->Display();
//     iRet = qobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     dValue = qobj->DeQueue();
//     cout << "Dequeued element is : " << dValue << endl;

//     qobj->Display();
//     iRet = qobj->Count();
//     cout << "Number of elements are : " << iRet << endl;

//     delete qobj;
//     return 0;
// }



