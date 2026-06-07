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
    ListNode* middleNode(ListNode* head) {
     ListNode *point = head ;
     ListNode *sec = head;
     int count = 0;
     while(point->next!=NULL){
        point = point->next;
        count++;
     }

    if(count%2==0){
        count = (count+1)/2;
        for(int i =0;i<count;i++){
            sec = sec->next;
        }
        return sec;
    }else{
            count = count/2;
        for(int i =0;i<=count;i++){
            sec = sec->next;
        }
        return sec;
    }


    }
};

// soln number two;
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
    ListNode* middleNode(ListNode* head) {
     
     ListNode *slow = head;
     ListNode *fast = head;

    int count = 0;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
        count++;
    }
    if(fast->next==NULL){
        return slow;
    }else{
        return slow->next;
    }


   


    }
};