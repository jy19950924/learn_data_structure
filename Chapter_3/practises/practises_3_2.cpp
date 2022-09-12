//
// Created by dell on 9/12/2022.
//

#include "../../public.h"


class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {
    }
};

void showNodeList(Node *nodeTail) {
    while (nodeTail != nullptr) {
        int randValue = (nodeTail->random == nullptr) ? -1 : nodeTail->random->val;
        cout << nodeTail->val << "->" << randValue << endl;
        nodeTail = nodeTail->next;
    }
}

class Solution {
public:

    Node *copyRandomList(Node *head) {
        /**
         *  细节点1：
         *      a. 不可以在连接random关系时，进行拆分，因为可能存在向后指向的情况。
         *      如果后面节点存在指向该节点的情况，则可能可能会无法找到拷贝节点。
         */
//        1. 拷贝所有节点
        Node *tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = new Node(tHead->val);
            copyNode->next = tHead->next;
            tHead->next = copyNode;
            tHead = tHead->next->next;
        }
//        2. 二次遍历连接random关系
        tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = tHead->next;
            if (tHead->random == nullptr)
                copyNode->random = nullptr;
            else
                copyNode->random = tHead->random->next;
            tHead = tHead->next->next;
        }
//        3. 分离节点
        Node *copyHead = new Node(-1);
        Node *copyTail = copyHead;
        tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = tHead->next;
            Node *nextNode = tHead->next->next;

            tHead->next = nextNode;

            copyTail->next = copyNode;
            copyTail = copyTail->next;

            tHead = tHead->next;
        }
        return copyHead->next;
    }
};

int main() {
    array<array<int, 2>, 5> arr =
            {
                    array{7, -1},
                    array{13, 0},
                    array{11, 4},
                    array{10, 2},
                    array{1, 0}
            };
    vector<Node *> nodeList(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++) {
        Node *node = new Node(arr[i][0]);
        nodeList[i] = node;
    }
    for (int i = 0; i < arr.size(); i++) {
        nodeList[i]->next = nodeList[i + 1];
        if (i == arr.size() - 1) {
            nodeList[i]->next = nullptr;
        }
        if (arr[i][1] == -1) {
            nodeList[i]->random = nullptr;
        } else {
            nodeList[i]->random = nodeList[arr[i][1]];
        }
    }

    Node *nodeHead = nodeList[0];
    Node *nodeTail = nodeHead;
    showNodeList(nodeHead);
    cout << "=========== copy ==============" << endl;
    Solution s = Solution();
    Node *res = s.copyRandomList(nodeHead);
    showNodeList(res);

    return 0;
}
