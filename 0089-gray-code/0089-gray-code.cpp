class Solution {
private:
    int binaryToGray(int num, int bits){
        int result = 0;

        // MSB remains same
        result |= (num & (1 << (bits - 1)));

        // Remaining bits
        for(int i = bits - 2; i >= 0; i--){
            bool current = num & (1 << i);
            bool next = num & (1 << (i + 1));

            if(current ^ next)
                result |= (1 << i);
        }
        return result;
    }

public:
    vector<int> grayCode(int bits) {
        vector<int> res;
        for(int i = 0; i < (1 << bits); i++){
            res.push_back(binaryToGray(i, bits));
        }
        return res;
    }
};