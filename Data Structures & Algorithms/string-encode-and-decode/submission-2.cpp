class Solution {
public:

    string encode(vector<string>& strs) {
        if (!strs.size()){
            return "";
        }
        //use str length n _ as delims as unique ids for each str that's decodeable
        string onePiece = "";
        for (auto s : strs){
            onePiece += to_string(s.size()) + "_" + s;
        }
        return onePiece;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        if (!s.size()){
            return strs;
        }
        //use ptrs/window to read in delims & use to capture str
        //as a substr (since it's all 1 str)

        int i = 0;
        while (i < s.size()){
            int j = i;
            //open window up to delim seperator
            while (s[j] != '_'){ 
                j++;
            }
            //len is digits up to _, starts at i & ends at j. convert to int 
            int len = stoi(s.substr(i, j - i));
            i = j+1; //set 1st ptr = to first letter
            j = i + len;//set j = 
            //str starts at i & goes for read-in length
            strs.push_back(s.substr(i, len));
            i = j;//set i = first digit of delim again
        }

        return strs;
    }
};
