class Solution {
public:
    int countDigitOne(int n) {
        long long cnt = 0, i = 1, j = 1;
        while (n > 0) {
            cnt += (n + 8) / 10 * i + (n % 10 == 1) * j;
            j += n % 10 * i;
            i *= 10;
            n /= 10;
    }
    return cnt;
    }
};