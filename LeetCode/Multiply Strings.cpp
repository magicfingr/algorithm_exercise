class Solution {
public:
    string multiply(string num1, string num2) {
        int len = num1.size() + num2.size();
        int *re = new int[len];
        memset(re, 0, sizeof(int) * len);
        // add to intermediate result
        for (int i = num1.size() - 1; i >= 0; i--){
            for (int j = num2.size() - 1; j >= 0; j--){
                int index = i + j + 1;
                re[index] += mul(num1[i], num2[j]);
            }
        }
        // calulate carry
        for (int i = len - 1; i > 0; i--){
            re[i - 1] += re[i] / 10;
            re[i] %= 10;
        }
        // output
        int firstValid = 0;
        while (firstValid < len && re[firstValid] == 0)
            firstValid++;
        string output = "";
        for (int i = firstValid; i < len; i++)
            output += (re[i] + '0');
        if (output == "")
            output = "0";
        return output;
    }
private:
    int mul(char a, char b){
        return (a - '0') * (b - '0');
    }
};