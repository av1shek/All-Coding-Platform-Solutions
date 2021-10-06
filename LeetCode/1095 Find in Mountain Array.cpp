class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        long long low = 0, high = mountainArr.length() - 1;
        long long mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        long long l = 0, h = low;
        bool found = false;
        while (l < h)
        {
            mid = l + (h - l) / 2;
            if (mountainArr.get(mid) < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        if (mountainArr.get(l) == target)
        {
            return l;
        }
        l = low + 1;
        h = mountainArr.length() - 1;
        while (l < h)
        {
            mid = l + (h - l) / 2;
            if (mountainArr.get(mid) > target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        if (mountainArr.get(l) == target)
        {
            return l;
        }
        return -1;
    }
};