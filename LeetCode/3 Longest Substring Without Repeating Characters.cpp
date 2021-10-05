class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mpp;
        int maxx = 0, start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mpp.find(s[i]) != mpp.end())
            {
                start = max(mpp[s[i]] + 1, start);
            }
            mpp[s[i]] = i;
            int len = i - start + 1;
            if (len > maxx)
                maxx = len;
        }
        return maxx;
    }
};