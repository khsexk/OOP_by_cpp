#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "덧셈 문자열을 입력하세요 >>" << endl;

    getline(cin, s, '\n');
    int sum = 0;
    int startIdx = 0;

    while(true){
        int findIdx = s.find('+', startIdx);

        if(findIdx == -1){
            string part = s.substr(startIdx);

            if(part == "")
                break;
            cout << part << endl;

            sum += stoi(part);
            break;
        }
        int cnt = findIdx - startIdx;
        string part = s.substr(startIdx, cnt);
        cout << part << endl;

        sum += stoi(part);
        startIdx = findIdx + 1;
    }
    cout << "Sum: " << sum;
}