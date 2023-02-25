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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        
        ListNode* temp1 = NULL;
        if(count == n)
        {
            temp1 = head;
            head = head->next;
            delete temp1;
            return head;
        }
        
        int pos = count - n;
        temp = head;
        int i = 0;
        while(i++ < pos-1)
        {
            temp = temp->next;
        }
    
        temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        
        return head;
    }
};