/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr || head->next == nullptr) return head;
        if (k == 0) return head;

        int len = 1;
        ListNode* moveNode = head;
        while (moveNode->next != nullptr)
        {
            moveNode = moveNode->next;
            len++;
        }

        int numberOfRotationRequired = (k >= len) ? k % len : k;
        if (numberOfRotationRequired == 0) return head;

        ListNode* startNode = head;
        ListNode* endNode = head;
        while (len != numberOfRotationRequired)
        {
            if (len - numberOfRotationRequired == 1) 
            {   
                endNode = startNode;
            }
            startNode = startNode->next;
            len--;
        }

        endNode->next = nullptr;
        moveNode->next = head;

        return startNode;
    }
};
