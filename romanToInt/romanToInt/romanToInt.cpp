#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        for (auto iter = s.begin(); iter < s.end(); iter++) {
            switch (*iter)
            {
            case 'I':
                this->answer++;
            case 'V':
                this->answer += 5;
            case 'X':
                this->answer += 10;
            case 'L':
                this->answer += 50;
            case 'C':
                this->answer += 100;
            case 'D':
                this->answer += 500;
            case 'M':
                this->answer += 1000;

            default:
                break;
            }
        }
        return this->answer;
    }
private:
    int answer = 0;
};

int main()
{
    Solution a;
    int b = a.romanToInt("III");
    cout << b;
}

