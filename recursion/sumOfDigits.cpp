class Solution {
    
    int sum(int n){
        
        if(n<10){
            return n;
        }
    
       return  n%10 + sum(n/10);
    }
    
    
    
  public:
    int sumOfDigits(int n) {
        return sum(n);
        
        
    }
};