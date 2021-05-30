class Solution {
public:
    int check( vector <int> weights , int days , int l )
    {
        // returns the no of days for a particular weight of the ship 
         int wt = 0 ;
        int d = 1;
            for(int i =0 ; i < weights.size() ; i++)
            {
                wt+= weights[i];
                if(wt>l)
                {
                    wt = weights[i] ;
                    d++;                    
                }
            }
        return d ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // we know that the ans is between the sum of the array and the min ele in the array
        int r = accumulate(weights.begin() , weights.end() , 0);
        
        int l = *max_element(weights.begin() , weights.end());
        int g  = r; // the result var       
        
        while(l < r)
        {
            int mid = (l+r)/2;
            if (check(weights , days , mid)> days)
            {
                // then we need to increase the left pointer
                l = mid+1;
               
            }
            else
            {
                if(check(weights , days , mid) == days)
                {
                    g = min(g , mid);
                    r = mid ; // we still need to check that is there any val lesser than this g on the left side of the array
                }
                else
                {
                    g = min(g , mid);
                    r = mid; 
                    
                }
            }
        }
        return g;
        
    }
};
