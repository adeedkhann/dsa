class Solution {
private:
   int sq(int a){
    int sum = 0;
    while(a){
        int rem = a%10;
        a=a/10;
        sum += rem*rem;
    }
    return sum;
   }
public:
    bool isHappy(int n) {
     int slow = n;
     int fast =n;

     while(fast!=1){
        slow=sq(slow);
        fast = sq(fast);
        fast=sq(fast);

        if(slow==fast && slow!=1){
            return false;
        }
     }return true;

     
    } 
};