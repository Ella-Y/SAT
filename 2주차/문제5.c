#include<vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int arr[100000][4] = { 0, };
    for(int i = 0 ; i < 4; i++) arr[0][i] = land[0][i];
	for(int i = 0 ; i < land.size() - 1 ; i++){
        for(int j = 0 ; j < 4; j++){
            for(int k = 0 ; k < 4; k++){
                if(k == j) continue;
                arr[i + 1][k] = arr[i + 1][k] > land[i + 1][k] + arr[i][j] ? arr[i + 1][k] : land[i + 1][k] + arr[i][j];
            }
        }
    }
    int answer = 0;
    for(int i = 0 ; i < 4 ; i++) answer = answer > arr[land.size() - 1][i] ? answer : arr[land.size() - 1][i];
	return answer;
}