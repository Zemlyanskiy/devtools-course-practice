//  Copyright 2017 Ivan Kiselev
#include "../include/List.h"
PLink List::GetLink(PValue pVal, PLink pLink) {
    return new Link(pVal, pLink);
}

PValue List::GetValue() {
    return pcurrlink->pvalue_;
}

List::List() {
    pfirst = new Link(NULL, NULL);
    plast = pfirst;
    pcurrlink = pfirst;
    pprevlink = NULL;
    pstop = pfirst;
    currpos = 0;
    listlen = 0;
}
List::List(const List &list) {
    int k = 1;
    pfirst = new Link(*list.pfirst);
    plast = pfirst;
    pcurrlink = pfirst;
    pprevlink = NULL;
    pstop = pfirst;
    currpos = 0;
    listlen = 0;
    Link * that = list.pfirst;
    while (k < list.listlen) {
        pcurrlink = new Link(*that);
        k++;
        that = that->GetNexLink();
        GoNext();
    }
    plast = new Link(that->GeValue(), that->pnext_);
    listlen = k;
}

List::~List() {
    DelList();
}

int List::IsEmpty() const {
    return pfirst == plast;
}

int List::GetListlength() const {
    return listlen;
}

void List::Reset(void) {
    pcurrlink = pfirst;
    pprevlink = NULL;
    currpos = 0;
}

bool List::IsListEnded(void) const {
    return ((currpos >= listlen) || (pcurrlink == plast));
}

int List::GoNext(void) {
    if (IsListEnded()) return 1;
    pprevlink = pcurrlink;
    pcurrlink = pcurrlink->GetNexLink();
    currpos++;
    return 0;
}

void List::InsFirst(PValue pVal) {
    pfirst = GetLink(pVal, pfirst);
    listlen++;
}

void List::InsLast(PValue pVal) {
    if (pfirst->pvalue_ == NULL) {
        InsFirst(pVal);
    } else {
        while (GoNext() != 1) {}
        pprevlink->SetNextLink(GetLink(pVal, plast));
        pcurrlink = pprevlink->GetNexLink();
        listlen++;
    }
}

void List::InsCurrent(PValue pVal) {
    if (pprevlink != NULL) {
        pprevlink->SetNextLink(GetLink(pVal, pcurrlink));
        pcurrlink = pprevlink->GetNexLink();
        listlen++;
    } else {
        InsFirst(pVal);
    }
}

void List::DelFirst(void) {
    PLink old = pfirst;
    pfirst = pfirst->GetNexLink();
    listlen--;
    old->~Link();
}

void List::DelCurrent(void) {
    if (pcurrlink == pfirst) {
        DelFirst();
    } else {
        PLink old = pcurrlink;
        pprevlink->SetNextLink(pcurrlink->GetNextLink());
        pcurrlink = pcurrlink->GetNexLink();
        old->~Link();
        listlen--;
    }
}

void List::DelList(void) {
    while (listlen > 0) DelFirst();
}
