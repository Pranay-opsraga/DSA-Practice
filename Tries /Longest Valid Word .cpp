struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool checkIfPrefixExist(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);

            if (!node->isEnd())
                return false;
        }

        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {

        Trie trie;

        for (auto &word : words) {
            trie.insert(word);
        }

        string longest = "";

        for (auto &word : words) {

            if (trie.checkIfPrefixExist(word)) {

                if (word.length() > longest.length()) {
                    longest = word;
                }
                else if (word.length() == longest.length() &&
                         word < longest) {
                    longest = word;
                }
            }
        }

        return longest;
    }
};
