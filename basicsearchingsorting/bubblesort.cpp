class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
       
       for(int i =0;i<arr.size();i++){
           for(int j =0;j<arr.size();j++){
               if(arr[i]<arr[j]) swap(arr[i],arr[j]);
           }
       }
        
    }
};