class Solution {
public:
    vector<string> split(const string& path) {
        vector<string> res;
        auto pos = path.find(' ');
        int start = 0;
        while (pos != -1) {
            res.push_back(path.substr(start, pos - start));
            start = pos + 1;
            pos = path.find(' ', start);
        }
        res.push_back(path.substr(start));
        return res;
    }
    
    string fileContent(const string& all) {
        auto lp = all.find('(');
        auto rp = all.find(')');
        
        if (lp + 1 == rp) return "";
        
        return all.substr(lp + 1, rp - lp - 1);
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map;
        for (auto p : paths) {
            auto values = split(p);
            for (int i = 1; i < values.size(); ++i) {
                auto cont = fileContent(values[i]);
                auto& vec = map[cont];
                auto temp = values[0] + "/" + values[i].substr(0, values[i].find('('));
                vec.push_back(temp);
            }
        }
        
        vector<vector<string>> res;
        for (auto& [c, v] : map) {
            if (v.size() > 1)
                res.push_back(v);
        }
        
        return res;
    }
};