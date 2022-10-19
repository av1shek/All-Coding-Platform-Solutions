class Solution {
public:
   vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> wordCount;
    for (const string& word : words) {
      wordCount[word]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> minHeap;
    for (const auto& [ word, count ] : wordCount) {
      minHeap.emplace(count, word);
      if (minHeap.size() > k)
        minHeap.pop();
    }

    vector<string>res;
    while (minHeap.size()) {
      res.emplace_back(minHeap.top().second);
      minHeap.pop();
    }

    reverse(res.begin(), res.end());
    return res;
  }

private:
  struct Comp {
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) {
      return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
    }
  };
};