//  Copyright 2017 Ivan Kiselev
#include "../include/Link.h"

Link::Link(PValue pVal, PRootLink pN) : RootLink(pN) {
    pvalue_ = pVal;
}

Link::Link(const Link &val) : RootLink(val.pnext_) {
    pvalue_ = val.pvalue_;
}

Link::~Link() {}

void Link::SeValue(PValue pVal) {
    pvalue_ = pVal;
}

PValue Link::GeValue() {
    return pvalue_;
}

Link* Link::GetNexLink() {
    return reinterpret_cast<Link*>(pnext_);
}
