# If we want to make MINIMUM changes to turn the input string into a strong password, each change made should fix as many problems as possible.
# Dividing the problem into three sub-problems

# The password has less than 6 characters.
# The length of password is between 6 and 20 characters, both included.
# And the string length is greater than 20 characters.
# Now a strong password should have at least one lowercase letter, at least one uppercase letter, and at least one digit. The methoid 'GetRequiredChar' checks for the three conditions.

# The first two cases are easy. When the string length is greater than 20 characters, we can optimize the edits of triplets by considering three cases:

# When the sequences of the same character are evenly divisible by 3
# When they have one extra character
# and when they are one character off from being evenly divisible by 3
# length%3 == 0 should have higher priority
# length%3 == 1 second
# length%3 == 2 lowest

# For any repeating sequences with length % 3 == 0, we can reduce one replacement by deleting one character. For any repeating sequences with length % 3 == 1, we can reduce one replacement by deleting two character. For the remaining sequences, we can reduce every replacement by deleting three character.

# SOLUTION: (in python)

class Solution(object):
    def strongPasswordChecker(self, s):
        missing_type = 3
        if any('a' <= c <= 'z' for c in s): missing_type -= 1
        if any('A' <= c <= 'Z' for c in s): missing_type -= 1
        if any(c.isdigit() for c in s): missing_type -= 1

        change = 0
        one = two = 0
        p = 2
        while p < len(s):
            if s[p] == s[p-1] == s[p-2]:
                length = 2
                while p < len(s) and s[p] == s[p-1]:
                    length += 1
                    p += 1
                    
                change += length / 3
                if length % 3 == 0: one += 1
                elif length % 3 == 1: two += 1
            else:
                p += 1
        
        if len(s) < 6:
            return max(missing_type, 6 - len(s))
        elif len(s) <= 20:
            return max(missing_type, change)
        else:
            delete = len(s) - 20
            
            change -= min(delete, one)
            change -= min(max(delete - one, 0), two * 2) / 2
            change -= max(delete - one - 2 * two, 0) / 3
                
            return delete + max(missing_type, change)
        