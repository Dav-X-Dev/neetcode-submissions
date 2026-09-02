class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        int prod = 1;
        vector<int> output;
        //iter thru nums collect cumulative product. and 0s
        for (const auto& n : nums){
            if (n == 0){
                zero_count++;
            
            }
            else{
                prod *= n;
            }  
        }

         int except;

        //case where each idx=0 since 0 will be the product for every num
        if (zero_count > 1){
            for (auto & n : nums){
                n = 0;
                output.push_back(n);
            }
        }
        else if(zero_count == 1){
            for (const auto & n :nums ){
                if (n == 0){
                    output.push_back(prod);
                }
                else{
                    except = 0;
                    output.push_back(except);
                }

            }
        }
        else if (!zero_count){
            for (const auto& n : nums) {
                except = prod / n;
                output.push_back(except);
            } 
        }

        return output;
    }
};
