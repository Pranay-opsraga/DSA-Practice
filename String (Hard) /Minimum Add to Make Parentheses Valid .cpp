class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;

        stack<char>st;

        for(char ch : s){
            if(ch == '('){
                 st.push(ch);
            } else {
                if(!st.empty()){
                    st.pop();
                } else ans++;
            }
        }
        return ans + st.size();
    }
};
