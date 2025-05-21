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
inline void MyList<T>::addBegin(T a) { // ïîñòàâèëè &, ÷òîáû ìîæíî áûëî ÷òî-òî ïðèñâîèòü è ýòî ïîÿâèòñÿ â ìýéíå 
    Node* t = new Node(a, head); // ñîçäàëè íîâûé óçåë 
    if (!head) head = tail = t;
    else head = t;

}

template <class T>
void MyList<T>::addEnd(T a) {
    Node* t = new Node(a); // ñîçäàëè íîâûé óçåë 
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

//template<class T>
//inline MyList<T>:: Node* listCopy(Node* head, Node*& tailCopy)
//{
//    Node* head1 = nullptr;
//    Node* prev = nullptr;
//    Node* tail = nullptr;
//    for (Node* h = head; h; h = h->next) {
//        tail = new Node(h->info);
//        if (!head1)prev = head1 = tail;
//        else prev->next = tail;
//        prev = tail;
//    }
//    tailCopy = tail;
//    return head1;
//}

//template<class T>
// int MyList<T>::insertList(Node* head, int x)
//{
//    Node* nodeX = nullptr;
//    Node* h;
//    for (h = head; h && h->info != x; h = h->next);
//    if (h) {
//        Node* tailCopy = nullptr;
//        Node* headCopy = listCopy(head, tailCopy);
//        tailCopy->next = h->next;
//        h->next = headCopy;
//        return 0;
//    }
//    else return -1;
//}
