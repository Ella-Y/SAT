#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans(2);
    if(v[0][0] == v[1][0]) ans[0] = v[2][0];
    else if(v[0][0] == v[2][0]) ans[0] = v[1][0];
    else ans[0] = v[0][0];
    
    if(v[0][1] == v[1][1]) ans[1] = v[2][1];
    else if(v[0][1] == v[2][1]) ans[1] = v[1][1];
    else ans[1] = v[0][1];
    
    return ans;
}