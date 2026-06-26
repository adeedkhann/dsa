class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            int dist = x * x + y * y;

            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> vp;
        while (!pq.empty()) {
            int index = pq.top().second;
            vp.push_back(points[index]);
            pq.pop();
        }

        return vp;
    }
};