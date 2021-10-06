class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<pair<int, int>> a;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                a.push_back(make_pair(arr[i], arr[j]));
            }
        }
        sort(a.begin(), a.end(), [=](pair<int, int> a, pair<int, int> b)
             { return (double)(((double)a.first / (a.second))) < (double)(((double)b.first / (b.second))); });
        return {a[k - 1].first, a[k - 1].second};
    };
};