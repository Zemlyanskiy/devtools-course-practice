// Copyright 2017 Nazarov Aleksandr and Vinogradova Ekaterina

#include "include/deque.h"
#include <string>

Deque::Deque(int size) : front_(-1), back_(0) {
    data_count_ = 0;
    mem_size_ = size;
    if (size < 0)
        throw "DataErr";
    else if (size == 0)
        memory_ = nullptr;
    else
        memory_ = new Elem[mem_size_];
}

Deque::Deque(const Deque &deq) : front_(deq.front_), back_(deq.back_) {
    data_count_ = deq.data_count_;
    mem_size_ = deq.mem_size_;
    if (mem_size_ == 0)
        memory_ = nullptr;
    else
        memory_ = new Elem[mem_size_];
    for (int i = 0; i < mem_size_; i++) {
        memory_[i] = deq.memory_[i];
    }
}

Deque::~Deque() {
    delete[] memory_;
    memory_ = nullptr;
}

void Deque::Clear() {
    data_count_ = 0;
    front_ = -1;
    back_ = 0;
}

int Deque::GetNextFrontIndex(int index) {
    return ++index % mem_size_;
}

int Deque::GetNextBackIndex(int index) {
    return (index == 0) ? mem_size_ - 1 : --index;
}

void Deque::InsFront(Elem element) {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsFull()) {
        throw "DataFull";
    } else {
        front_ = GetNextFrontIndex(front_);
        memory_[front_] = element;
        data_count_++;
    }
}

void Deque::InsBack(Elem element) {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsFull()) {
        throw "DataFull";
    } else {
        back_ = GetNextBackIndex(back_);
        memory_[back_] = element;
        data_count_++;
    }
}

Elem Deque::GetFront() {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsEmpty()) {
        throw "DataEmpty";
    } else {
        data_count_--;
        Elem tmp = memory_[front_];
        front_ = GetNextBackIndex(front_);
        return tmp;
    }
}

Elem Deque::GetBack() {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsEmpty()) {
        throw "DataEmpty";
    } else {
        data_count_--;
        Elem tmp = memory_[back_];
        back_ = GetNextFrontIndex(back_);
        return tmp;
    }
}

bool Deque::IsEmpty(void) const {
    return data_count_ == 0;
}

bool Deque::IsFull(void) const {
    return data_count_ == mem_size_;
}

void Deque::Save(const char *FileName) {
    std::ofstream filestream(FileName, std::ios_base::trunc);

    if (filestream.is_open()) {
        for (int i = back_, f = 0; f < data_count_; f++,
            i = GetNextFrontIndex(i)) {
            if (memory_[i].size() > 0) {
                if (memory_[i].at(memory_[i].size() - 1) == '\n')
                    filestream << memory_[i];
                else
                    filestream << memory_[i] << std::endl;
            }
        }
    }

    filestream.close();
}

void Deque::Load(const char *FileName) {
    std::ifstream filestream(FileName);
    std::string string_from_file;

    Clear();
    if (filestream.is_open() && !filestream.eof()) {
        while (!filestream.eof()) {
            std::getline(filestream, string_from_file);
            if (string_from_file.size() != 0)
                InsFront(string_from_file);
        }
    } else {
        throw "File stream error";
    }
}
