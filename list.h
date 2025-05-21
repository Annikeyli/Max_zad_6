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
    Node* listCopy(Node* head, Node*& tailCopy);
    int insertList(Node* head, int x);
    bool digitIntNode(Node* head, T a);
    bool IsEmpty();
    void deleteEl(T a);

    friend ostream& operator<<(ostream& os, MyList<T>& l) {
        for (Node* t = l.head; t != nullptr; t = t->next) os << t->info << "\n";
        return os;
    }
};

template <class T>
void MyList<T>::addBegin(T a) {
    Node* t = new Node(a, head);
    if (!head) head = tail = t;
    else head = t;
}

template <class T>
void MyList<T>::addEnd(T a) {
    Node* t = new Node(a);
    if (!head) {
        head = tail = t;
        return;
    }
    tail->next = t;
    tail = t;
}

template <class T>
void MyList<T>::deleteList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

template <class T>
bool MyList<T>::digitIntNode(Node* head, T x) {
    Node* h;
    for (h = head; h && !(h->info == x); h = h->next);
    return h != nullptr;
}

template <class T>
bool MyList<T>::IsEmpty() {
    return head == nullptr;
}

template <class T>
void MyList<T>::deleteEl(T a) {
    if (!head) return;

    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        if (current->info == a) {
            if (prev) {
                prev->next = current->next;
                if (current == tail) tail = prev;
            }
            else {
                head = current->next;
                if (current == tail) tail = nullptr;
            }
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

template <class T>
typename MyList<T>::Node* MyList<T>::listCopy(Node* head, Node*& tailCopy) {
    Node* head1 = nullptr;
    Node* prev = nullptr;
    tailCopy = nullptr;

    for (Node* h = head; h; h = h->next) {
        Node* newNode = new Node(h->info);
        if (!head1) {
            head1 = prev = newNode;
        }
        else {
            prev->next = newNode;
            prev = newNode;
        }
        tailCopy = newNode;
    }
    return head1;
}

template <class T>
int MyList<T>::insertList(Node* head, int x) {
    Node* nodeX = nullptr;
    Node* h;
    for (h = head; h && h->info.getNumber() != x; h = h->next);

    if (h) {
        Node* tailCopy = nullptr;
        Node* headCopy = listCopy(head, tailCopy);
        tailCopy->next = h->next;
        h->next = headCopy;
        return 0;
    }
    return -1;
}
