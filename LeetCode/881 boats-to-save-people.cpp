#include <vector>

using namespace std;

class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {
        // Sort people from lightest to heaviest.
        sort(people.begin(), people.end());

        int boats = 0;
        int i = 0, j = people.size() - 1;

        // Skip past individuals who are heavier than the weight limit as efficiently as possible.
        while(i < j && people[j] >= limit) {
            ++boats;
            --j;
        }

        // Pair light and heavy individuals.
        while(i <= j) {
            ++boats;

            // If the next lightest and heaviest individuals have a combined weight that is at or below
            // the limit, then the light person can be boarded on the same boat as the heavy individual.
            // Advance to the next lightest invididual for the next iteration in this case.
            if(people[i] + people[j] <= limit) {
                ++i;
            }

            // The next heaviest person will always be placed on a boat, either by themselves or with
            // the light person determined above. Thus, always advance to the next heaviest individual
            // for the next iteration.
            --j;
        }

        return boats;
    }

};
