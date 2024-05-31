// 31-05-2024

class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        
        string bin = bitset<8> (n).to_string();
        
        for(int i=0;i<4;i++)
        {
            swap(bin[i] , bin[i+4]);
        }
        
        // return stoi(bin);
        
        int k = 0;
        int num = 0;
        
        for(int i=7;i>=0;i--)
        {
            if(bin[i] == '1')
                num += pow(2, k++);
            
            else
                k++;
        }
        
        return num;
    }
};
