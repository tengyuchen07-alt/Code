#include <iostream>
#include<cstring>
#include<string>
using namespace std;
class Input {
public:
    string number_int;
    string number_double;
    int original_base;
    int target_base;
    int int_base10;
	double double_10;
    Input(string n_int, string n_double, int o, int t) {
        number_int = n_int;
        number_double = n_double;
        original_base = o;
        target_base = t;
        
    }
    void test();
    void intToBase10();
	void DoubleToBase10();
};
void Input::test() {
    cout << number_int <<' '<< number_double << ' ' << original_base << ' ' << target_base << endl;
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
void Input::Base10ToStr(){//整數部分轉目標進位
	string s;
	if (int_base10 == 0) return "0";
    string s = "";
    while (int_base10 > 0) {
        int remainder = int_base10 % target_base;
        if (remainder > 9) 
            s = char('A' + (remainder - 10)) + s;
        else 
            s = char('0' + remainder) + s;        
        int_base10 /= target_base;              
    }
}
void Input::DoubleToBase10(){
	double_10=0;
	
}
Input get_input() {//分割輸入
    char s[1000];
    cin.getline(s, 1000);
    char const* d = "()-> .";
    char* p;
    char* context = nullptr;
    p = strtok_s(s, d,&context);
    string number_int = p;
    p = strtok_s(NULL, d, &context);
    string number_double = p;
    p = strtok_s(NULL, d, &context);
    int original_base = stoi(p);
    p = strtok_s(NULL, d, &context);
    int target_base = stoi(p);
    return Input(number_int, number_double, original_base, target_base);
}
int main()
{
    try {
        Input n = get_input();
        n.intToBase10();
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}