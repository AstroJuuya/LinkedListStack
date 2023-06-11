#include "Stack.h"

Stack::Stack(const Stack& source)
{
    if (source.Empty()) {
        head = nullptr;
    }
    else if (source.head->p_next == nullptr) {
        head = new Node(source.head->data, nullptr);
    }

    head = new Node(source.head->data, nullptr);
    Node* copytail = source.head->p_next;
    while (copytail->p_next != nullptr) {
        Push(copytail->data);
        copytail = copytail->p_next;
    }
    Push(copytail->data);
}

Stack& Stack::operator=(const Stack& source)
{
    if (source.Empty()) {
        delete head;
        head = nullptr;
        return *this;
    }
    else if (source.head->p_next == nullptr) {
        delete head;
        head = nullptr;
        head = new Node(source.head->data, nullptr);
        return *this;
    }
    delete head;
    head = nullptr;
    head = new Node(source.head->data, nullptr);
    Node* copytail = source.head->p_next;
    while (copytail->p_next != nullptr) {
        Push(copytail->data);
        copytail = copytail->p_next;
    }
    Push(copytail->data);
    return *this;
}

Stack::~Stack()
{
    if (head == nullptr) {
        return;
    }
    delete head;
    head = nullptr;
}

void Stack::Push( int val ) {
    if (Empty()) {
        head = new Node(val, nullptr);
        return;
    }
    else if (head->p_next == nullptr) {
        head->p_next = new Node(val, nullptr);
        return;
    }

    Node* tail = head->p_next;
    while (tail->p_next != nullptr) {
          tail = tail->p_next;  
    }
    tail->p_next = new Node(val, nullptr);
}

int Stack::Pop() {
    if (Empty()) {
        return 0;
    }
    else if(head->p_next == nullptr) {
        int result = head->data;
        delete head;
        head = nullptr;
        return result;
    }

    Node* tail = head->p_next;
    Node* new_tail = nullptr;
    while (tail->p_next != nullptr) {
    new_tail = tail;
    tail = tail->p_next;  
    }

    const int result = tail->data;
    if (new_tail != nullptr) {
        new_tail->p_next = nullptr;
    }
    else {
        head->p_next = nullptr;
    }
    delete tail;
    return result;
}

int Stack::Size() const {
    if (Empty()) {
        return 0;
    }
    else if (head->p_next == nullptr) {
        return 1;
    }
    int size = 1;
    Node* tail = head->p_next;
    while (tail->p_next != nullptr) {
          tail = tail->p_next;  
          size++;
    }
    size++;
   return size; 
}

bool Stack::Empty() const {
   return head == nullptr; 
}

inline Stack::Node::Node(int value, Node* next)
    :
    data(value),
    p_next(next)
{}

inline Stack::Node::~Node() {
    delete p_next;
    p_next = nullptr;
}
