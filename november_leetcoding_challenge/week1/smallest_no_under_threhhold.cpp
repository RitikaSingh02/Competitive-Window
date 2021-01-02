class Solution {
public:
   bool check_sum(int x, vector <int> &nums, int th){
      int sum = 0;
      for(int i = 0; i < nums.size(); i++){
         sum += ceil((double)nums[i]/(double)x);// as ceil accepts double else will result to absurd value
      }
      return sum<=th;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
      
      int low = 1;
      int high = INT_MAX;
      while(low < high){
         int mid = low + (high - low)/2;
         if(check_sum(mid, nums, threshold)){
            high = mid;
         }
          else 
             low = mid + 1;
      }
      return high;
    }
};