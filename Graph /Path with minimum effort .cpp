class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) return effort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int diff = abs(heights[r][c] - heights[nr][nc]);

                    int neweffort = max(effort, diff);

                    if (dist[nr][nc] > neweffort) {
                        dist[nr][nc] = neweffort;
                        pq.push({neweffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
