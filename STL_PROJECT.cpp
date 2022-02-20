////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  NAME               : SANTOSH DNYANOBA SHINDE
//
//  PROJECT NAME       : STL_PROJECT 
//
//  POURPOSE           : TO CREATE OWN DATASTRUCTURE LIBRARY
//
//  DATE               : 22-02-2019
//
//  NUMBER OF MEMBERS  : 1
//
//  DESCRIPTION        : This is the reaserch oriented project. The main perpose of this project is to implement the our own Datastructures.
//                       This is the Generic Project due to which we can use any data type in our Project to create linked list.
//                       In this project there is not only four linked list implimented but also stack  and Queue is implemented.                      
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//
//      HEADER FILES INCLUSION
//
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//     Singly Linear Circular Structure
//
///////////////////////////////////////////////////////////////////////////////////

template <typename ST>     // TEMPLATE FOR STRUCTURE 

struct SCL_node
{
    ST data;
    struct SCL_node *next;
};

////////////////////////////////////////////////////////////////////////////////////
//
//     Doubly Linear Circular Structure
//
///////////////////////////////////////////////////////////////////////////////////

template <typename DT>   // TEMPLATE FOR STRUCTURE 

struct DCL_node
{
   DT data;
    struct DCL_node *next;
       struct DCL_node *prev;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      SinglyLinearLinkedList
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class ST>

class SinglyLL         //CLASS SINGLY LINEAR
{
private:

    SCL_node <ST> *first;
    int size;
    
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //             FUNTION DECLARATIONS
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   SinglyLL();

   void InsertFirst(ST);

     void InsertLast(ST);

        void InsertAtPos(ST, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////

template<class ST>
SinglyLL<ST> :: SinglyLL()
{
    first = NULL;
    size = 0;
}


template <class ST>
    void  SinglyLL <ST> :: InsertFirst(ST value)
    {
          SCL_node<ST> *newn = new   SCL_node<ST>;  
        
        newn->data = value;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }

template <class ST>
    void  SinglyLL <ST> :: InsertLast(ST value)
    {
          SCL_node<ST>  *newn = new   SCL_node<ST>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = value;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
              SCL_node<ST>* temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }

template <class ST>
    void  SinglyLL <ST> :: InsertAtPos(ST value, int ipos)
    {
          SCL_node<ST> *temp = first;

        if ((ipos < 1) || (ipos > size+1))
        {
            return;
        }

        if (ipos == 1)
        {
            InsertFirst(value);
        }
       else if (ipos == size+1)
        {
            InsertLast(value);
        }
        else
        {
              SCL_node<ST>* newn = new struct SCL_node <ST>;
            newn->data = value;
            newn->next = NULL;

            for (int i = 1; i < ipos-1; i++)
            {
                temp= temp->next;
            }
            newn->next = temp->next;
            temp->next =newn;
        }
        size++;
    }

template<class ST>
    void SinglyLL <ST> :: DeleteFirst()
    {
          SCL_node<ST> *temp = first;

        if (first == NULL)
        {
            return;
        }
        else
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }

template<class ST>
    void  SinglyLL <ST> :: DeleteLast()
    {
          SCL_node<ST> *temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

template<class ST>
    void  SinglyLL<ST> :: DeleteAtPos(int ipos)
    {
                  SCL_node<ST> *temp = first;

        if ((ipos < 1)||(ipos > size))        //FIlter
        {
            return;
        }
-
        if (ipos == 1)         // If Position is first
        {
              DeleteFirst();
        }

        else if (ipos == size)         //If Position Is Last
        {
            DeleteLast(); 
        }

        else
        {
            for (int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
          
             SCL_node<ST> *targeted = first;
             targeted = temp->next;
             temp->next = targeted->next;
             delete targeted;
        }
        size--;
    }

template<class ST>
    void  SinglyLL <ST> :: Display()
    {
          SCL_node<ST> *temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }

template<class ST>

    int  SinglyLL<ST> :: Count()
    {
        return size;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      SinglyCircularLinkedList
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class ST>
class SinglyCL
{
private:
                          //characteristics
   SCL_node<ST>* first;
   SCL_node<ST>* last;
   int size;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //             FUNTION DECLARATIONS
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         SinglyCL();

         void InsertFirst(ST);

         void InsertLast(ST);

         void InsertAtPos(ST, int);

         void DeleteFirst();

         void DeleteLast();

         void DeleteAtPos(int);

         void Display();

         int Count();
};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////

template<class ST>       //CLASS TEMPLATE 
   
   SinglyCL<ST> :: SinglyCL()       //CLASS CONSTRUCTOR
   {
      first = NULL;
      last = NULL;
      size = 0;
   }

template<class ST>

void SinglyCL<ST> :: InsertFirst(ST value)
{
    SCL_node<ST>* newn = new SCL_node<ST>;
      newn->data = value;
       newn->next = NULL;

   if ((first == NULL) && (last == NULL))
   {
      first = newn;
      last = newn;
   }
   else
   {
      newn->next = first;
      first = newn;
   }
   size++;
   last->next = first;
}

template<class ST>

void  SinglyCL<ST> :: InsertLast(ST value)
{
   SCL_node<ST>* newn = new SCL_node<ST>;
   newn->next = NULL;
   newn->data = value;

  if ((first == NULL)&&(last == NULL))
   {
      first = newn;
      last = newn;
   }
        else
       {

         last->next = newn;
          last = newn;
       }
   size++;
   last->next = first;
}

template<class ST>

void  SinglyCL<ST> :: InsertAtPos (ST value, int iPos)
{

        SCL_node<ST>* newn = new SCL_node<ST>;

        newn->data = value;
        newn->next = NULL;

        SCL_node<ST>* temp = first;

    if((iPos < 1) || (iPos > size+1))
    {
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(value);
    }
    else if(iPos == size +1)
    {
        InsertLast(value);
    }
    else
    {
        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
        size ++;
    }

   last->next = first;
}


template<class ST>

void  SinglyCL<ST> :: DeleteFirst()
{
   if ((first == NULL)&&(last == NULL))
   {
      return ;
   }
   else if (first == last)
   {
      delete first;
      first = NULL;
      last =  NULL;
   }
   else
   {
      first = first->next;
      delete last->next;
   }
   size--;
   last->next = first;
}

template<class ST>

void  SinglyCL<ST> :: DeleteLast()
{
   SCL_node<ST>* temp = new SCL_node<ST>;
   temp = first;

    if ((first == NULL)&&(last == NULL))
   {
      return;
   }
   else if (size == 1)
   {
      delete last;
      first = NULL;
      last = NULL;
   }

   else
   {
     while(temp->next != last)
     {
         temp = temp->next;
     }

     delete temp->next;
     last = temp;
   }

   last->next=first;
   
   size--;
   
}

template<class ST>

void  SinglyCL<ST> :: DeleteAtPos(int iPos)
{ 
   SCL_node<ST>* temp = first;

   SCL_node<ST>* targeted = new SCL_node<ST>;

   
   if (iPos == 1)
   {
      DeleteFirst();
   }
   else if (iPos == size)
   {
      DeleteLast();
   }
   else
   {
      for (int i = 1;  i < iPos-1;  i++)
      {
         temp = temp-> next;
      }

      targeted = temp->next;
      temp->next = targeted->next;
      delete targeted;

   size --;

   }
   last->next = first;
}

template<class ST>

void SinglyCL<ST> ::  Display()
{
   do
   {
      cout<<"|"<<first->data<<"|"<<"  ";
      first = first->next;

   } while(first != last->next);

   cout<<"\n";

}

template<class ST>

int SinglyCL<ST> ::  Count()
{
   return size;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DoublyLinearLinkedList  
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class DoublyLL
{
private:

   DCL_node<DT>* first;
   int size;

public:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //
    //             FUNTION DECLARATIONS
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
   DoublyLL();

   void InsertFirst(DT);

     void InsertLast(DT);

        void InsertAtPos(DT, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////
template <class DT>
  DoublyLL<DT> :: DoublyLL()
   {
      first =NULL;
      size = 0;
   }

template <class DT>
void DoublyLL<DT> :: InsertFirst(DT value)
{
   DCL_node<DT>* newn = new DCL_node<DT>;

   newn->data = value;
       newn->next = NULL;
          newn->prev = NULL;

   if (first == NULL)
   {
      first = newn;
   }
       else
       {
            newn->next = first;
               first = newn;
       }

   size++;
}

template <class DT>
void DoublyLL<DT> :: InsertLast (DT value)
{
   DCL_node<DT>* newn = new DCL_node<DT>;
   DCL_node<DT>* temp = first;

   newn->data = value;
   newn->next = NULL;
   newn->prev = NULL;

    if (first == NULL)
   {
      first = newn;
   }
      else 
          {
             while(temp->next != NULL)
              {
                 temp = temp->next;
             }
        temp->next = newn;
      newn->prev = temp;
   }

   size++;
}

template <class DT>
void DoublyLL<DT> :: InsertAtPos(DT value, int iPos)
{
   DCL_node<DT>* newn = new DCL_node<DT>;

   newn->data = value;
   newn->next = NULL;
   newn->prev = NULL;

   DCL_node<DT>* temp = new DCL_node<DT>;
      temp = first;

if ((iPos < 1 )||(iPos > size+2))
{
    cout<<"Enter Valid Position :";
    return;
}
   if (first == NULL)
   {
      first = newn;
   }
          else if (iPos == 1)
          {
            InsertFirst(value);
          }
              else if (iPos == size+1)
                 {
                    InsertLast(value);
                 }
       else
       {
          for (int i = 1; i < iPos-1; i++)
           {
              temp = temp->next;
           }

          newn->next = temp->next;
       temp->next = newn;
      newn->prev = temp;

   size++;

   }
}


template <class DT>
void DoublyLL<DT> :: DeleteFirst()
{
   DCL_node<DT>* temp = first;

   if (first == NULL)
   {
      return;
   }
        else 
        {
          first = first->next;
           delete temp ;
       }
   
   size--;
}

template <class DT>
void DoublyLL<DT> :: DeleteLast()
{
   DCL_node<DT>* temp = first;

   if (first == NULL)
   {
      return ;
   }
           else if (first->next == NULL)
            {
              delete first;
                first = NULL;
            }
                else
                {
                  while(temp->next->next != NULL)
                  {
                      temp = temp->next;
                  }
          delete temp->next;
      temp->next = NULL;
   }
   size--;
}

template <class DT>
void DoublyLL<DT> :: DeleteAtPos(int iPos)
{
   DCL_node<DT>* targeted = new DCL_node<DT>;

   DCL_node<DT>* temp  = new DCL_node<DT>;
   temp = first;


   if (first == NULL)
   {
      return;
   }
           if (iPos == 1)
          {
                DeleteFirst();
            }
                   else if (iPos == size)
                        {
                               DeleteLast();
                          }
        else
       {
         for (int i = 1; i < iPos - 1; i++)
         {
            temp = temp->next;
         }

            temp->next = temp->next->next;
                temp->next->next->prev = temp;

         size --;
       }
}

template <class DT>
void DoublyLL<DT> :: Display()
{
   DCL_node<DT>* temp = first;

   while(temp != NULL)
   {
      cout<<"|"<<temp->data<<"|"<<"  ";
      temp = temp->next;
   }cout<<"\n";
}

template <class DT>
int DoublyLL<DT> :: Count()
{
   return size;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DoublyCircularLinkedList
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class DoublyCL
{
private:

   DCL_node<DT>* first;
   DCL_node<DT>* last;
   int size;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //           FUNTION DECLARATIONS
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
   DoublyCL();

   void InsertFirst(DT);

     void InsertLast(DT);

        void InsertAtPos(DT, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////

template <class DT>
   DoublyCL<DT> ::  DoublyCL()
   {
      first = NULL;
      last = NULL;
      size = 0;
   }

template <class DT>
void  DoublyCL<DT> :: InsertFirst(DT value)
{
   DCL_node<DT>* newn = new DCL_node<DT>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

             if((first == NULL)&&(last == NULL))
             {
                first = newn;
                   last = newn; 
                }
     else 
   {
      newn->next = first;
      first->prev = newn;
      first = newn;       
   }

      last->next = first;
      first->prev = last;  

   size++;
}

template <class DT>
void  DoublyCL<DT> :: InsertLast (DT value)
{
   DCL_node<DT>* newn = new DCL_node<DT>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

   if ((first == NULL)&&(last == NULL))
   {
      first = newn ;
      last = newn ;
   }

   else
   {
      last->next = newn;
      newn->prev = last;
      last = newn;
   }

   last->next = first;
   first->prev = last;

 size++;
} 

template <class DT>
void  DoublyCL<DT> ::  InsertAtPos( DT value, int iPos)
{
   DCL_node<DT>* temp = new DCL_node<DT>;
   temp = first;

   DCL_node<DT>* newn = new DCL_node<DT>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

      if ((iPos < 1 )||(iPos > size+1))
      {
         cout<<"Please Enter Valid Position :\n";
         return;
         }
           
              if (iPos == 1)
               {
                  InsertFirst(value);
                }

           else if (iPos == size+1)
             {
                 InsertLast(value);
             }
      else
      {
         for (int i = 1; i < iPos-1 ; i++)
         {
            temp = temp->next;
         }

    newn->next = temp->next;
       temp->next->prev = newn;
         temp->next = newn;
            newn->prev = temp;
             size++;
    
         last->next = first;
      first->prev = last;
   }

}

template <class DT>
void DoublyCL<DT> ::  DeleteFirst()
{
   DCL_node<DT>* temp = first;

      if ((first == NULL)&&(last == NULL))
      {
         return ;
      }
           else  if (first == last)
              {
               delete first;
                first = NULL;
                   last = NULL;
                }
      else
      {
         first = first->next;
         delete last->next;

         first->prev = last;
         last->next = first;
      }

      size--;
}

template <class DT>
void  DoublyCL<DT> :: DeleteLast()
{
   if ((first == NULL)&&(last == NULL))
   {
      return ;
   }
       else if (first == last)
         {
         delete first;
            first = NULL;
             last = NULL;
         }
            else
            {
               last = last->prev;
               delete last->next;

               last->next = first;
               first->prev = last;
            }

      size--;
}

template <class DT>
void DoublyCL<DT> :: DeleteAtPos(int iPos)
{
   DCL_node<DT>* temp = first;

   if ((iPos < 1 ) || (iPos > size+1))
   {
         cout<<"Please Enter Valid Position :\n";

      return;
   }
       if (iPos == 1)
       {
            DeleteFirst();
         }
             else if (iPos == size)
             {
                DeleteLast();
               }
                  else
                  {
                     for (int i = 1; i < iPos-1; i++)
                     {
                        temp = temp->next;  
                       }

                       temp->next = temp->next->next;  //
                       delete temp->next->prev;        //
                       temp->next->prev = temp;        //
                size--;   
                   }
   
             last->next = first;
                first->prev = last;
}

template <class DT>
void  DoublyCL<DT> ::  Display()
{
   DCL_node<DT>* temp = first;  

   for (int i = 1; i <= size; i++)
   {
      cout<<"|"<<temp->data<<"|"<<"  ";
      temp = temp->next;
   }
   cout<<"\n";
}

template <class DT>
int  DoublyCL<DT> ::  Count()
{
   return size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        Stack 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
template<class ST>
class Stack
{
private:

    SCL_node<ST>* first;
    int size;

public:
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //             FUNTION DECLARATIONS
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
Stack();

void Push(ST);

void Pop();

void Display();

int Count();

};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////

template<class ST>
    Stack<ST> :: Stack()
    {
        first = NULL;
        size = 0;
    }

template<class ST>
    void Stack<ST> :: Push(ST value)
    {
        SCL_node<ST>* newn = new SCL_node<ST>;

        newn->data = value;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
          }
            else
            {
                newn->next = first;
                first = newn;
            }
    size++;
}

template<class ST>
    void Stack<ST> ::  Pop()
    {
        SCL_node<ST>* temp = first;

        if (first == NULL)
        {
            cout<<"Stack Is Empty :";
            return ;
        }
    
        else
        {
            first = first->next;
            delete temp;
        }
        size--;
    }

template<class ST>
    void Stack<ST> :: Display()
    {
         SCL_node<ST>* temp = first;

         if (first == NULL)
         {
            cout<<"Stack Is Empty :";
         }

        while(temp != NULL)
        {
           cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<"\n";
    }

template<class ST>
    int Stack<ST> ::  Count()
    {
        return size;
    }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//         Queue
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class ST>
class Queue        //CLASS QUEUE
{
private:

    SCL_node<ST>* first;
    int size;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //             FUNTION DECLARATIONS
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
    Queue();
    
    void InQueue(ST);

    void DeQueue();

    void Display();

    int Count();
    
};

////////////////////////////////////////////////////////////////
//
//       fUNCTION DEFINATIONS
//
/////////////////////////////////////////////////////////////////

template <class ST>
    Queue <ST>:: Queue()
    {
        first = NULL;
        size = 0;
    }

template <class ST>
    void Queue<ST>:: InQueue(ST value)
    {
        SCL_node<ST>* newn = new SCL_node<ST>;
        newn->data = value;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }

        else
        {
            SCL_node<ST>* temp = first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;

        }
        size++;
    }

template <class ST>
    void Queue<ST>:: DeQueue()
    {
        SCL_node<ST>* temp = first;

        if (first == NULL)
        {
            return;
        }
        else
        {
            first = first->next;
            delete temp;
        }
        size--;
    }

template <class ST>
    void Queue<ST> :: Display()
    {
        SCL_node<ST>* temp = first;

        while(temp != NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<"\n";
    }

template <class ST>
    int Queue<ST> :: Count()
    {
        return size;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
