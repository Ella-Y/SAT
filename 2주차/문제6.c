#include <vector>
using namespace std;

int DP[100001][2][2] = {0, };

int solution(vector<int> sticker)
{
    int N = sticker.size();
    DP[2][0][1] = sticker[0];
    DP[2][1][1] = sticker[0] + sticker[2];
    for(int i = 2 ; i < N - 2 ; i++){
        DP[i + 1][0][1] = DP[i + 1][0][1] > DP[i][0][1] ? DP[i + 1][0][1] : DP[i][0][1];
        DP[i + 1][1][1] = DP[i + 1][1][1] > DP[i][0][1] + sticker[i + 1] ? DP[i + 1][1][1] : DP[i][0][1] + sticker[i + 1];
        DP[i + 2][0][1] = DP[i][1][1];
        DP[i + 2][1][1] = DP[i][1][1] + sticker[i + 2];
    }
    int max1 = DP[N-1][0][1] > DP[N-2][1][1] ? DP[N-1][0][1] : DP[N-2][1][1];
    DP[1][1][0] = sticker[1];
    for(int i = 1 ; i < N - 1 ; i++){
        DP[i + 1][0][0] = DP[i + 1][0][0] > DP[i][0][0] ? DP[i + 1][0][0] : DP[i][0][0];
        DP[i + 1][1][0] = DP[i + 1][1][0] > DP[i][0][0] + sticker[i + 1] ? DP[i + 1][1][0] : DP[i][0][0] + sticker[i + 1];
        DP[i + 2][0][0] = DP[i][1][0];
        DP[i + 2][1][0] = DP[i][1][0] + sticker[i + 2];
    }
    int max2 = DP[N-1][1][0] > DP[N][0][0] ? DP[N-1][1][0] : DP[N][0][0];
    if(N == 1){
        max1 = sticker[0];
        max2 = sticker[0];
    }
    return max1 > max2 ? max1 : max2;
}