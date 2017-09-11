/* kakao 모의문제 20150249 김예지
*/
#include <vector>
using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
int solution(vector<int> sticker)
{
    if(sticker.size()==1)
        return sticker[0];
    if(sticker.size()<4){
        int mmax=-1;
        for(int i=0;i<sticker.size();i++){
            mmax=max(mmax,sticker[i]);
        }
        return mmax;
    }
	int answer = 36;
	int n = sticker.size();
	vector<int>ans0; //0번째 값을 선택하는 경우
	vector<int>ans1;  //1번째 값을 선택하는 경우

	ans0.push_back(sticker[0]);
	ans0.push_back(sticker[0]);
	ans1.push_back(0);
	ans1.push_back(sticker[1]);
	int i = 2;
	for (i = 2; i < n; i++){
		answer = max(ans0[i - 2] + sticker[i], ans0[i - 1]);
		ans0.push_back(answer);
		answer = max(ans1[i - 2] + sticker[i], ans1[i - 1]);
		ans1.push_back(answer);
	}
	
	return max(ans0[n - 2], ans1[n - 1]);
}
