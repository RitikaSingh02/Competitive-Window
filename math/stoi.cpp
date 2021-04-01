class Solution {
public:
    int myAtoi(string s) {
        // '0' == 48
        // '9' == 57
        long result = 0;
        
        bool negative = false;
        char *ch = s.data();
        while (*ch != 0) {
            if (*ch == ' ') {
                ch++;
                continue;
            } else if (*ch == '+') {
                ch++;
                break;
            } else if (*ch == '-') {
                negative = true;
                ch++;
                break;
            } else if (*ch < 48 || *ch > 57) {
                return 0;
            } else if (*ch >= 48 && *ch <= 57) {
                result = *ch - 48;
                ch++;
                break;
            } else {
                ch++;
            }
        }
                
        while (*ch != 0) {
            if (*ch >= 48 && *ch <= 57) {
                if (result >= LONG_MAX / 10L) {
                    result = INT_MAX + 1L;
                    break;
                }
                result = result * 10 + (*ch++ - 48);
            } else {
                break;
            }
        }
        
        if (negative) {
            if (-result < INT_MIN) {
                return INT_MIN;
            }
            
            return (int) -result;
        }
        
        if (result > INT_MAX) {
            return INT_MAX;
        }
        
        return (int) result;
    }
};
