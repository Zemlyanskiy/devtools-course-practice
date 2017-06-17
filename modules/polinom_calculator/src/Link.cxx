//  Copyright 2017 Ivan Kiselev
#include "../include/Link.h"

Link::Link(PValue pVal, PRootLink pN) : RootLink(pN) {
    pValue_ = pVal;
}

Link::Link(const Link &val) : RootLink(val.pNext_) {
    pValue_ = val.pValue_;
}

Link::~Link() {}

void Link::SeValue(PValue pVal) {
    pValue_ = pVal;
}

PValue Link::GeValue() {
    return pValue_;
}

Link* Link::GetNexLink() {
    return reinterpret_cast<Link*>(pNext_);
}
