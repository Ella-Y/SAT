#include<vector>
using namespace std;

char flag[100001] = {0, };
bool solution(vector<int> arr)
{
    for(int i = 0 ; i < arr.size() ; i++){
        if(flag[arr[i]] == 1){
            return false;
        }
        flag[arr[i]] = 1;
    }
    for(int i = 1 ; i <= arr.size() ; i++){
        if(flag[i] == 0) return false;
    }
	return true;
}