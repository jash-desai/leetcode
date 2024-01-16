class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        if(st.count(val)) return false;
        st.insert(val); return true;
    }
    
    bool remove(int val) {
        if(!st.count(val)) return false;
        st.erase(val); return true;
    }
    
    int getRandom() {
        int rnd = rand() % (st.size());
        int val = *next(st.begin(), rnd);
        return val;
    }
};