class SmallestInfiniteSet {
public:
    int val;
    set<int> setint;
    SmallestInfiniteSet() {
        val=1;
    }
    
    int popSmallest() {
        if(setint.size()){
            int res = *setint.begin();
            setint.erase(res);
            return res;
        }else{
            val++;
            return val-1;
        }
    }
    
    void addBack(int num) {
        if(val>num) setint.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */