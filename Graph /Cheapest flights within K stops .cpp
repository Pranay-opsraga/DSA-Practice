class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<pair<int,int>, int>> q;
        // {{stops, node}, cost}

        vector<int> dist(n, INT_MAX);

        q.push({{0, src}, 0});
        dist[src] = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int stops = front.first.first;
            int node = front.first.second;
            int cost = front.second;

            if (stops > k) continue;

            for (auto it : adj[node]) {
                int next = it.first;
                int price = it.second;

                if (cost + price < dist[next]) {
                    dist[next] = cost + price;
                    q.push({{stops + 1, next}, dist[next]});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
