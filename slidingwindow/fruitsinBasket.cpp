class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int , int > hm;
        int h=0;
        int l=0;
        int res=0;
        for(h=0;h<fruits.size();h++){
            hm[fruits[h]]++;
            while(hm.size()>2){
                hm[fruits[l]]--;
                if(hm[fruits[l]]==0){
                    hm.erase(fruits[l]);
                }
                l++;
            }

            res = max(res , h-l+1);
        }return res;
    }
};