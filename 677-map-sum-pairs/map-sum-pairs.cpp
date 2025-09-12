class MapSum {
public:
    MapSum() {
        
    }
    unordered_map<string,int>m;
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        int n = prefix.size();
        for(auto i:m){
            if(i.first.substr(0,n) == prefix) sum += i.second;
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */