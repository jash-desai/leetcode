class SnapshotArray {
private:
  unordered_map<int, map<int, int>> a;
  int cur_snap = 0;
public: 
  SnapshotArray(int n) {}
  int snap() { return cur_snap++; }
  void set(int i, int k) { 
    a[i][cur_snap] = k; 
  }
  int get(int i, int id) {
    auto it = a[i].upper_bound(id);
    return it == begin(a[i]) ? 0 : prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */