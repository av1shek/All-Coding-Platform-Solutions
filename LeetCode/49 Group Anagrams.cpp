

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    bool wordEnd;
    vector<int> indices;
	TrieNode *child[ALPHABET_SIZE];

	TrieNode()
	{
	    wordEnd = false;
	    for(int i=0;i<ALPHABET_SIZE;i++)
            child[i] = NULL;
	}
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    void insert(string s, int index)
    {
        TrieNode *curr = root;
        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                curr->child[indx] = new TrieNode();
            curr = curr->child[indx];
        }
        curr->wordEnd = true;
        curr->indices.push_back(index);
    }

    bool search(string s)
    {
        TrieNode *curr = root;
        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                return false;
            curr = curr->child[indx];
        }
        return (curr) && (curr->wordEnd);
    }


};

void solve(TrieNode *root, vector<vector<string> > &ans, vector<string> &arr)
{
    if(root==NULL) return;
    if(root->wordEnd)
    {
        vector<string> temp;
        for(auto it: root->indices)
            temp.push_back(arr[it]);
        ans.push_back(temp);
    }

    for(int i=0;i<ALPHABET_SIZE;i++)
        solve(root->child[i], ans, arr);
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        Trie T;
    for(int i=0;i<arr.size();i++)
    {
        string temp = arr[i];
        sort(temp.begin(), temp.end());
        T.insert(temp, i);
    }
    vector<vector<string> > ans;

    solve(T.root, ans, arr);
    return ans;
    }
};
