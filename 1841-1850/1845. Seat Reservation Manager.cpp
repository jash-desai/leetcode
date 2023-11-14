class SeatManager {
private:
    set<int> st;
public:
    SeatManager(int n) {
        st.clear();
        for(int i=1; i<=n; i++) st.insert(i);
    }
    
    int reserve() {
        int k = *st.begin();
        st.erase(st.begin());
        return k;
    }
    
    void unreserve(int x) {
        st.insert(x);
    }
};
