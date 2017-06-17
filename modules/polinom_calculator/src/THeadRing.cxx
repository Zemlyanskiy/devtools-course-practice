//  Copyright 2017 Ivan Kiselev
#include "../include/THeadRing.h"
THeadRing::THeadRing() {
    pHead_ = new Link();
    pHead_->SetNextLink(pFirst);
    pStop = pHead_;
    pLast->SetNextLink(pHead_);
}

void THeadRing::InsFirst(PValue pVal) {
    List::InsFirst(pVal);
    pHead_->SetNextLink(pFirst);
    if (pCurrLink == pFirst->GetNexLink()) {
        pPrevLink = pFirst;
        CurrPos = 1;
    }
}

void THeadRing::DelFirst(void) {
    List::DelFirst();
    pHead_->SetNextLink(pFirst);
}
