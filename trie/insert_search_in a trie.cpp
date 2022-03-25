class Trie {
	struct Node{
        Node *links[26];
        bool flag = false;
        bool containskey(char ch)
        {
            return (links[ch-'a']!=NULL);
        }
        void put(char ch , Node * node)
        {
            links[ch-'a'] = node;
        }
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
        bool setend()
        {
            flag = true;
        }
        bool isend()
        {
            return flag;
        }
    };
    private:
    Node * root;   
    public:
    
    Trie() { 
        root = new Node();
    }
    // tc = O(len of the word)
    void insert(string word) {	
		Node *node = root;
        for(auto i : word)
        {
            if(!node->containskey(i))
            {
                // curr node does not have this char
                node->put(i , new Node());
            }
            node = node->get(i);
        }
        node->setend();
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
		Node * node = root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(!node->containskey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isend() ? true : false;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		Node * node = root;
        for(int i = 0 ;i < prefix.size() ; i++)
        {
            if(!node->containskey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
