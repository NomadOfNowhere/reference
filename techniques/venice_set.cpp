struct VeniceSet {
    multiset<int> st;
    int global = 0;
    
    void add(int x) {
        st.insert(x + global);
    }
    void remove(int x) {
        st.erase(st.find(x + global));
    }
    void updateAll(int x) {
        global += x;
    }
    int min(int x) {
        return *st.begin() - global;
    }
};