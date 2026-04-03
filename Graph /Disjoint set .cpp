class DisjointSet {
public:
    vector<int> rank , parent , sizze;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n , 0);
        sizze.resize(n , 1);

        for(int i = 0 ; i < n ; i++){
              parent[i] = i;
        }
    }

    int findpar( int node){
         if(parent[node] == node) return node;
         return parent[node] = findpar( parent[node]);

    }
      

    bool find(int u, int v) {
       return ( parent[u] == parent[v]);
    }

    void unionByRank(int u, int v) {
         int pu = findpar(u);
         int pv = findpar(v);

         if(pu == pv) return;
         if(rank[pu] > rank[pv]) parent[pv] = pu;
         else if (rank[pv] > rank[pu]) parent[pu] = pv;
         else{
            parent[pu] = pv;
            rank[pu]++;
         }
    }

    void unionBySize(int u, int v) {
          int pu = findpar(u);
          int pv = findpar(v);

          if(sizze[pu] > sizze[pv]) {
            parent[pv] = pu;
            sizze[pu] += sizze[pv];
          }
          else{
               parent[pu] = pv;
               sizze[pv] += sizze[pu];
          }
    }

};
