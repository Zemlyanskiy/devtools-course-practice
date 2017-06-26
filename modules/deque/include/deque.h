// Copyright 2017 Nazarov Aleksandr and Vinogradova Ekaterina

#ifndef MODULES_DEQUE_INCLUDE_DEQUE_H_
#define MODULES_DEQUE_INCLUDE_DEQUE_H_

#include <iostream>
#include <string>
#include <fstream>

const int kDefMemSize = 2000;

typedef std::string    Elem;
typedef Elem*    PointElem;

class Deque {
 public:
    explicit Deque(int size = kDefMemSize);
    explicit Deque(const Deque &deq);
    ~Deque();
    void InsFront(Elem element);
    void InsBack(Elem element);
    Elem GetFront();
    Elem GetBack();
    bool IsEmpty(void) const;
    bool IsFull(void) const;
    void Load(const char* FileName);
    void Save(const char* FileName);
 protected:
    PointElem memory_;
    int front_;
    int back_;
    int mem_size_;
    int data_count_;

    void Clear();
    int GetNextFrontIndex(int index);
    int GetNextBackIndex(int index);
};

#endif  // MODULES_DEQUE_INCLUDE_DEQUE_H_
