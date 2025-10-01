//1121631鄧宇辰
#include <iostream>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;
class Input {
public:
	bool repeating;
    bool positive;
    string number_int;
    string number_double;
    string result_int;
	string result_double;
    int original_base;
    int target_base;
    int int_base10;
    double double_base10;
    Input(string n_int, string n_double, int o, int t,bool p) {
        number_int = n_int;
        number_double = n_double;
        original_base = o;
        target_base = t;
        positive = p;
    }
    void test();
    void intToBase10();
    void DoubleToBase10();
    void Base10ToTarget_int();
    void Base10ToTarget_double();
};
void Input::test() {
    cout << (positive?result_int:'-'+result_int) <<'.'<<result_double << endl;
}
void Input::intToBase10() {//整數部分轉10進位
    int_base10 = 0;
    int digit;
    for (auto c : number_int) {
        if (c <= '9')digit = c - '0';
        else digit = c - 'A' + 10;
        int_base10 = int_base10 * original_base + digit;
    }
}
void Input::DoubleToBase10() {//小數部分轉10進位
    double_base10 = 0;
    double digit;
    for (int i = 1; i <= number_double.length(); i++) {
        if (number_double[i - 1] <= '9')digit = number_double[i - 1] - '0';
        else digit = number_double[i - 1] - 'A' + 10;
        double_base10 += digit * pow(original_base, -i);
    }
}
void Input::Base10ToTarget_int() {//10進位轉目標進位
    result_int = "";
    while (int_base10 > 0) {
        int digit = int_base10 % target_base;
        if (digit > 9)result_int.insert(result_int.begin(), 'A' - (digit - 10));
        else result_int.insert(result_int.begin(), '0' + digit);
        int_base10 /= target_base;
    }
}
void Input::Base10ToTarget_double() {//10進位轉目標進位
	unordered_map<string, int> seen;
	result_double = "";
	
    int i = 0;
    while (double_base10 > 0 && result_double.length() <= 40) {
        double_base10 *= target_base;
        int digit = (int)double_base10;
        double_base10 -= digit;
        string s = to_string(double_base10);
        if (seen.count(s)) {
            repeating = true;
            break;
        }
        else seen[s] = i++;
        if (digit > 9)result_double.push_back('A' - (digit - 10));
        else result_double.push_back('0' + digit);
    }
    if (repeating) {
        result_double.insert(i , "[");
        result_double.push_back(']');
    }
}
Input get_input() {//分割輸入
    char s[1000];
    cin.getline(s, 1000);
    bool positive = true;
    if (s[0] == '-')positive = false;
    char const* d = "()-> .";
    char* p;
    char* context = nullptr;
    p = strtok_s(s, d, &context);
    string number_int = p;
    p = strtok_s(NULL, d, &context);
    string number_double = p;
    p = strtok_s(NULL, d, &context);
    int original_base = stoi(p);
    p = strtok_s(NULL, d, &context);
    int target_base = stoi(p);
    return Input(number_int, number_double, original_base, target_base,positive);
}
int main()
{
    try {
        Input n = get_input();
        n.intToBase10();
        n.DoubleToBase10();
        n.Base10ToTarget_int();
        n.Base10ToTarget_double();
        n.test();
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
