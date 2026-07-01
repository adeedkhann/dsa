#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin>>s;
    unordered_map<char ,int>mp;
    for(int i = 0;i<s.size();i++){
        mp[s[i]]++;
    }

    if(mp.size()%2 != 0){
        cout<<"IGNORE HIM!"<<endl;
    }else{
        cout<<"CHAT WITH HER!"<<endl;
    }
}