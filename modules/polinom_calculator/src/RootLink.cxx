//  Copyright 2017 Ivan Kiselev
#include "../include/RootLink.h"
RootLink::RootLink(PRootLink pN) {
    pNext_ = pN;
}

void RootLink::SetNextLink(PRootLink pLink) {
    pNext_ = pLink;
}

RootLink::~RootLink() {}

PRootLink RootLink::GetNextLink() {
    return pNext_;
}

void RootLink::InsNextLink(PRootLink pLink) {
    PRootLink p = pNext_;
    pNext_ = pLink;
    if (pLink != NULL) pLink->pNext_ = p;
}
