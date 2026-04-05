class DSU {
     public:

     vector<int> parent , rank;

     DSU(int n){
           parent.resize(n);
           rank.resize(n , 0);
           for(int i = 0 ; i < n ; i++){
                 parent[i] = i;
           }
     }

     int findParent(int node){
          if( parent[node] == node) return node;
          return parent[node] = findParent(parent[node]);
     }

     void unite(int x , int y){
           int px = findParent(x);
           int py = findParent(y);

           if(px == py) return ;

           if(rank[px] > rank[py]) parent[py] = px;
           else if (rank[px] < rank[py]) parent[px] = py;
           else {
               parent[py] = px;
               rank[px]++; 
           }

     }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
       vector<int>ans;
	   vector<vector<int>>vis(n , vector<int>(m , 0));
       int count = 0;

       DSU ds(n * m );

       for(auto it : q){
             int row = it[0];
             int col = it[1];
             int node = (row * m) + col;

             if(vis[row][col]) {
               ans.push_back(count);
               continue;
              }
             vis[row][col] = 1;
             count++;

             
             int dRow[4] = {-1, 0, 1, 0};
             int dCol[4] = {0, 1, 0, -1};

             for(int i = 0 ; i < 4 ; i++){
                  int nrow = row + dRow[i];
                  int ncol = col + dCol[i];
                  
                  
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]) {

                int newNode = (nrow * m) + ncol;

                      if(ds.findParent(node) != ds.findParent(newNode)) {
                      ds.unite(node , newNode);
                      count--;
                      }
                  }
             }
              ans.push_back(count);
           }
            return ans;
       }
      

