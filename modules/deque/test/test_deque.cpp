// Copyright 2017 Nazarov Aleksandr and Vinogradova Ekaterina

#include <gtest/gtest.h>
#include <string>

#include "include/deque.h"

TEST(Deque, can_create_deque) {
    ASSERT_NO_THROW(Deque deq);
}

TEST(Deque, can_create_copy_deque) {
    Deque deq;

    deq.InsFront("test string");

    ASSERT_NO_THROW(Deque deq2(deq));
}

TEST(Deque, can_create_copy_deque_with_null_size) {
    Deque deq(0);

    ASSERT_NO_THROW(Deque deq2(deq));
}

TEST(Deque, cant_create_deque_with_negative_size) {
    ASSERT_ANY_THROW(Deque deq(-5));
}

TEST(Deque, can_InsFront_in_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_NO_THROW(deq.InsFront("test"));
}

TEST(Deque, cant_InsFront_in_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.InsFront("test"));
}

TEST(Deque, cant_InsFront_in_full_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront("test");

    ASSERT_ANY_THROW(deq.InsFront("test"));
}

TEST(Deque, can_InsBack_in_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_NO_THROW(deq.InsBack("test"));
}

TEST(Deque, cant_InsBack_in_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.InsBack("test"));
}

TEST(Deque, cant_InsBack_in_full_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsBack("test");

    ASSERT_ANY_THROW(deq.InsBack("test"));
}

TEST(Deque, can_GetFront_from_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront("test");

    ASSERT_NO_THROW(deq.GetFront());
}

TEST(Deque, GetFront_get_front_element) {
    const int size = 5;
    Deque deq(size);
    std::string number;

    for (int i = 0; i < size; i++) {
        number.push_back(static_cast<char>(i));
        deq.InsFront("teststring" + number);
        number.clear();
    }
    number.push_back(static_cast<char>(size - 1));

    ASSERT_EQ(deq.GetFront(), "teststring" + number);
}

TEST(Deque, cant_GetFront_from_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.GetFront());
}

TEST(Deque, cant_GetFront_from_empty_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_ANY_THROW(deq.GetFront());
}

TEST(Deque, can_GetBack_from_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront("test");

    ASSERT_NO_THROW(deq.GetBack());
}

TEST(Deque, GetBack_get_back_element) {
    const int size = 5;
    Deque deq(size);

    deq.InsFront("checking");
    for (int i = 1; i < size; i++)
        deq.InsFront("tests");

    ASSERT_EQ(deq.GetBack(), "checking");
}

TEST(Deque, cant_GetBack_from_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.GetBack());
}

TEST(Deque, cant_GetBack_from_empty_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_ANY_THROW(deq.GetBack());
}

TEST(Deque, empty_deque_is_empty) {
    const int size = 5;
    Deque deq(size);

    ASSERT_TRUE(deq.IsEmpty());
}

TEST(Deque, deque_with_elements_not_empty) {
    const int size = 5;
    Deque deq(size);

    deq.InsFront("test");
    deq.InsBack("test");

    ASSERT_FALSE(deq.IsEmpty());
}

TEST(Deque, full_deque_is_full) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront("test");

    ASSERT_TRUE(deq.IsFull());
}

TEST(Deque, full_deque_not_full_after_get) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront("test");
    deq.GetFront();

    ASSERT_FALSE(deq.IsFull());
}

TEST(Deque, empty_deque_not_empty_after_put) {
    const int size = 5;
    Deque deq(size);

    deq.InsBack("test");

    ASSERT_FALSE(deq.IsEmpty());
}

TEST(Deque, can_save_into_file) {
    const int size = 5;
    Deque deq(size);
    std::ifstream file_test_stream;
    char line_buffer[255];

    deq.InsBack("test\n");
    deq.InsBack("test");
    deq.Save("FileTesting.test");
    file_test_stream.open("FileTesting.test");
    file_test_stream.getline(line_buffer, 255);

    EXPECT_EQ(deq.GetBack(), std::string(line_buffer));
}

TEST(Deque, can_load_from_file) {
    const int size = 5;
    Deque deq(size);
    std::ofstream file_test_stream("FileTesting.test");
    std::string testing_string("test");
    file_test_stream << testing_string;
    file_test_stream.close();

    deq.Load("FileTesting.test");

    EXPECT_EQ(deq.GetFront(), testing_string);
}

TEST(Deque, cant_load_from_not_exist_file) {
    const int size = 5;
    Deque deq(size);

    ASSERT_ANY_THROW(deq.Load("wrongnamefile"));
}
