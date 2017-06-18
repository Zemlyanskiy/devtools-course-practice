//  Copyright 2017 Ivan Kiselev
#include "../include/Head.h"
Head::Head() {
    pHead_ = new Link();
    pHead_->SetNextLink(pFirst);
    pStop = pHead_;
    pLast->SetNextLink(pHead_);
}

void Head::InsFirst(PValue pVal) {
    List::InsFirst(pVal);
    pHead_->SetNextLink(pFirst);
    if (pCurrLink == pFirst->GetNexLink()) {
        pPrevLink = pFirst;
        CurrPos = 1;
    }
}

void Head::DelFirst(void) {
    List::DelFirst();
    pHead_->SetNextLink(pFirst);
}
