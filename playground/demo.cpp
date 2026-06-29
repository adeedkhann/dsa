#include<bits/stdc++.h>
using namespace std;

void getSubset(vector<int>& a, int n, int idx, vector<int>& temp) {
    if (idx == n) {
        if (temp.empty()) {
            cout << "{}" << endl;
            return;
        }
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    
    getSubset(a, n, idx + 1, temp);

    temp.push_back(a[idx]);
    getSubset(a, n, idx + 1, temp);

    temp.pop_back();
}

int main() {

    vector<int> a = {1, 2, 3};
    int n = a.size();
    vector<int> temp;
    
    getSubset(a, n, 0, temp);
    
    return 0;
}