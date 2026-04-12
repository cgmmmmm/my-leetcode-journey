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
    ListNode* mergeNodes(ListNode* head) {
        // create a new ptr that stores head's memory address
        ListNode* tmp = head;
        ListNode* deletionNode;

        while (tmp->next->next)
        {
            if (tmp->next->next->next == nullptr)
            {
                deletionNode = tmp; 
            }

            if (tmp->next->val != 0)
            {
                tmp->val += tmp->next->val;
                tmp->next = tmp->next->next;
            }
            else
            {
                tmp = tmp->next;
            }
        }

        // remove trailing zero
        deletionNode->next = nullptr;

        return head;
    }
};
