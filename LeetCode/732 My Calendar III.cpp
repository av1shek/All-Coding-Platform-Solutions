class MyCalendarThree {
public:
    multiset<int> s,e;
    set<int> t;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        s.insert(start);
        e.insert(end);
        t.insert(start);
        t.insert(end);
        int c=0,m=0;
        for(auto i:t)
        {
            if(s.count(i))
                c+=s.count(i);
            // m=max(m,c);
            if(e.count(i))
                c-=e.count(i);
            m=max(m,c);
        }
        return m;
    }
};