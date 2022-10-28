// You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

// Choose 2 distinct names from ideas, call them ideaA and ideaB.
// Swap the first letters of ideaA and ideaB with each other.
// If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
// Otherwise, it is not a valid name.
// Return the number of distinct valid names for the company.



// answer:



class Solution {
 public:
  long long distinctNames(vector<string>& ideas) {
    long long ans = 0;
    // Group strings by initials
    vector<unordered_set<string>> suffixes(26);

    for (const string& idea : ideas)
      suffixes[idea[0] - 'a'].insert(idea.substr(1));

    for (int i = 0; i < 25; ++i)
      for (int j = i + 1; j < 26; ++j) {
        int count = 0;
        for (const string& suffix : suffixes[i])
          if (suffixes[j].count(suffix))
            ++count;
        ans += 2 * (suffixes[i].size() - count) * (suffixes[j].size() - count);
      }

    return ans;
  }
};
