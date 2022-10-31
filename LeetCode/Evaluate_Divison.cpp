class Solution {
    
    // DSU factors declaration
    map<string,string> par;
    map<string,long long> size;
    map<string,double> mp;
    
    // Adding new node to our DSU graph
    void addNode(string s){
        if(par.find(s) == par.end()){ par[s] = s; size[s] = 1;}
    }
    
    // To find parent node for a given node
    string getPar( string x ){
        if( par[x] == x ) return x;
        // Path Compression
        return par[x] = getPar(par[x]);
    }
    
    // To merge two nodes resulting their parents to be same i.e. now both belongs to the same component
    void join( string a, string b ){
        string pa = getPar(a);
        string pb = getPar(b);
        if(pa == pb) return;
        // Size optimisation
        if(size[pa] < size[pb]) swap(pa,pb);
        par[pb] = pa;
        size[pa]+=size[pb];
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // Making connected components first by adding them in DSU
        for(auto eq:equations){
            string ai = eq[0], bi = eq[1];
            addNode(ai);
            addNode(bi);
            join(ai,bi);
        }
        
        /* 
            Now, we assume value of parent to be 1 always
            let say a/b = 3    and   b/c = 2
            and mapping is like par[a] = a , par[b] = a, par[c] = a
            then we can easily take other values of a component
            
            like here we put a = 1;
            the b = 1/3
            after it c = 1/6
            ..... and so on
        */
        for(auto p:par){
            if(p.first == p.second) mp[p.first] = 1;
        }
        
        // ADDING INDIVIDUAL VALUES TO OUR MAP
        while( mp.size() < par.size() ){
            
             for(int i = 0;i<equations.size();i++){
                 string ai = equations[i][0], bi = equations[i][1];
                 double v = values[i];
                 
                if( mp.find(ai) == mp.end() && mp.find(bi) == mp.end() ){
                    // will handle it in next iteration
                } else if( mp.find(ai) == mp.end() ){
                    mp[ai] = mp[bi]*v;
                } else if(mp.find(bi) == mp.end()){
                    mp[bi] = mp[ai]/v;
                }
            }
            
        }
        
        // FINDING ANSWER
         vector<double> ans;
        
        for(auto q:queries){
            string ci = q[0], di = q[1];
            
            // If its a new variable overall or if parents of variables are different then push -1
            if( par.find(ci) == par.end() || par.find(di) == par.end() || getPar(ci) != getPar(di)){
                ans.push_back(-1);
            } else {
                // So, for now we actually stored var / par  as value in our map
                // ans as we kept par = 1
                // we can directly divide their map values and find the answer
                ans.push_back(mp[ci]/mp[di]);
            }
        }
        
        return ans;
        
    } 
};
