class Solution {
public:
    void dfs(string beginWord, string word, vector<string>& seq,
             vector<string>& wordList, unordered_map<string, int>& mpp,
             vector<vector<string>>& ans) {
        if (word == beginWord) {
            vector<string> temp = seq;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = mpp[word];

        for (int i = 0; i < word.size(); i++) {
            char og = word[i];

            for (char ch = 'a'; ch <= 'z' ; ch++) {
                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(beginWord, word, seq, wordList, mpp, ans);
                    seq.pop_back();
                }
            }
            word[i] = og;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        queue<string> q;
        unordered_map<string, int> mpp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        mpp[beginWord] = 1;
        st.erase(beginWord);
        q.push(beginWord);
        vector<vector<string>> ans;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            for (int i = 0; i < word.size(); i++) {
                char og = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        st.erase(word);
                        mpp[word] = steps + 1;
                        q.push(word);
                    }
                }
                word[i] = og;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(beginWord, endWord, seq, wordList, mpp, ans);
        }

        return ans;
    }
};
