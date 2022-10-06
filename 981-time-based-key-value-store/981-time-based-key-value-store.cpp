class TimeMap {
    private:
    unordered_map<string,unordered_map<int,string>>keyTimemap;
public:
    
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyTimemap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!keyTimemap.count(key)){
            return "";
        }
        for(int i=timestamp;i>=1;--i){
            if(keyTimemap[key].count(i)){
                return keyTimemap[key][i];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */