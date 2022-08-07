#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romeNum;
        romeNum['I'] = 1;
        romeNum['V'] = 5;
        romeNum['X'] = 10;
        romeNum['L'] = 50;
        romeNum['C'] = 100;
        romeNum['D'] = 500;
        romeNum['M'] = 1000;

        answer = romeNum[*s.begin()];

        for (auto iter = s.begin() + 1; iter != s.end(); iter++)
        {
            char previous = *(iter - 1);
            char current = *iter;
            if (romeNum[current] > romeNum[previous])
                answer += romeNum[current] - 2 * romeNum[previous];
            else
                answer += romeNum[current];
        }
        return answer;
    }
        
private:
    int answer;
};

int main()
{
    string s;
    Solution a;
    cin >> s;
    int b = a.romanToInt(s);
    cout << b << endl;
}

