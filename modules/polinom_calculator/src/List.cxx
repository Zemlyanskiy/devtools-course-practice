//  Copyright 2017 Ivan Kiselev
#include "../include/List.h"
PLink List::GetLink(PValue pVal, PLink pLink) {
    return new Link(pVal, pLink);
}

PValue List::GeValue() {
    return pCurrLink->pValue_;
}

List::List() {
    pFirst = new Link(NULL, NULL);
    pLast = pFirst;
    pCurrLink = pFirst;
    pPrevLink = NULL;
    pStop = pFirst;
    CurrPos = 0;
    ListLen = 0;
}
List::List(const List &list) {
    int k = 1;
    pFirst = new Link(*list.pFirst);
    pLast = pFirst;
    pCurrLink = pFirst;
    pPrevLink = NULL;
    pStop = pFirst;
    CurrPos = 0;
    ListLen = 0;
    Link * that = list.pFirst;
    while (k < list.ListLen) {
        pCurrLink = new Link(*that);
        k++;
        that = that->GetNexLink();
        GoNext();
    }
    pLast = new Link(that->GeValue(), that->pNext_);
    ListLen = k;
}

List::~List() {
    DelList();
}

int List::IsEmpty() const {
    return pFirst == pLast;
}

int List::GetListLength() const {
    return ListLen;
}

void List::Reset(void) {
    pCurrLink = pFirst;
    pPrevLink = NULL;
    CurrPos = 0;
}

bool List::IsListEnded(void) const {
    return ((CurrPos >= ListLen) || (pCurrLink == pLast));
}

int List::GoNext(void) {
    if (IsListEnded()) return 1;
    pPrevLink = pCurrLink;
    pCurrLink = pCurrLink->GetNexLink();
    CurrPos++;
    return 0;
}

void List::InsFirst(PValue pVal) {
    pFirst = GetLink(pVal, pFirst);
    ListLen++;
}

void List::InsLast(PValue pVal) {
    if (pFirst->pValue_ == NULL) {
        InsFirst(pVal);
    } else {
        while (GoNext() != 1) {}
        pPrevLink->SetNextLink(GetLink(pVal, pLast));
        pCurrLink = pPrevLink->GetNexLink();
        ListLen++;
    }
}

void List::InsCurrent(PValue pVal) {
    if (pPrevLink != NULL) {
        pPrevLink->SetNextLink(GetLink(pVal, pCurrLink));
        pCurrLink = pPrevLink->GetNexLink();
        ListLen++;
    } else {
        InsFirst(pVal);
    }
}

void List::DelFirst(void) {
    PLink old = pFirst;
    pFirst = pFirst->GetNexLink();
    ListLen--;
    old->~Link();
}

void List::DelCurrent(void) {
    if (pCurrLink == pFirst) {
        DelFirst();
    } else {
        PLink old = pCurrLink;
        pPrevLink->SetNextLink(pCurrLink->GetNextLink());
        pCurrLink = pCurrLink->GetNexLink();
        old->~Link();
        ListLen--;
    }
}

void List::DelList(void) {
    while (ListLen > 0) DelFirst();
}
