#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "LinkedList.hpp"

/* Fixtures */
// LinkedList containing only multiple node
class LinkedListDataInit : public testing::Test {
protected:
    LinkedList ll;
    void SetUp() override {
        ll.insertEnd(1);
        ll.insertEnd(2);
        ll.insertEnd(3);
        ll.insertEnd(4);
        ll.insertEnd(5);
    }
};

// LinkedList containing only one node
class LinkedListSingleInit : public testing::Test {
protected:
    LinkedList ll;
    void SetUp() override {
        ll.insertHead(5);
    }
};

/* Helper Functions */
// get tail node data
int getTailData(Node* node) {
    while (node->next != nullptr) {
        node = node->next;
    }
    return node->data;
}

// convert linked list data to vector representation
std::vector<int> convertLinkedListToVector(Node* head) {
    std::vector<int> result;
    Node* temp = head;
    while(temp) {
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

/* Linked List Insertion */

// test insertHead method on empty linked list
TEST(LinkedListEmptyInit, InsertHeadTest) {
    LinkedList ll;
    ll.insertHead(1);
    ASSERT_EQ(1, ll.getHead()->data);
    ll.insertHead(2);
    ASSERT_EQ(2, ll.getHead()->data);
    ll.insertHead(3);
    ASSERT_EQ(3, ll.getHead()->data);
}

// test insertHead method on filled linked list
TEST_F(LinkedListDataInit, InsertHeadTest) {
    ll.insertHead(6);
    ll.insertHead(7);

    int expectedOutput[] = {7, 6, 1, 2, 3, 4, 5};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 7; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

// test insertEnd method on empty linked list
TEST(LinkedListEmptyInit, InsertEndTest) {
    LinkedList ll;
    ll.insertEnd(1);
    ASSERT_EQ(1, ll.getHead()->data);
    ll.insertEnd(2);
    ASSERT_EQ(1, ll.getHead()->data);
    ASSERT_EQ(2, getTailData(ll.getHead()));
    ll.insertEnd(3);
    ASSERT_EQ(3, getTailData(ll.getHead()));
    ll.insertEnd(4);
    ASSERT_EQ(4, getTailData(ll.getHead()));
}

// test insertEnd method on filled linked list
TEST_F(LinkedListDataInit, InsertEndTest) {
    ll.insertEnd(6);
    ll.insertEnd(7);

    int expectedOutput[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 7; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

// test insertAt method on empty linked list
TEST(LinkedListEmptyInit, InsertAtTest) {
    LinkedList ll;
    ll.insertAt(4, 3);
    ll.insertAt(2, 1);
    ll.insertAt(5, 3);
    ll.insertAt(1, 5);
    ll.insertAt(3, 2);

    int expectedOutput[] = {2, 3, 4, 5, 1};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 5; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

// test insertAt method on filled linked list
TEST_F(LinkedListDataInit, InsertAtTest) {
    ll.insertAt(6, 3);
    ll.insertAt(7, 0);
    ll.insertAt(8, 10);
    int expectedOutput[] = {7, 1, 2, 6, 3, 4, 5, 8};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 8; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

/* Linked List GetLength */

// test getLength method on empty linked list
TEST(LinkedListEmptyInit, GetLengthTest) {
    LinkedList ll;
    ASSERT_EQ(0, ll.getLength());
    ll.insertAt(4, 3);
    ASSERT_EQ(1, ll.getLength());
    ll.insertAt(2, 1);
    ASSERT_EQ(2, ll.getLength());
    ll.insertAt(5, 3);
    ASSERT_EQ(3, ll.getLength());
    ll.insertAt(1, 5);
    ASSERT_EQ(4, ll.getLength());
    ll.insertAt(3, 2);
    ASSERT_EQ(5, ll.getLength());
}

// test getLength method on filled linked list
TEST_F(LinkedListDataInit, GetLengthTest) {
    ASSERT_EQ(5, ll.getLength());
    ll.insertAt(5, 3);
    ASSERT_EQ(6, ll.getLength());
}

/* Linked List Deletion */

// test deleteHead method on empty linked list
TEST(LinkedListEmptyInit, DeleteHeadTest) {
    LinkedList ll;
    ASSERT_EQ(-1, ll.deleteHead());

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteHead method on single linked list
TEST_F(LinkedListSingleInit, DeleteHeadTest) {
    ASSERT_EQ(5, ll.deleteHead());
    ASSERT_EQ(-1, ll.deleteHead());
    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteHead method on filled linked list
TEST_F(LinkedListDataInit, DeleteHeadTest) {
    ll.insertHead(8);
    ASSERT_EQ(8, ll.deleteHead());

    for (int i = 1; i < 6; i++)
        ASSERT_EQ(i, ll.deleteHead());

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteEnd method on empty linked list
TEST(LinkedListEmptyInit, DeleteEndTest) {
    LinkedList ll;

    ll.insertHead(5);
    ASSERT_EQ(5, ll.deleteEnd());

    ll.insertHead(9);
    ASSERT_EQ(9, ll.deleteEnd());

    for (int i = 0; i < 5; i++)
        ASSERT_EQ(-1, ll.deleteEnd());

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteEnd method on single linked list
TEST_F(LinkedListSingleInit, DeleteEndTest) {
    ASSERT_EQ(5, ll.deleteEnd());
    ASSERT_EQ(-1, ll.deleteEnd());
    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteEnd method on filled linked list
TEST_F(LinkedListDataInit, DeleteEndTest) {
    ll.insertEnd(8);
    ASSERT_EQ(8, ll.deleteEnd());

    for (int i = 5; i > 0; i--)
        ASSERT_EQ(i, ll.deleteEnd());

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteAt method on empty linked list
TEST(LinkedListEmptyInit, DeleteAtTest) {
    LinkedList ll;
    ASSERT_EQ(-1, ll.deleteAt(3));
    ASSERT_EQ(-1, ll.deleteAt(0));
    ASSERT_EQ(-1, ll.deleteAt(-5));

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteAt method on single linked list
TEST_F(LinkedListSingleInit, DeleteAtTest) {
    ASSERT_EQ(-1, ll.deleteAt(2));
    ASSERT_EQ(-1, ll.deleteAt(-1));
    ASSERT_EQ(-1, ll.deleteAt(0));
    ASSERT_EQ(5, ll.deleteAt(1));
    ASSERT_EQ(-1, ll.deleteAt(1));
    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test deleteAt method on filled linked list
TEST_F(LinkedListDataInit, DeleteAtTest) {
    ASSERT_EQ(3, ll.deleteAt(3));
    ASSERT_EQ(4, ll.deleteAt(3));
    ASSERT_EQ(-1, ll.deleteAt(0));
    ASSERT_EQ(-1, ll.deleteAt(5));
    ASSERT_EQ(-1, ll.deleteAt(4));
    ASSERT_EQ(5, ll.deleteAt(3));
    ASSERT_EQ(1, ll.deleteAt(1));
    ASSERT_EQ(2, ll.deleteAt(1));

    // after removing every node from linked list, head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test dataAt method on empty linked list
TEST(LinkedListEmptyInit, DataAtTest) {
    LinkedList ll;
    ASSERT_EQ(-1, ll.dataAt(0));
    ASSERT_EQ(-1, ll.dataAt(-1));
    ASSERT_EQ(-1, ll.dataAt(1));
}

// test dataAt method on empty linked list
TEST_F(LinkedListSingleInit, DataAtTest) {
    ASSERT_EQ(-1, ll.dataAt(-2));
    ASSERT_EQ(-1, ll.dataAt(0));
    ASSERT_EQ(5, ll.dataAt(1));
    ASSERT_EQ(-1, ll.dataAt(2));
    ASSERT_EQ(1, ll.getLength());
}

// test dataAt method on empty linked list
TEST_F(LinkedListDataInit, DataAtTest) {
    for (int i = 1; i < 6; i++)
        ASSERT_EQ(i, ll.dataAt(i));
    ASSERT_EQ(-1, ll.dataAt(0));
    ASSERT_EQ(-1, ll.dataAt(-1));
}

/* Reverse Test */

// test reverse method on empty linked list
TEST(LinkedListEmptyInit, ReverseTest) {
    LinkedList ll;
    ll.Reverse();

    // after removing every node from linked list,
    // head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test reverse method on single node linked list
TEST_F(LinkedListSingleInit, ReverseTest) {
    ll.Reverse();
    ASSERT_EQ(1, ll.getLength());
    ASSERT_EQ(5, ll.dataAt(1));
}

// test reverse method on multiple node linked list
TEST_F(LinkedListDataInit, ReverseTest) {
    ll.Reverse();
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());
    for (int i = 0; i < 5; i++)
        ASSERT_EQ(ll_vector[i], 5-i);
}



// test reverse method (recursive) on empty linked list
TEST(LinkedListEmptyInit, ReverseRecursiveTest) {
    LinkedList ll;
    ll.ReverseRecursive(ll.getHead());

    // after removing every node from linked list,
    // head should point to nullptr
    ASSERT_EQ(nullptr, ll.getHead());
    ASSERT_EQ(0, ll.getLength());
}

// test reverse method (recursive) on single node linked list
TEST_F(LinkedListSingleInit, ReverseRecursiveTest) {
    ll.ReverseRecursive(ll.getHead());
    ASSERT_EQ(1, ll.getLength());
    ASSERT_EQ(5, ll.dataAt(1));
}

// test reverse method (recursive) on multiple node linked list
TEST_F(LinkedListDataInit, ReverseRecursiveTest) {
    ll.ReverseRecursive(ll.getHead());
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());
    for (int i = 0; i < 5; i++)
        ASSERT_EQ(ll_vector[i], 5-i);
}