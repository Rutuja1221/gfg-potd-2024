class Solution:
    def atoi(self, string):
        if not string:
            return -1

        n = len(string)
        result = 0
        sign = 1

        # Skip leading whitespaces
        i = 0
        while i < n and string[i] == ' ':
            i += 1

        # Check for optional sign
        if i < n and (string[i] == '-' or string[i] == '+'):
            sign = -1 if string[i] == '-' else 1
            i += 1

        # Process digits
        while i < n and string[i].isdigit():
            digit = int(string[i])
            result = result * 10 + digit
            i += 1

        # Apply sign to the result
        result *= sign

        # Check for overflow
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        if result > INT_MAX:
            return INT_MAX
        elif result < INT_MIN:
            return INT_MIN

        # Check for remaining non-digit characters
        while i < n and not string[i].isdigit():
            return -1

        return result
        