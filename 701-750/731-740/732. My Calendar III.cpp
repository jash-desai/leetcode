class MyCalendarThree{
    map<int, int> mpp;
public:
    MyCalendarThree() {}

    int book(int start, int end){
        mpp[start]++;
        mpp[end]--;

        int res = 0, curr = 0;

        for (auto it : mpp){
            curr += it.second;
            res = max(res, curr);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */