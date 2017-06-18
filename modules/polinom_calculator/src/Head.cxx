//  Copyright 2017 Ivan Kiselev
#include "../include/Head.h"
Head::Head() {
    phead_ = new Link();
    phead_->SetNextLink(pfirst);
    pstop = phead_;
    plast->SetNextLink(phead_);
}

void Head::InsFirst(PValue pval) {
    List::InsFirst(pval);
    phead_->SetNextLink(pfirst);
    if (pcurrlink == pfirst->GetNexLink()) {
        pprevlink = pfirst;
        currpos = 1;
    }
}

void Head::DelFirst(void) {
    List::DelFirst();
    phead_->SetNextLink(pfirst);
}
