#include <iostream>
#include <string.h>
 
using namespace std;
 
int main()
{
    char eight[333335];
    char first[10][4] = { "","1","10","11","100","101","110","111" };
    char table[10][4] = { "000","001","010","011","100","101","110","111" };
    int len;
 
    cin >> eight;
	if(eight[0]-48==0){
		printf("0\n");
	}else{
		len = strlen(eight);
		printf("%s", first[eight[0] - 48]);
		for (int i = 1; i < len; i++) printf("%s", table[eight[i] - 48]);
		return 0;
	}
}
