#pragma once
#include <iostream>
#include <string.h> 
#include "MARSH.h"
using namespace std;
template <class T>
class MyList {
    class Node {
    public:
        T info;
        Node* next = nullptr;
        Node(T info, Node* next) :info(info), next(next) {};
        Node(T info) :info(info), next(nullptr) {};
        Node() {};

    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void addBegin(T a);
    void addEnd(T a);
    void deleteList();
    //Node* listCopy(Node* head, Node*& tailCopy);
    //int insertList(Node* head, int x);
    bool digitIntNode(Node* head, T a);
    bool IsEmpty();
    void deleteEl(T a);
    friend ostream& operator<<(ostream& os, MyList<T>& l) {
        for (Node* t = l.head; t != nullptr; t = t->next)os << t->info << " \n";
        return os;
    }
    /*bool operator==(Node* head, T a) {
        Node* h
            return h->info == a;
    }*/

};


template <class T>
inline void MyList<T>::addBegin(T a) { // поставили &, чтобы можно было что-то присвоить и это появится в мэйне 
    Node* t = new Node(a, head); // создали новый узел 
    if (!head) head = tail = t;
    else head = t;

}

template <class T>
void MyList<T>::addEnd(T a) {
    Node* t = new Node(a); // создали новый узел 
    if (!head) {
        head = tail = t; return;
    }
    tail->next = t;
    tail = t;
}
template <class T>
void MyList<T>::deleteList() {
    if (head != nullptr) {
        Node* t = head;
        while (t) {
            Node* g = t;
            t = t->next;
            t = nullptr;
            delete g;
        }
    }
    head = nullptr;
}

template<class T>
inline bool MyList<T>::digitIntNode(Node* head, T x)
{
    Node* h;
    for (h = head; h && h->info == x; h = h->next);
    if (h)return true;
    return false;
}

template<class T>
inline bool MyList<T>::IsEmpty()
{
    return head == nullptr;
}

template<class T>
inline void MyList<T>::deleteEl(T a)
{
    if (head != nullptr) {
        Node* t = head;
        while (t) {
            Node* g = t;
            t = t->next;
            if (t == a) {
                delete g;
            }
        }
    }
}