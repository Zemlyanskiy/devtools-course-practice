//  Copyright 2017 Ivan Kiselev
#include "../include/TRootLink.h"
TRootLink::TRootLink(PTRootLink pN) {
    pNext_ = pN;
}

void TRootLink::SetNextLink(PTRootLink pLink) {
    pNext_ = pLink;
}
