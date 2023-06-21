class DSU{
public:
    int *rank,*parent;
    DSU()
    {
        rank = new int[26];
        parent = new int[26];
        makeSet();
    }
    
    void makeSet()
    {
        for(int i=0;i<26;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
    
    void unionn(int x,int y)
    {
        int u = findParent(x);
        int v = findParent(y);
        if(u == v)
        {
            return;
        }
        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if(rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[u] = rank[v] + 1;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU obj;
        for(auto it : equations)
        {
		// first unify all the elements which are equal
            if(it[1] == '=')
            {
                int x = it[0] - 'a';
                int y = it[3] - 'a';
                obj.unionn(x,y);
            }
        }
        for(auto it : equations)
        {
		// Find parents, if they are equal means we can't give them different numbers, so return false.
            if(it[1] == '!')
            {
                int x = obj.findParent(it[0] - 'a');
                int y = obj.findParent(it[3] - 'a');
                if(x == y)
                {
                    return false;
                }
            }
        }
        return true;
    }
};