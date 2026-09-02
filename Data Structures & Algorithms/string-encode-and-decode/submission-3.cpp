class Solution {
public:

    string encode(vector<string>& strs) {
        if (!strs.size()){
            return "";
            
        }
        string onePiece;
        for (auto s : strs){
            onePiece += to_string(s.size()) + "_" + s;
        }

      

        return onePiece;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        if (s.size() == 0){
            return strs;
        }
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '_'){
                j++;
            }
            //have now captured str size in window, read it in n convert to actual int 
            int len = stoi(s.substr(i, j - i));
            i = j + 1;//set i to first letter of str
            j = i + len; //j ptr moves to start of new entry which is 1st dig of size
            strs.push_back(s.substr(i, len));
            i = j;

        }

        return strs;
    }
};
