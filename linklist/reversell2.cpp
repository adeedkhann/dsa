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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right) return head ;
        if (head == NULL) return NULL;
        int count = 1;
        ListNode *temp = head;
        ListNode * prevnode = NULL;
        ListNode * prev= NULL;
        while(temp != NULL){
            if(count<left){
                prevnode = temp ;
                temp = temp->next;
                count++;
                continue;
            }
            ListNode * curr = temp;
            int times = right - left +1;

            while(times--){
                ListNode * next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            temp->next = curr;
            break;
        }
         if(prevnode){
            prevnode->next = prev;
            return head;
            }else{
                return prev;
            }
        
    }
};