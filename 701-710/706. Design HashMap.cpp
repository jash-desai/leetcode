class MyHashMap {
private:
    vector<array<int, 2>> mp;
public:
    MyHashMap() {
        
    }
    
    void put(int i, int k) {
        for (auto &[key, val] : mp) {
            if (key == i) {
                val = k; return;
            }
        }
        mp.push_back({i, k}); 
    }
    
    int get(int i) {
        for(const auto&[key, val] : mp) if(key == i) return val;
        return -1; 
    }
    
    void remove(int key) {
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i][0] == key) {
                mp.erase(i + mp.begin()); 
                return;
            }
        }
    }
};