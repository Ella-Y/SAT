#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int arr[1002][1002] = {0, };
    int row = board.size();
    int col = board[0].size();
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            arr[i][j] = board[i][j];
            if(i != 0) arr[i][j] += arr[i - 1][j];
            if(j != 0) arr[i][j] += arr[i][j - 1];
            if(i != 0 && j != 0) arr[i][j] -= arr[i-1][j-1];
        }
    }
    int max = 1;
    for(int i = 0 ; i < row - max ; i++){
        for(int j = 0 ; j < col - max ; j++){
            char check = 0;
            while(check == 0){
                int sum = 0;
                sum += arr[i + max][j + max];
                if(i != 0) sum -= arr[i - 1][j + max];
                if(j != 0) sum -= arr[i + max][j - 1];
                if(i != 0 && j != 0) sum += arr[i - 1][j - 1];
                if(sum == (max + 1)*(max + 1)) max++;
                else{
                    check = 2;
                }
            }
        }
    }
    if(arr[row - 1][col - 1] == 0) max = 0;
    return max*max;
}