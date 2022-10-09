class TimeMap {
public:
    unordered_map< string ,map<int, string> > m;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key][ timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        
        if( m.find( key)==m.end()) return ""; 
        auto t=m[ key].upper_bound(timestamp);  
		if( t==m[key].begin()) return "";  
        
        t--;
        return t->second;
    }
};