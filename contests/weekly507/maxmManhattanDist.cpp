class Solution {
public:
    int maxDistance(string moves) {

        int up = 0;
        int down = 0;
        int left = 0;
        int right=0;
        int under = 0;
        for(char i : moves){
            if(i=='U'){
                up++;
            }else if(i=='D'){
                down++;
            }else if(i=='L'){
                left++;

            }else if(i=='R'){
                right++;
            }else{
                under++;
            }
        }

        int horizontal =abs(right - left);
        int vertical = abs(up - down);
        int ans = (horizontal + vertical +under);
        return ans;
    }
};