class Solution {
public:
    int minLights(vector<int>& lights) {    
    int bulbs=0;
    int n = lights.size();
    vector <bool> covered(lights.size() , false);
    vector<int> diff(lights.size()+1 , 0);
    for(int i = 0; i<lights.size();i++){
        if(lights[i]>0){
            int right = min(n-1, i+lights[i]);
            int left = max(0 ,i- lights[i]);
            diff[left] +=1;
            diff[right+1] -=1;
        }
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum > 0) {
          covered[i] = true; 
         }
    }

    for(int i = 0;i<lights.size();i++){
        if(covered[i]==false){
            int newBulb = (i + 1 < n) ? (i + 1) : i;
            int left = max(0, newBulb - 1);
            int right = min(n - 1, newBulb + 1);
            for (int j = left; j <= right; j++) {
                    covered[j] = true;
                }
            bulbs++;
            i = right;
        }
    }
        return bulbs;

        
    }
};