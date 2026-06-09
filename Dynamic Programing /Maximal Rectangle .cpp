class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int element = st.top();
                st.pop();
                int NSE = i;
                int PSE = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, (NSE - PSE - 1) * heights[element]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();

            int NSE = n;
            int PSE = st.empty() ? -1 : st.top();

            maxarea = max(maxarea, (NSE - PSE - 1) * heights[element]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int maxarea = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            maxarea = max(maxarea, largestRectangleArea(heights));
        }

        return maxarea;
    }
};
