
#include <iostream>
#include "LinkedListG.h"

int main() {

    LinkedList<int> Lista1;
    Lista1.insert(1);
    Lista1.insert(2);
    Lista1.insert(3);
    Lista1.insert(4);
    Lista1.print(); cout<<endl;

    LinkedList<char> Lista2;
    Lista2.insert('F');
    Lista2.insert('E');
    Lista2.insert('L');
    Lista2.insert('I');
    Lista2.print(); cout<<endl;

    LinkedList<string> Lista3;
    Lista3.insert("tor");
    Lista3.insert("tu");
    Lista3.insert("gui");
    Lista3.insert("ta");
    Lista3.print(); cout<<endl;

    Lista1.insert_position(3,3);
    Lista1.popBack();//FIN
    Lista1.popFront();//ELIM INI
    Lista1.insert_position(15,2);

    Lista2.insert_position('a',1);
    Lista2.popBack();
    Lista2.popFront();
    Lista2.insert_position('e',3);

    Lista3.insert_position("uva",2);
    Lista3.popBack();
    Lista3.popFront();
    Lista3.pushFront("GAAA");
    Lista3.pushBack("GEEE");
    Lista3.insert_position("gra",1);

    int AUX1;
    Iterator<int> *ite1 = Lista1.getIterator();
    while (ite1->ExistNext()){
        AUX1 = ite1->Next();
        cout<<AUX1<<" ";
    }
    cout<<endl;

    char AUX2;
    Iterator<char> *ite2 = Lista2.getIterator();
    while (ite2->ExistNext()){
        AUX2 = ite2->Next();
        cout<<AUX2<<" ";
    }
    cout<<endl;

    string AUX3;
    Iterator<string> *ite3 = Lista3.getIterator();

    while (ite3->ExistNext()){
        AUX3 = ite3->Next();
        cout<<AUX3<<" ";
    }
    cout<<endl;

    LinkedList<int> Lista4;
    Lista4=std::move(Lista1);
    Lista4.print(); cout<<endl;
    Lista3.print(); cout<<endl;
    Lista3.popBack();
    Lista3.print();
    cout << endl; 

    for (IteratorList<int> aea = Lista1.begin(); aea != Lista1.end(); aea++)
    {
        cout << *aea << ", ";
    }
    return 0;
}