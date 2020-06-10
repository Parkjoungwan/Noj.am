#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long binarySearch(vector<long long>& input, long long start, long long end, int target){
    long long maxLen = (start+end)/2;
    long long sum = 0;
    //이진 탐색 시행
    while(start<=end){
        sum = 0;
        maxLen = (start+end)/2;
        for(int i=0;i<input.size();i++){
            sum += input[i]/maxLen;
        }
            //sum이 target보다 작으면 오른쪽 절반 범위 탐색
            if(target>sum){
                end=maxLen-1;
            }
            //sum이 target보다 크거나 같으면 왼쪽 절반 범위 탐색
            else if(sum>=target){
                start=maxLen+1;
            }
    }
    return end;
}
 
int main() {
    int num, targetNum = 0;
    long long sum = 0;
    vector<long long> abc;
    scanf("%d %d",&num, &targetNum);
    getchar();
    for(int i=0;i<num;i++){
        long long temp = 0;
        scanf("%lld ",&temp);
        abc.push_back(temp);
        sum += temp;
    }
    //이진탐색을 위한 정렬
    sort(abc.begin(),abc.end());
    printf("%lld",binarySearch(abc, 1, abc[abc.size()-1],targetNum));
    return 0;
}