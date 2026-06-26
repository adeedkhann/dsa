class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i = 1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

//beat only 10percent  in time whie 5 percent in space'


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap; // min heap
        
        for(int i = 0; i < nums.size(); i++) {
            min_heap.push(nums[i]);
            
            // Agar heap ka size K se bada ho jaye, toh sabse chhota element pop kar do
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        // Aakhir me heap me sirf K sabse bade elements bachenge,
        // aur Min-Heap ke top par unka sabse chhota (Kth largest) hoga.
        return min_heap.top();
    }
};

// 42 time complex beet 