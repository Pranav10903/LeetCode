class MedianFinder {
    public:
    
    priority_queue<int>smaller;
    
    priority_queue<int, vector<int>,greater<int>>larger;
    
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        if(!smaller.empty() && !larger.empty() && smaller.top()>larger.top()){
            int val=smaller.top();
            smaller.pop();
            larger.push(val);
        }
        
        if(smaller.size()>larger.size()+1){
            larger.push(smaller.top());
            smaller.pop();
        }else if(larger.size()>smaller.size()+1){
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if(smaller.size()==larger.size()){
            return (double(smaller.top())+double(larger.top()))/2;
        }
        else if(smaller.size()==larger.size()+1){
            return double(smaller.top());
        }else{
            return double(larger.top());
        }
    }
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */