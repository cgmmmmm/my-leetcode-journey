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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return nullptr;
        if (!head->next || !head->next->next) return head;

        ListNode* oddNode = head;
        ListNode* evenStart = head->next;
        ListNode* evenNode = evenStart;

        while (oddNode->next && evenNode->next)
        {
            if (evenNode->next != nullptr)
            {
                oddNode->next = evenNode->next;
                oddNode = oddNode->next;
            }
            else break;
            if (oddNode->next != nullptr)
            {
                evenNode->next = oddNode->next;
                evenNode = evenNode->next;
            }
            else break;
        }
        evenNode->next = nullptr;
        oddNode->next = evenStart;

        return head;
    }
};