///////////////////////////////////////////////////////////////////
//                                                               //                 
//              Generic Data Structure Library                   //   
//                                                               //               
///////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////
//
//  Data structure - Singly Linear Linked List
//
//////////////////////////////////////////////////////////

template<class T> 
struct SLnode
{
    T data;
    struct SLnode<T> *next;
};

template<class T>
class SinglyLL
{
    public:
        struct SLnode<T> *Head;
        int iCount;
    
        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct SLnode<T> *newn = NULL;
    newn = new SLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct SLnode<T> *newn = NULL;
    newn = new SLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct SLnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        Head = Head->next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > (iCount+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iCount+1))
    {
        InsertLast(no);
    }
    else
    {
        struct SLnode<T> *newn = NULL;
        newn = new SLnode<T>;

        newn->data = no;
        newn->next = NULL;

        struct SLnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct SLnode<T> *temp = Head;
        struct SLnode<T> *tempX = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

//////////////////////////////////////////////////////////
//
//  Data structure - Doubly Linear Linked List
//
//////////////////////////////////////////////////////////

template<class T>  
struct DLnode
{
    T data;
    struct DLnode<T> *next;
    struct DLnode<T> *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct DLnode<T> *Head;
        int iCount;
    
    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct DLnode<T> *newn = NULL;
    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct DLnode<T> *newn = NULL;
    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct DLnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > (iCount+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iCount+1))
    {
        InsertLast(no);
    }
    else
    {
        struct DLnode<T> *newn = NULL;
        newn = new DLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct DLnode<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//////////////////////////////////////////////////////////
//
//  Data structure - Singly Circular Linked List
//
//////////////////////////////////////////////////////////

template<class T>   
struct SCnode
{
    T data;
    struct SCnode<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct SCnode<T> *Head;
        struct SCnode<T> *Tail;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SCnode<T> *newn = NULL;
    newn = new SCnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SCnode<T> *newn = NULL;
    newn = new SCnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;

    iCount++;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct SCnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Circular Linked List are : "<<endl;

    do 
    {
    cout<<"|"<<temp->data<<"| ->";
    temp = temp->next;
    }while(temp != Tail->next);
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
    }
    Tail->next = Head;

    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct SCnode<T> *temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        delete temp->next;
        Tail = temp;
    }
    Tail->next = Head;

    iCount--;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > (iCount+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iCount+1))
    {
        InsertLast(no);
    }
    else
    {
        struct SCnode<T> *newn = NULL;
        newn = new SCnode<T>;
        newn->data = no;
        newn->next = NULL;

        struct SCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct SCnode<T> *temp = Head;
        struct SCnode<T> *tempX = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

//////////////////////////////////////////////////////////
//
//  Data structure - Doubly Circular Linked List
//
//////////////////////////////////////////////////////////

template<class T>   
struct DCnode
{
    T data;
    struct DCnode<T> *next;
    struct DCnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DCnode<T> *Head;
        struct DCnode<T> *Tail;
        int iCount;
    
    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;

    iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    iCount++;
}

template<class T>
void DoublyCLL<T>::Display()
{
    struct DCnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Circular Linked List are : "<<endl;

    do 
    {
    cout<<"|"<<temp->data<<"| <->";
    temp = temp->next;
    }while(temp != Tail->next);
    cout<<"NULL"<<endl;
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    iCount--;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > (iCount+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iCount+1))
    {
        InsertLast(no);
    }
    else
    {
        struct DCnode<T> *newn = NULL;
        newn = new DCnode<T>;
        newn->data = no;
        newn->next = NULL;

        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//////////////////////////////////////////////////////////
//
//  Data structure - Stack
//
//////////////////////////////////////////////////////////

template <class T>   
struct SNode
{
    T data;
    struct SNode<T> *next;
};

template <class T>
class Stack
{
    private:
    struct SNode<T> *First;
    int iCount;

    public:
    Stack();
    void Push(T);
    void Pop();
    void Display();
    int Count();

};

template <class T>
Stack<T> :: Stack()
{
   First = NULL;
   iCount = 0;
}

template <class T>      // Insert First
void Stack<T> :: Push(T no)
{
    struct SNode<T> *newn = NULL;
    newn = new SNode<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
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
template <class T>  //DeleteFirst
void Stack<T> :: Pop()
{
    T no;
    struct SNode<T> *temp = NULL;
    temp = First;

    if(First == NULL)
    {
        cout<<"stack is empty\n";
        return;
    } 
    else if(First->next == NULL)
    {
        no = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        no = First->data; 
        First = temp->next;
        delete temp;
    }
    cout<<"Removed elements are : "<<no<<endl;
    iCount--;
    
}

template <class T>
void Stack<T> :: Display()
{
    struct SNode<T> *temp = First;

    if(First == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    else 
    {
        cout<<"Elements of stack are : \n";
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////
//
//  Data structure - Queue
//
//////////////////////////////////////////////////////////

template <class T>    
struct QNode
{
    T data;
    struct QNode<T> *next;
};

template <class T>
class Queue
{
    private:
    struct QNode<T> *First;
    int iCount;

    public:
    Queue();
    void Enqueue(T);
    void Dequeue();
    void Display();
    int Count();

};

template <class T>
Queue<T> :: Queue()
{
   First = NULL;
   iCount = 0;
}

template <class T>      // Insert Last
void Queue<T> :: Enqueue(T no)
{
    struct QNode<T> *newn = NULL;
    newn = new QNode<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else 
    {
        struct QNode<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}
template <class T>  //DeleteFirst
void Queue<T> :: Dequeue()
{
    T no;
    struct QNode<T> *temp = NULL;
    temp = First;

    if(First == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    } 
    else if(First->next == NULL)
    {
        no = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        no = First->data; 
        First = temp->next;
        delete temp;
    }
    cout<<"Removed elements are : "<<no<<endl;
    iCount--;
    
}

template <class T>
void Queue<T> :: Display()
{
    struct QNode<T> *temp = First;

    if(First == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else 
    {
        cout<<"Elements of Queue are : \n";
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////
//
//  Data structure - Searching Algorithm
//
//////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
    T *Arr;
    int iSize;

    ArrayX(int);
    ~ArrayX();
    void Accept();
    void Display();
    bool LinearSearch(T);
    bool BidirectionalSearch(T);
    bool BinarySearch(T);
};

template <class T>
ArrayX<T> :: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the number of elements : \n";
    for(int iCnt = 0; iCnt<iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{
    cout<<"Elements of array are : \n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BidirectionalSearch(T No)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = 0, iMid = 0;
    
    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart)/2;
        if(Arr[iMid] == No)
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid -1;
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////
//
//  Data structure - Sorting Algorithm
//
//////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else 
        {
            flag = false;
            break;
        }
    }
    return flag;
}

cout<<"----------Ascending order----------\n";
template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;
    
    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }

        }
    }
}

cout<<"----------Desending order----------\n";
template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;
    
    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }

        }
    }
}

cout<<"----------Ascending order----------\n";
template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;
    
    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

cout<<"----------Decending order----------\n";
template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;
    
    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

cout<<"----------Ascending order----------\n";
template <class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j = 0;
    int min_index = 0; 
    T temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] > Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

cout<<"----------Decending order----------\n";
template <class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j = 0;
    int min_index = 0; 
    T temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}



template <class T>
void ArrayX<T> :: InsertionSort()
{
    int i = 0, j = 0;
    T selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}

//////////////////////////////////////////////////////////
//
//  Data structure - Binary Search Tree.
//
//////////////////////////////////////////////////////////

template <class T>
struct Bnode
{
    T data;
    struct Bnode<T> *lchild;
    struct Bnode<T> *rchild;
};

template <class T>
class BST
{
    private:
    struct Bnode<T> *First;
    int iCount;

    public:
    BST();
    void Insert(T);
    bool Search(T);
    int Count();
};

template <class T>
BST<T> :: BST()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void BST<T> :: Insert(T no)
{
    struct Bnode<T> *newn = NULL;
    newn = new QNode<T>;
    struct Bnode<T> *temp = First;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        while(1)
        {
            if(temp->data == no)
            {
                cout<<"Duplicate node\n";
                delete newn;
                break;
            }
            else if(no < (temp->data))
            {
                if(temp -> lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no > (temp->data))
            {
                if(temp -> rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rchild;   
            }
        }
    }
}

template <class T>
bool BST<T> :: Search(T no)
{
    if(First == NULL)
    {
        return false;
    }
    else 
    {
        struct Bnode<T> *temp = First;
        while(temp != NULL)
        {
            if(temp-> data == no)
            {
                break;
            }
            else if(no > (temp->data))
            {
                temp = temp->rchild;
            }
            else if(no < (temp->data))
            {
                temp = temp->lchild;
            }
        }
        if(temp == NULL)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}

template <class T>
{
    int BST<T> :: Count()
    {
        return iCount;
    }
}

