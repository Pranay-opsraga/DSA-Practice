class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>, int>> q;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntfresh = 0;
        int cnt = 0;

        // Step 1: push all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }

                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        // Step 2: BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {

                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // Step 3: check
        if (cnt != cntfresh) return -1;

        return tm;
    }
};
