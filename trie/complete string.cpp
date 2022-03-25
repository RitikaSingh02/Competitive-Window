//https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
// longest string whose all the prefixes are in the array A

struct Node
{
    Node * links[26];
    bool flag = false;
    bool containskey(char ch)
    {
        return (links[ch- 'a']!=NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void put(char ch , Node * node)
    {
        links[ch - 'a'] = node;
    }
    
    void setend()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
    }
   	
};
class Trie
{
    private:
    Node* root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node* node = root;
        for(int i =0 ; i < word.size() ; i++)
        {
            if(!node->containskey(word[i]))
            {
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
    bool checkifprefixexist(string word)
    {
        bool cond = true;
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(node->containskey(word[i]))
            {
                node = node->get(word[i]);
                if(node->isend() == false)
                    return false;
            }
            else
            	return false;
            	
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie *trie = new Trie();
    for(auto i : a)
    {
        trie->insert(i);    
    }
    string res = "";
    for(auto i : a)
    {
        if(trie->checkifprefixexist(i))
        {
            if(res.size() < i.size())
            {
                res = i;
            }
            else if(res.size() == i.size() && i < res)
                res = i;
        }
    }
    if(res == "") return "None";
    
    return res;
}
