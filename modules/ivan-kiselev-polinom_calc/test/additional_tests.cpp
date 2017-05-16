// Copyright 2017 Ivan Kiselev
#include <iostream>
#include "../3rdparty/gtest/gtest.h"
#include "../include/TPolinoms.h"
TEST(TDatList, DelCurrent) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 2 } };
    int size = 2;
    int ressize = 1;
    TPolinom pol(mon, size);
    TPolinom res(resmon, ressize);

    pol.Reset();
    pol.DelCurrent();

    EXPECT_TRUE(pol == &res);
}

TEST(TMonom, cout_test) {
    TMonom* mon = new TMonom(2, 1, 1, 1);
    GTEST_TEST_NO_FATAL_FAILURE_(std::cout << mon, GTEST_NONFATAL_FAILURE_);
}

TEST(TMonom, Equality1) {
    TMonom* mon1 = new TMonom(2, 1, 1, 1);
    TMonom* mon2 = new TMonom(2, 1, 1, 1);

    EXPECT_FALSE(mon2 < mon1);
}

TEST(TMonom, Equality2) {
    TMonom* mon1 = new TMonom(2, 1, 1, 1);
    TMonom* mon2 = new TMonom(2, 1, 1, 1);

    EXPECT_FALSE(mon1 > mon2);
}

TEST(TPolinom, Assignment_to_a_nonzero_polynom) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int mon2[][4] = { { 1, 0, 1, 0 } , { 3, 0, 0, 2 } };
    int size = 2;
    TPolinom pol(mon, size);
    TPolinom pol2(mon2, size);

    pol2 = pol;

    EXPECT_TRUE(pol == &pol2);
}

TEST(TPolinom, Not_Equal_polinoms1) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 2 } };
    int size = 2;
    int ressize = 1;
    TPolinom pol(mon, size);
    TPolinom res(resmon, ressize);

    EXPECT_FALSE(pol == &res);
}

TEST(TPolinom, Not_Equal_polinoms2) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 2 } , { 10, 0, 0, 1 } };
    int size = 2;
    int ressize = 1;
    TPolinom pol(mon, size);
    TPolinom res(resmon, ressize);

    EXPECT_FALSE(pol == &res);
}

TEST(TPolinom, cout_polinom) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int size = 2;
    TPolinom pol(mon, size);

    GTEST_TEST_NO_FATAL_FAILURE_(std::cout << pol, GTEST_NONFATAL_FAILURE_);
}

TEST(THeadRing, can_create_THeadRing) {
    GTEST_TEST_NO_FATAL_FAILURE_(THeadRing thead, GTEST_NONFATAL_FAILURE_);
}

TEST(TRootLink, can_create_TRootLink) {
    GTEST_TEST_NO_FATAL_FAILURE_(PTRootLink troot(), GTEST_NONFATAL_FAILURE_);
}

TEST(TRootLink, can_set_next_link) {
    TDatLink* link = new TDatLink();
    TDatLink* TDL = new TDatLink();
    
    TDL->SetNextLink(reinterpret_cast<TRootLink*> (link));
    EXPECT_TRUE(TDL->GetNextLink() == link);
}
