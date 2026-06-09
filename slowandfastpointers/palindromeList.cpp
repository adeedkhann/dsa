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
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode *sar= head;
        while(sar != NULL){
            v.push_back(sar->val);
            sar = sar->next;
        }

        
       int start = 0;
       int end = v.size()-1;

       while(start<end){
        if(v[start] != v[end]) return false;
        start++;
        end--;
       }return true;
    }
};


// ye slow and fast se bhi hojayega same as reorderList;