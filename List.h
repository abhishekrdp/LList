/* 
 * File:   List.h
 * Author: abhishek
 *
 * Created on February 22, 2013, 2:08 PM
 */

#include<cstdlib>
#include<iostream>

#ifndef LIST_H
#define  LIST_H

template<typename T>
struct Node
{
    Node():data(0),next(NULL){};    
    T data;
    Node *next;
};

template<typename T>
class List
{
    public:
        List():node(){};
        List(T val);
        ~List();
        void append(T val);
        void print();
        void clearL();
        
    private:
        
        Node<T> *node;
};

template<typename T>
void List<T>::clearL()
{
    Node<T> *curr,*temp;
    curr = this->node;
    while(curr!= NULL)
    {
        temp = curr;
        delete temp;
        curr = curr->next;        
    }
    
}
template<typename T>
void List<T>::append(T val)
{    
    Node<T> *curr = this->node;
    if(!curr)
    {
        curr = new Node<T>();
        curr->data = val;
        curr->next = NULL;
        this->node = curr;
    }
    else
    {
            Node<T> *prev;
        while(curr!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        Node<T> *nod = new Node<T>();
        nod->next = NULL;
        nod->data = val;        
        prev->next = nod;        
    }
}
template<typename T>
void List<T>::print()
{
    Node<T> *curr = this->node;
    while(curr!=NULL)
    {
        std::cout<<"   "<<curr->data;
        curr = curr->next;
    }    
    std::cout<<std::endl;
}
template<typename T>
List<T>::List(T val)
{
    node = new Node<T>();
    node->data = val;
    node->next = NULL;
}


template<typename T>
List<T>::~List()
{
    clearL();
}
#endif	/* LIST_H */

