class DSU {
public:
    vector<int> parent, sizze;

    DSU(int n) {
        parent.resize(n);
        sizze.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp) return;

        if (sizze[xp] > sizze[yp]) {
            parent[yp] = xp;
            sizze[xp] += sizze[yp];
        } else {
            parent[xp] = yp;
            sizze[yp] += sizze[xp];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // 🔹 Step 1: Build DSU for all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {

                            int node1 = i * n + j;
                            int node2 = ni * n + nj;

                            ds.unite(node1, node2);
                        }
                    }
                }
            }
        }

        int ans = 0;

        // 🔹 Step 2: Try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {

                    unordered_set<int> st;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {

                            st.insert(ds.find(ni * n + nj));
                        }
                    }

                    int total = 1;
                    for (auto it : st) {
                        total += ds.sizze[it];
                    }

                    ans = max(ans, total);
                }
            }
        }

        // 🔹 Step 3: Handle case where grid has no 0
        for (int i = 0; i < n * n; i++) {
            if (ds.find(i) == i) {
                ans = max(ans, ds.sizze[i]);
            }
        }

        return ans;
    }
};
