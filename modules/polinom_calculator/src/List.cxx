//  Copyright 2017 Ivan Kiselev
#include "../include/List.h"
PLink List::GetLink(PValue pval, PLink plink) {
    return new Link(pval, plink);
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
    plast = new Link(that->GetValue(), that->pnext_);
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

void List::InsFirst(PValue pval) {
    pfirst = GetLink(pval, pfirst);
    listlen++;
}

void List::InsLast(PValue pval) {
    if (pfirst->pvalue_ == NULL) {
        InsFirst(pval);
    } else {
        while (GoNext() != 1) {}
        pprevlink->SetNextLink(GetLink(pval, plast));
        pcurrlink = pprevlink->GetNexLink();
        listlen++;
    }
}

void List::InsCurrent(PValue pval) {
    if (pprevlink != NULL) {
        pprevlink->SetNextLink(GetLink(pval, pcurrlink));
        pcurrlink = pprevlink->GetNexLink();
        listlen++;
    } else {
        InsFirst(pval);
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
