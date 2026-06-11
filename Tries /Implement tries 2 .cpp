class Node {
    public:
    Node* links[26];

    Node() {
    for(int i = 0; i < 26; i++) {
        links[i] = nullptr;
    }
}

    bool flag = false;
    int cntword = 0;
    int cntEnd = 0;

    bool containsKey (char ch){
         return (links[ch - 'a'] != NULL);
    }

    void put (char ch , Node* node){
          links[ch - 'a'] = node;
    }

    Node* get (char ch){
         return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }
    
    void increaseword(){
        cntword++;
    }

    void increaseEnd(){
       cntEnd++;
    }

    void deleteEnd() {
        cntEnd--;
    }

    void reduceword() {
        cntword--;
    }

    int getEnd() {
        return cntEnd;
    }

    int getword() {
        return cntword;
    }


};

class Trie {
	public:
    Node* root;
	    Trie() {
	        root = new Node();
	    }

	    void insert(string word) {
	        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }
           node = node->get(word[i]);
           node->increaseword();
        }
        node->increaseEnd();
        node->setEnd();
    	}

	    int countWordsEqualTo(string word) {
	        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }

            node = node->get(ch);
        }

        return node->getEnd();
    	}

	    int countWordsStartingWith(string word) {
	        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }

            node = node->get(ch);
        }

        return node->getword();
    	}

	    void erase(string word) {
	        Node* node = root;

        for (char ch : word) {
            node = node->get(ch);
            node->reduceword();
        }

        node->deleteEnd();
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(word);
 * obj->erase(word);
 */
