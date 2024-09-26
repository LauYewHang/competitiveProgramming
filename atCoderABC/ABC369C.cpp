#include <iostream>
#include <vector>

using namespace std;

int cal(vector<int> v){
    int pairs = v.size() * v.size();
    pairs -= (v.size() % 2 == 0 ? (v.size()-1 + 1)*((v.size()-1)/2) + v.size()/2 : (v.size()-1 + 1)*((v.size()-1)/2) );
    return pairs;
}

int main(){
    int N, a, pairs = 0, constant = 0;
    vector <int> A = {};
    vector <vector<int>> aS = {};
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a;
        A.emplace_back(a);
    }
    
    int i = 0;
    for (i; i < N - 1; i++){
        aS.emplace_back();
        constant = A[i] - A[i+1];
        while ((i+1 < N-1) && (A[i] - A[i+1] == constant)){
            aS[aS.size()-1].emplace_back(A[i]);
            i++;
        }
        if (A[i-1] - A[i] == constant)
            aS[aS.size()-1].emplace_back(A[i--]);
    }
    
    for (vector<int> v : aS){
        pairs += cal(v);
    }
    pairs -= aS.size()-1;
    cout << pairs;
}