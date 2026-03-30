class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] &&
                    grid[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({{nr , nc} , dist+1});
                }
            }
        }
        return -1;
    }
};
