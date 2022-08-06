#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        switch (*s.begin())
        {
        case 'I': {
            this->answer++;
            break;
        }
        case 'V': {
            this->answer += 5;
            break;
        }
        case 'X': {
            this->answer += 10;
            break;
        }
        case 'L': {
            this->answer += 50;
            break;
        }
        case 'C': {
            this->answer += 100;
            break;
        }
        case 'D': {
            this->answer += 500;
            break;
        }
        case 'M': {
            this->answer += 1000;
            break;
        }
        default:
            break;
        }
        for (auto iter = s.begin() + 1; iter < s.end(); iter++) {
            current = *iter;
            previous = *(iter - 1);
            switch (current)
            {
            case 'I': {
                this->answer++;
                break;
            }
            case 'V': {
                if (previous == 'I')
                {
                    this->answer += 3;
                }
                else
                {
                    this->answer += 5;
                }
                break;
            }
            case 'X': {
                if (previous == 'I')
                {
                    this->answer += 8;
                }
                else
                {
                    this->answer += 10;
                }
                break;
            }
            case 'L': {
                if (previous == 'X')
                {
                    this->answer += 30;
                }
                else
                {
                    this->answer += 50;
                }
                break;
            }
            case 'C': {
                if (previous == 'X')
                {
                    this->answer += 80;
                }
                else
                {
                    this->answer += 100;
                }
                break;
            }
            case 'D': {
                if (previous == 'C')
                {
                    this->answer += 300;
                }
                else
                {
                    this->answer += 500;
                }
                break;
            }
            case 'M': {
                if (previous == 'C')
                {
                    this->answer += 800;
                }
                else
                {
                    this->answer += 1000;
                }
                break;
            }
            default:
                break;
            }
        }
        return this->answer;
    }
private:
    int answer = 0;
    char current;
    char previous;
};

int main()
{
    string s;
    Solution a;
    cin >> s;
    int b = a.romanToInt(s);
    cout << b << endl;
}

