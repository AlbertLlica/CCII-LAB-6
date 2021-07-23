#ifndef __ITERATORLIST_H__
#define __ITERATORLIST_H__

#include "Iterator.h"
#include "Node.h"

template <typename T>
class IteratorList:public Iterator<T>{
private:
    Node<T> *Site;
public:
    IteratorList(Node<T> *);
    virtual bool ExistNext()const;
    virtual T Next();
    ~IteratorList();
};

template <typename T>
IteratorList<T>::IteratorList(Node<T> * NODE){
    Site = NODE;
}

template <typename T>
bool IteratorList<T>::ExistNext()const{
    return(Site != nullptr);
}

template <typename T>
T IteratorList<T>::Next(){
    T aux;
    if(ExistNext()){
        aux=Site->getValue();
        Site=Site->getNext();
        return aux;
    }
}

template <typename T>
IteratorList<T>::~IteratorList(){}


#endif