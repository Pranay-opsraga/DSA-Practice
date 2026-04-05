class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[py] > rank[px])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(it[0], maxRow);
            maxCol = max(it[1], maxCol);
        }
        DSU ds(maxRow + maxCol + 2);
        unordered_map<int, int> mpp;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unite(nodeRow, nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : mpp) {
            if (ds.find(it.first) == it.first)
                cnt++;
        }
        return n - cnt;
    }
};
