class MyHashSet {
public:
    MyHashSet() : v(1x000001, false){}
    
    void add(int key){
        v[key] = true;
    }
    
    void remove(int key){
        v[key] = false;
    }
    
    bool contains(int key){
        return v[key];
    }
private:
    vector<bool> v;
};