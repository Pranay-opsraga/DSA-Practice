class Solution {
public:
    bool detect(int node, vector<int>& vis,
                vector<int> adj[], vector<int>& pathvis) {
        
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (detect(it, vis, adj, pathvis)) return true;
            } 
            else if (pathvis[it]) {
                return true; 
            }
        }

        pathvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> adj[numCourses];

        for (auto e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (detect(i, vis, adj, pathvis)) {
                    return false; 
                }
            }
        }

        return true; 
    }
};
