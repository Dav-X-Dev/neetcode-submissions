class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack holds day,temp pairs for elts that are still looking for 
        //the 1st day of earlier temps. once found add to vec at specific idx

        stack<pair<int, int>> staxx; //day, temp
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++){
        
            while (!staxx.empty() && staxx.top().second < temperatures[i]){
                //calc how many days and add to proper idx in result vec
                //ALSO ADD CURR DAY TO STACK
                int days = i - staxx.top().first;
                result[staxx.top().first] = days;
                staxx.pop();
                //staxx.push({i, temperatures[i]});
            }
            //empty or curr temp 
            staxx.push({i, temperatures[i]});
            
            
        }

        return result;
    }
};
