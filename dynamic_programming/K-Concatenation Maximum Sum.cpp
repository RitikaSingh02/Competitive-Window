class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        //kadane's algo
        int cons = 1e9 +7;
        int n = arr.size() , max_all = INT_MIN , i =0 ,local_max = 0 ;
        bool flag = false;
        for(auto i : arr)
        {
            if(i<0)
            {
                flag = true;
                break;
            }
        }
        while(i<n && flag)
        {
            local_max+=arr[i];
            if(local_max > max_all)
                max_all = local_max;
            if(local_max<0)
                local_max = 0;

            i++;
            
            if(i==n && k>0)
            {
                i=0;
                k-=1;
                // cout<<"y";
                // cout<<local_max<<" ";
            }
            if(k==0)
                break;
            
        }
        if(!flag)
        {
            long long int sum1= accumulate(arr.begin() , arr.end() , 0);
            long long int sum = ((sum1%cons)%cons)*(k);//modulus multiplication property
            max_all = (sum%cons); 
        }
        max_all = max(0, max_all);
        return max_all % cons;
    }
};
