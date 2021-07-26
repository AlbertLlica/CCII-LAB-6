#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class Iterator
{
public:
    virtual bool ExistNext()const = 0;
    virtual  T Next() = 0;
};

#endif

//ref: https://www.youtube.com/watch?v=Qzy-CwIO9zg