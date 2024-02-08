//User function template for C++

class Solution {
public:
    int atoi(string s) {
        int n = s.length();
        if (n == 0) return -1;

        int i = 0;
        int sign = 1;
        int result = 0;

        // Handling whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handling sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Constructing the number
        while (i < n && isdigit(s[i])) {
            // Handling overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + (s[i++] - '0');
        }

        // Checking for non-numeric characters
        while (i < n && !isdigit(s[i])) {
            return -1;
        }

        return result * sign;
    }
};

//
