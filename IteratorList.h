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

    bool operator==(const IteratorList &aea);
    bool operator!=(const IteratorList &aea);
    T operator*();
    IteratorList &operator++();
    IteratorList operator++(int);
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
    }
    return aux;
}

template <typename T>
bool IteratorList<T>::operator==(const IteratorList &aea)
{
    return Site == aea.Site;
}
template <typename T>
bool IteratorList<T>::operator!=(const IteratorList &aea)
{
    return Site != aea.Site;
}
template <typename T>
T IteratorList<T>::operator*()
{
    return Site->getValue();
}
template <typename T>
IteratorList<T> &IteratorList<T>::operator++()
{
    Site = Site->getNext();
    return *this;
}
template <typename T>
IteratorList<T> IteratorList<T>::operator++(int)
{
    IteratorList temp = *this;
    Site = Site->getNext();
    return temp;
}

template <typename T>
IteratorList<T>::~IteratorList(){}


#endif