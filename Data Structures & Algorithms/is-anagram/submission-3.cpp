class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> s1;
        unordered_map<char, int> t1;

        for (auto c : s){
            s1[c]++;
        }

        for (auto c : t){
            t1[c]++;
        }

        return s1 == t1; 
    }
};
