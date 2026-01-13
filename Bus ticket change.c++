class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five=0 , ten = 0;
        
        for(auto &coin : arr) {
            if(coin == 5) {
                five++;
            } else if(coin == 10) {
                if(five == 0)   return false;
                five--, ten++;
            } else {
                if(five > 0 && ten > 0) {
                    five--, ten--;
                } else if(five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
