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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        DSU dsu(n);

        for (auto& c : connections) {
            dsu.unite(c[0], c[1]);
        }

        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                comp++;
        }
        return comp - 1;
    }
};
