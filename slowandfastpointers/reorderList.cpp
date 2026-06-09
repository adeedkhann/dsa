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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow =slow->next ;
            fast = fast ->next->next;
        }

        ListNode *cur = slow;
        ListNode *prev = NULL;

        while(cur != NULL){
            ListNode *nextNode =cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        ListNode *start = head;
        ListNode *mid = prev;
        while(mid->next !=NULL){
            
           ListNode *temp1 = start->next;
           ListNode *temp2 = mid->next;

            start -> next = mid;
            mid->next = temp1;

            start =temp1;
            mid = temp2;

        }

    }
};