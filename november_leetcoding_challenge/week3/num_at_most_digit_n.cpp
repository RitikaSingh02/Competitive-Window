class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      string N = to_string(n);
      int sz = N.size();
      int ret = 0;
      for (int i = 1; i < sz; i++) {
         ret += pow(digits.size(), i);
      }
      for (int i = 0; i < sz; i++) {
         bool hasSameNum = false;
         for (string &x : digits) {
            if (x[0] < N[i]) {
               ret += pow(digits.size(), sz - i - 1);
            } else if (x[0] == N[i]) {
               hasSameNum = true;
            }
         }
         if (!hasSameNum)
         return ret;
      }
      return ret + 1;
   }
    
};