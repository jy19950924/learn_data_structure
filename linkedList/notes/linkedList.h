#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <climits>
#include <string>

typedef int T;

struct ListNode
{
    ListNode *next;
    T val;

    ListNode(){};

    ListNode(ListNode *next) : val(INT_MIN), next(next){};

    ListNode(int n) : val(n), next(nullptr){};

    ListNode(int n, ListNode *nextNode) : val(n), next(nextNode){};
};

struct LinkedList
{
    ListNode *head;

    LinkedList() : head(new ListNode()){};

    LinkedList(T *p, size_t n);

    void draw();

private:
    void drawNoCircle();

    void drawCircle();

    bool hasCircle();
};

#endif
