//  Copyright 2017 Ivan Kiselev
#include "../include/TDatList.h"
PTDatValue TDatList::GetDatValue() {
return pCurrLink->pValue;
}

TDatList::TDatList() {
pFirst = new TDatLink(NULL, NULL);
pLast = pFirst;
pCurrLink = pFirst;
pPrevLink = NULL;
pStop = pFirst;
CurrPos = 0;
ListLen = 0;
}

/*TDatList::TDatList(const TDatList &List) : TDatList() {
int k = 0;
pCurrLink = List.pFirst;
while (k < List.ListLen) {
	k++;
	if (pCurrLink != NULL) InsLast(pCurrLink->GetDatValue());
}
}*/

void TDatList::Reset(void) {
pCurrLink = pFirst;
pPrevLink = NULL;
CurrPos = 0;
}

bool TDatList::IsListEnded(void) const {
return ((CurrPos >= ListLen) || (pCurrLink == pLast));
}

int TDatList::GoNext(void) {
if (IsListEnded()) return 1;
pPrevLink = pCurrLink;
pCurrLink = pCurrLink->GetNextDatLink();
CurrPos++;
return 0;
}

void TDatList::InsFirst(PTDatValue pVal) {
pFirst = GetLink(pVal, pFirst);
ListLen++;
}

void TDatList::InsLast(PTDatValue pVal) {
if (pFirst->pValue == NULL) {
InsFirst(pVal);
} else {
while (GoNext() != 1) {}
pPrevLink->SetNextLink(GetLink(pVal, pLast));
pCurrLink = pPrevLink->GetNextDatLink();
ListLen++;
}
}

void TDatList::InsCurrent(PTDatValue pVal) {
if (pPrevLink != NULL) {
pPrevLink->SetNextLink(GetLink(pVal, pCurrLink));
pCurrLink = pPrevLink->GetNextDatLink();
ListLen++;
} else {
InsFirst(pVal);
}
}

void TDatList::DelFirst(void) {
PTDatLink old = pFirst;
pFirst = pFirst->GetNextDatLink();
ListLen--;
old->~TDatLink();
}

void TDatList::DelCurrent(void) {
if (pCurrLink == pFirst) {
DelFirst();
} else {
PTDatLink old = pCurrLink;
pPrevLink->SetNextLink(pCurrLink->GetNextLink());
pCurrLink = pCurrLink->GetNextDatLink();
old->~TDatLink();
ListLen--;
}
}

void TDatList::DelList(void) {
while (ListLen > 0) DelFirst();
}
