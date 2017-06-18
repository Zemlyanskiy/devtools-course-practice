//  Copyright 2017 Ivan Kiselev
#include "../include/RootLink.h"
RootLink::RootLink(PRootLink pN) {
    pnext_ = pN;
}

void RootLink::SetNextLink(PRootLink pLink) {
    pnext_ = pLink;
}

RootLink::~RootLink() {}

PRootLink RootLink::GetNextLink() {
    return pnext_;
}

void RootLink::InsNextLink(PRootLink pLink) {
    PRootLink p = pnext_;
    pnext_ = pLink;
    if (pLink != NULL) pLink->pnext_ = p;
}
