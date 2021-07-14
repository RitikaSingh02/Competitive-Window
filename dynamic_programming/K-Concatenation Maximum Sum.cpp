#define mod 1000000007
class Solution {
public:
    int maxSum(vector<int> arr,int size){
        long long  totalMax=0, currMax=0 ,  asize=arr.size();
        
        for(int i=0;i<size;i++){
            currMax=(currMax+arr[i%asize]);
            if(currMax<arr[i%asize]){
                currMax=arr[i%asize];
            }
            if(currMax>totalMax){
                totalMax=currMax;
            }
        }
        return totalMax % mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long int size=arr.size();
        if(k==1){
            return maxSum(arr,size);
        }
        else{
            long long sum=0;
            for(int i=0;i<arr.size();i++){
                sum=(sum+arr[i]);
            }
            long long kSum=maxSum(arr,size*2);
            if(sum>0){
                kSum=(kSum+((k-2)*sum));
            }
            return kSum%mod;
        }
        return 0;
    }

};
