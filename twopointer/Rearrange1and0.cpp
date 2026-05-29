class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int freq= count(arr.begin(),arr.end(),0);
        int j= arr.size()-1;
        for(int i=0;i<=j;i++){
            if(i<freq){
                arr[i]=0;
            }else{
                arr[i]=1;
            }
        }
    }
};


//fill approach

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int freq= count(arr.begin(),arr.end(),0);
        
        fill(arr.begin(),arr.begin()+freq,0);
        fill(arr.begin()+freq,arr.end(),1);
    }
};