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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* temp = head;
        if(head->next != NULL)
        {
            head = head->next;
        }
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        while(temp != NULL && temp->next != NULL)
        {
            temp1 = temp->next;
            if(temp2!=NULL)
                temp2->next=temp1;
            
            temp->next = temp1->next;
            temp1->next = temp;
            temp2 = temp;
            temp = temp->next;
        }
        return head;
    }
};