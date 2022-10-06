class TimeMap {
public:
    unordered_map<string,map<int,string>> keyTimeToValue;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeToValue[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(keyTimeToValue.find(key)!=keyTimeToValue.end())
        {
            auto it=keyTimeToValue[key].lower_bound(timestamp);
            if(it->first!=timestamp)
            {
                if(it==keyTimeToValue[key].begin())
                    return "";
                it=prev(it);
            }
            //cout<<it->second<<" ";
            return it->second;
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