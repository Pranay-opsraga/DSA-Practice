class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> height(n, vector<int>(n, INT_MAX));
        height[0][0] = grid[0][0];

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == n - 1)
                return node;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newNode = max(node, grid[nr][nc]);

                    if (newNode < height[nr][nc]) {
                        height[nr][nc] = newNode;
                        pq.push({newNode, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
