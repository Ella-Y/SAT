//20150249 김예지
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
    int i,max,j;
    vector<int> small_land(4);
    int n=land.size();
    for(i=0;i<n;i++){
        copy(land[i].begin(),land[i].end(),small_land.begin());
        sort(small_land.begin(),small_land.end());
        max=small_land[3];
        if(i==n-1)
            break;
        for(j=0;j<4;j++){
            if(land[i][j]!=max)
                land[i+1][j]+=max;
            else if(max==small_land[2])
                land[i+1][j]+=max;
            else
                land[i+1][j]+=small_land[2];
        }
    }
    answer=max;
	return answer;
}
