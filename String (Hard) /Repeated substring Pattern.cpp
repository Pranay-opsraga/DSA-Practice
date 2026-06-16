class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        int n = t.size();
        
        return (t.substr(1 , n-2).find(s) != string::npos);
    }
};
