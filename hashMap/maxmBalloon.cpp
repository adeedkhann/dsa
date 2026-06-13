class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int>mp;
        for(int i =0;i<text.size();i++){
            mp[text[i]]++;
        }
        int freqA= mp['a'];
        int freqB = mp['b'];
        int freqL = mp['l'];
        int freqO = mp['o'];
        int freqN = mp['n'];

        int freq = min({freqA , freqB , freqL/2 , freqO/2 , freqN});
        return freq;

    }
};