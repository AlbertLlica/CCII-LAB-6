#ifndef __LINKEDLISTG_H__
#define __LINKEDLISTG_H__

#include <iostream>
#include "Node.h"
#include "IteratorList.h"
using namespace std;
template <typename T>

class LinkedList {
        int size;
        Node<T> *head;
    public:

        LinkedList();
        LinkedList(T);
        LinkedList(const LinkedList &);

        ~LinkedList();
        LinkedList(LinkedList<T>& inicio);
        LinkedList(LinkedList<T>&& inicio);
        LinkedList<T>& operator=(LinkedList<T>& inicio);
        LinkedList<T>& operator=(LinkedList<T>&& inicio);

        int count();

        void insert(T);
        void insert_pri(T);
        void insert_position(T,int);
        void popBack();
        void popFront();
        void print();
        virtual Iterator<T> *getIterator();
        
        
};
template<typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T value) {
    this->size = 1;
    this->head = new Node<T>(value);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &o) {
    this->size = 0;
    this->head = nullptr;
    Node<T>* current_o = o.head;
    while(current_o)
    {
        this->insert(current_o->getValue());
        current_o = current_o->getNext();
    }

}

template <typename T>
Iterator<T>* LinkedList<T>::getIterator(){
    return new IteratorList<T>(head);
}

template <typename T>
int LinkedList<T>::count()
{
	Node<T>* tmp = head;
	int count = 0;
	while (tmp != nullptr)
	{
		tmp = tmp->getNext();
		count++;
	}
	return count;
}

template <typename T>
void LinkedList<T>::insert_pri(T elem){
    head = new Node<T>(elem, head);
}

template<typename T>
void LinkedList<T>::insert(T value) {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *tmp = head;
    if(head==nullptr){
        head = newNode;
    } else {
            while  (tmp->getNext() != nullptr)
            {
                tmp = tmp->getNext();
            }
            newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);
    }
    size++;
}
template<typename T>
void LinkedList<T>::insert_position(T value,int pos){
    if(pos<size+1){
        Node<T> *newNode= new Node<T>(value);
        Node<T> *tmp =head;
        for (int i=0;i<=pos-2;i++){
            tmp=tmp->getNext();
        }
        newNode -> setNext(tmp->getNext() ); 
        tmp->setNext(newNode);
    }
    else{
        cout<<"No";
    }
    size++;
}

template<typename T>
void LinkedList<T>::popBack(){
    int tam=size-1;
        Node<T> *aux, *current=head;
        if (tam!=0){
            int i=0;
            while(i<tam){
                aux = current; current = current->getNext();
                i++;
            }
            aux -> setNext( current->getNext() ); 
            delete current;
        }
        else{
            head = head -> getNext(); 
            delete current;
        }
        size--;
}

template<typename T>
void LinkedList<T>::popFront() {
        Node<T> *current=head;
        head = head -> getNext(); 
        delete current;
        size--;
    
}

template<typename T>
void LinkedList<T>::print(){
    Node<T>* aux = head;
    int i=1;
    cout<<"LISTA: ";
    while (aux != nullptr){
        cout<<aux->getValue()<<", ";
        aux = aux->getNext();
        i++;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *current;
    while (head!=nullptr){
        current = head->getNext();
        delete head;
        head = current;
    }
    delete head;
}

//CONSTRUCT Y SOBRE MOVE
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& inicio)
{
	this->~LinkedList();
	head = inicio.head;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& inicio)
{
	if (this == &inicio)
		return *this;

	this->~LinkedList();
	head = inicio.head;

	return *this;

}


//#include "LinkedList.cpp"
#endif