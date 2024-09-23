#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateGrayCode(int n) {
    if (n == 0) {
        return {""};  
    }
    
    vector<string> prevGrayCode = generateGrayCode(n - 1);
    vector<string> result;

    for (const string &code : prevGrayCode) {
        result.push_back("0" + code);
    }

    for (int i = prevGrayCode.size() - 1; i >= 0; --i) {
        result.push_back("1" + prevGrayCode[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> grayCodeSequence = generateGrayCode(n);

    for (const string &code : grayCodeSequence) {
        cout << code << endl;
    }

    return 0;
}
