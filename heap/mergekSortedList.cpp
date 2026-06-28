class Solution {
    struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;


        while (!pq.empty()) {

            ListNode* smallestNode = pq.top();
            pq.pop();

            temp->next = smallestNode;
            temp = temp->next;
            if (smallestNode->next != nullptr) {
                pq.push(smallestNode->next);
            }
        }
        ListNode* result = dummy->next;
        delete dummy; // kya sach me memory kam hogi ?? 
        return result;
    }
};
// this is the most optimised tareeka