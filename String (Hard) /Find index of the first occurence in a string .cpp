class Solution {
public:
    int strStr(string haystack, string needle) {
         
         if(haystack.size() < needle.size()) return -1;
         
         int n = haystack.size();
         int m = needle.size();

         for(int i = 0 ; i <= n - m ; i++){
              if(haystack.substr(i , m) == needle){
                    return i;
              }
         }
         return -1;
    }
};
