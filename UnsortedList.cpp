#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currentPos = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {

}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}









template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    Node<T>* curr = head;
    while(curr != nullptr) {
        if (curr->info == someItem) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {

    Node<T>* loc = new Node<T>;
    loc->info = item;                     //     loc = item;
    loc->next = head;
    head = loc;
    length++;

}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {

    if (length > 0 && head->info == item){
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        length--;
        return;
    }

    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while(curr != nullptr) {
        if (curr->info == item) {
            prev->next = curr->next;
            delete curr;
            length--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currentPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    if (currentPos == nullptr) {
        throw "Nothing to iterator over";
    }

    T currVal = currentPos->info;
    currentPos = currentPos->next;
    return currVal;
}
