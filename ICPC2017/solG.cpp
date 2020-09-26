#include <iostream>
#include <stack>
#include <string>

using namespace std;

string input;
int S, L, B, W;
stack<char> paran;
char lst[] = {'S', 'L', 'B', '(', '[', ')', ']', ','};

bool alph = true;
bool o_Paran = false;
bool c_Paran = false;
bool comma = false;

void next(bool a, bool b, bool c, bool d){
    alph = a;
    o_Paran = b;
    c_Paran = c;
    comma =  d;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    S = 0;
    L = 0;
    B = 0;
    cin >> W;
    cin.ignore(256,'\n');
    getline(cin, input);
	int cnt = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			cnt++;
		}
	}
	if (cnt == input.length()) {
		cout << 2 << '\n';
		return 0;
	}
    next(1, 0, 0, 0);


    for(int i = 0; i<input.length(); i++){
        char cur = input[i];
        if (cur == ' ') continue;
        bool error = true;
        for (int j = 0; j<8; j++){
            if (cur == lst[j]){
                error = false;
                break;
            }
        }
        if (error){
            cout << -1 << "\n";
            return 0;
        }

        if (cur == ','){
            if (comma){
                next(1, 0, 0, 0);
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == 'S'){
            if (alph){
                next(0, 0, 1, 1);
                S++;
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == 'L'){
            if (alph){
                next(0, 1, 0, 0);
                L++;
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == 'B'){
            if (alph){
                next(0, 1, 0, 0);
                B++;
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == '('){
            if (o_Paran){
                paran.push('(');
                next(1, 0, 0, 0);
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == '['){
            if (o_Paran){
                paran.push('[');
                next(1, 0, 0, 0);
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }
        else if (cur == ')'){
            if (paran.empty()){
                cout << -1 << "\n";
                return 0;
            }
            char p = paran.top();
            paran.pop();
            if (p != '('){
                cout << -1 << "\n";
                return 0;
            }
            else {
                if (c_Paran){
                    next(0, 0, 1, 1);
                }
                else {
                    cout << -1 << "\n";
                    return 0;
                }
                
            }
        }
        else if (cur == ']'){
            if (paran.empty()){
                cout << -1 << "\n";
                return 0;
            }
            char p = paran.top();
            paran.pop();
            if (p != '['){
                cout << -1 << "\n";
                return 0;
            }
            else {
                if (c_Paran){
                    next(0, 0, 1, 1);
                }
                else {
                    cout << -1 << "\n";
                    return 0;
                }
                
            }
        }
    }
    if (!paran.empty()){
        cout << -1 << "\n";
        return 0;
    }
    int V = S+2*L+2*B;
    int eF = V-1+B;
    int eB = L;
    int res = eF + W*eB - V + 2;
    cout << res;
}