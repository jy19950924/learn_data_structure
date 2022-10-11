#include "linkedList.h"

LinkedList::LinkedList(T *p, size_t n)
{
    this->head = new ListNode();
    ListNode *cur = this->head;
    for (int i = 0; i < n; i++)
    {
        cur->next = new ListNode(p[i]);
        cur = cur->next;
    }
}

void LinkedList::draw()
{
    if (hasCircle())
    {
        drawCircle();
    }
    drawNoCircle();
}

void LinkedList::drawNoCircle()
{
    using namespace std;
    ListNode *cur = this->head->next;
    while (cur != nullptr)
    {
        cout << cur->val;
        if (cur->next != nullptr)
        {
            cout << " -> ";
        }
        cur = cur->next;
    }
    cout << endl;
}

bool LinkedList::hasCircle()
{
    ListNode *fast, *slow = this->head;

    return false;
}

void LinkedList::drawCircle()
{
}

int main()
{
    using namespace std;
    int len = 10;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : arr)
    {
        cout << i << endl;
    }

    auto *l1 = new LinkedList(arr, len);
    cout << "print linked list :\n";
    l1->draw();

    return 0;
}
