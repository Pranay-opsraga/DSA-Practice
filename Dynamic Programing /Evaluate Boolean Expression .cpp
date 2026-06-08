class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;

        for (char c : expression) {

            if (c == ',')
                continue;
            if (c != ')')
                st.push(c);
            else {

                int t = 0;
                int f = 0;

                while (!st.empty() && st.top() != '(') {
                    if (st.top() == 't')
                        t++;
                    else if (st.top() == 'f')
                        f++;
                    st.pop();
                }
                st.pop();

                char op = st.top();
                st.pop();

                char res;

                if(op == '!') res = (t > 0) ? 'f' : 't';
                else if(op == '|') res = (t > 0) ? 't' : 'f';
                else res = (f > 0) ? 'f' : 't';
                st.push(res);
            }
        }
        return (st.top() == 't');
    }
};
