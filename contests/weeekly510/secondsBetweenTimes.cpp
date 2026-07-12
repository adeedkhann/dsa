class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string hour1 = startTime.substr(0 , 2);
        int h1 = stoi(hour1);
        string min1 = startTime.substr(3 ,2);
        int m1 = stoi(min1);
        string sec1 = startTime.substr(6 ,2);
        int s1 = stoi(sec1);
        int total1 = (h1 * 60 *60 ) + (m1*60) + s1;
        string hour2 = endTime.substr(0 , 2);
        int h2 = stoi(hour2);
        string min2 =endTime.substr( 3 ,2);
        int m2 = stoi(min2);
        string sec2 = endTime.substr(6 ,2);
        int s2 = stoi(sec2);
        int total2 = (h2 * 60 *60 ) + (m2*60) +s2;

        return total2-total1;
        
    
    }
};