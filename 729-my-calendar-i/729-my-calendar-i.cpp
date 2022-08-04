class MyCalendar {
public:
  vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
      for(auto t: v)
      {
        if(max(t.first,start) < min(t.second,end)) return false;
      }
      v.push_back({start,end});
      return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */