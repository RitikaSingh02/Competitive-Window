class TrieNode {
public:
    TrieNode* next[2];  // creating a TrieNode array for storing 2 bits 1 and 0 
    TrieNode()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};

class Solution {
public:
    
    TrieNode* root = new TrieNode();   // creat a root node to connect everything 
    
     void insert(int num){
         
        TrieNode* curr = root;   // start from the root node
        
        for(int i=31;i>=0;i--)      // travel through all the bits (32 is the max limit)
        {
            int bit = (num>>i) & 1; 
            if(!curr->next[bit])    // no next(children to root trie ) is present then 
                curr->next[bit]=new TrieNode(); // add a new TrieNode
            
            curr=curr->next[bit];  // add the new bit in the newly formed TrieNode array
        }
    }
    
int max_xor(int num) {
    
        TrieNode* curr = root;  
        int ans=0;
        for(int i=31;i>=0;i--)  
        {
            int bit=(num>>i)&1;
       
            if(curr->next[!bit]) // we need a opposite bit that we get above
            {
                ans+= (1<<i); //basically did 2^i to get the num back
                curr=curr->next[!bit];  // move towards the next opposite of opposite  bit 
            }
            else curr=curr->next[bit]; // just move to next if no opposite bit found
            
        }
        return ans;
    }   
    
    int findMaximumXOR(vector<int>& nums) 
    {
        
        int max_ans=0;
        int n=nums.size();  

        
        for(int i=0;i<n;i++)
        {
            insert(nums[i]);        // insert all the numbers in the trie 
            max_ans=max(max_ans,max_xor(nums[i]));  // get the max side by side
        }
        return max_ans;
    }
};
