#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include "simplenode.h"
#include <iostream>

using namespace std;

template <typename tData>
class SimpleList
{
    SimpleNode<tData> *head;
    SimpleNode<tData> *actual;
    SimpleNode<tData> *tail;
    int lSize;
    public:
        SimpleList();
        ~SimpleList();
        bool isVoid();
        void insertAtHead(tData dato);
        void insertAtTail(tData dato);
        void insertAtPos(int pos, tData dato);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        int getSize();

        SimpleNode<tData>* operator [](int pos);
        void swap(int pos, int pos2);

    protected:
};


template <typename tData>
SimpleList<tData>::SimpleList()
{
    head = actual = tail = 0;
    lSize = 0;
}

template <typename tData>
SimpleList<tData>::~SimpleList()
{
}

template <typename tData>
int SimpleList<tData>::getSize()
{
    return lSize;
}

template <typename tData>
bool SimpleList<tData>::isVoid()
{
    return head == 0;
}

/*METODOS DE INSERCION*/

template <typename tData>
void SimpleList<tData>::insertAtHead(tData dato)
{
    if(isVoid())
    {
        head = new SimpleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        SimpleNode<tData>* nsNode = new SimpleNode<tData>(dato);
        nsNode->setNext(head);
        head = nsNode;
        lSize++;
    }
}

template <typename tData>
void SimpleList<tData>::insertAtTail(tData dato)
{
    if(isVoid())
    {
        head = new SimpleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        SimpleNode<tData>* nsNode = new SimpleNode<tData>(dato);
        tail->setNext(nsNode);
        tail = nsNode;
        lSize++;
    }
}

template <typename tData>
void SimpleList<tData>::insertAtPos(int pos, tData dato)
{
    if(isVoid())
    {
        head = new SimpleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        if(pos <= 0)
            insertAtHead(dato);
        else
        {
            actual = head;
            int index = 1;
            while ((index != pos) && (actual->getNext() != 0))
            {
                index++;
                actual = actual->getNext();
            }
            SimpleNode<tData>* nsNode = new SimpleNode<tData>(dato);
            nsNode->setNext(actual->getNext());
            actual->setNext(nsNode);
            lSize++;
        }/*else*/
    }/*else*/
}

/*METODOS DE BORRADO*/

template <typename tData>
void SimpleList<tData>::deleteAtHead()
{
    if(isVoid())
         cout << "La lista se está vacía\n";
    else
    {
        if(!head->getNext())
        {
            head = 0;
            lSize--;
        }
        else
        {
            actual = head;
            head = head->getNext();
            delete actual;
            lSize--;
        }
    }/*else*/
}


template <typename tData>
void SimpleList<tData>::deleteAtTail()
{
    if(isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        actual = head;
        while (actual->getNext()->getNext())
            actual = actual->getNext();
        SimpleNode<tData> *temp = actual->getNext();
        actual->setNext(0);
        delete temp;
        tail = actual;
        lSize--;
    }
}

template <typename tData>
void SimpleList<tData>::deleteAtPos(int pos)
{
    if(isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        if((pos >= lSize) || (pos < 0))
            cout << "El índice esta fuera del los límites de la lista\n";
        else
        {
            if(pos == 0)
                deleteAtHead();
            else if(pos == lSize-1)
                deleteAtTail();
            else
            {
                int index = 1;
                actual = head;
                while (index <= pos) {
                    actual = actual->getNext();
                    index++;
                }
                SimpleNode<tData> *temp = actual->getNext();
                actual->setNext(actual->getNext()->getNext());
                delete temp;
                lSize--;
            }
        }
    }
}

/*METODO DE IMPRESION*/

template <typename tData>
void SimpleList<tData>::print()
{
    if (isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        actual = head;
        while (actual)
        {
            if (!actual->getNext())
            {
                cout << actual->getDato() << endl;
                actual = actual->getNext();
            }
            else
            {
                cout << actual->getDato() << " - ";
                actual = actual->getNext();
            }
        }
    }
}

template <class tData>
SimpleNode<tData>* SimpleList<tData>::operator [](int pos)
{
    if(isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        if((pos >= lSize) || (pos < 0))
            cout << "El índice esta fuera del los límites de la lista\n";
        else
        {
            if(pos == 0)
                return head;
            else if(pos == lSize-1)
                return tail;
            else
            {
                int index = 1;
                actual = head;
                while (index <= pos) {
                    actual = actual->getNext();
                    index++;
                }
                return actual;
            }
        }
    }
}

template<class tData>
void SimpleList<tData>::swap(int pos, int pos2)\
{
    SimpleNode<tData>* temp1;
    SimpleNode<tData>* temp2;
    SimpleNode<tData> temp3(0);
    if (pos == pos2) return;
    if(isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        if((pos >= lSize) || (pos < 0))
            cout << "El índice esta fuera del los límites de la lista\n";
        else
        {
            if(pos == 0)
                temp1 = head;
            else
            {
                int index = 1;
                actual = head;
                while (index <= pos) {
                    actual = actual->getNext();
                    index++;
                }
                temp1 = actual;
            }
        }
        if((pos2 >= lSize) || (pos2 < 0))
            cout << "El índice esta fuera del los límites de la lista\n";
        else
        {
            if(pos2 == 0)
                temp2 = head;
            else
            {
                int index = 1;
                actual = head;
                while (index <= pos2) {
                    actual = actual->getNext();
                    index++;
                }
                temp2 = actual;
            }
        }
    }
    temp3 = *temp1;
    temp1->dato = temp2->dato;
    temp2->dato = temp3.dato;

}

#endif
