class MyCalendarThree {
private:
    int mxCnt = 0;
    map<int,int>mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int overlap = 0;
        for(auto it : mp){
            overlap += it.second;
            mxCnt = max(mxCnt,overlap);
        }
        return mxCnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */