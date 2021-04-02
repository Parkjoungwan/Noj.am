/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Answer;
int Amenu[200000];
int Bmenu[200000];
vector <int> v;

bool possible(int A, int B, int K){
	int max = Amenu[A]+Bmenu[B];
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			if(i==A||j==B) continue;
			if(max < Amenu[i]+Bmenu[j]) return false;
		}	
	}
	return true;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int N, K;
		cin >> N >> K;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		for (int i=0;i<N;i++){
			cin >> Amenu[i];
		}
		sort(Amenu,Amenu+N);
		for (int i=0;i<N;i++){
			cin >> Bmenu[i];
		}
		sort(Bmenu,Bmenu+N);
		for(int i=0;i<K;i++){
			for(int j=0;j<K;j++){
				if(possible(i,j,K)){
					v.push_back(Amenu[i]+Bmenu[j]);
				}
			}
		}
		sort(v.begin(),v.end());
		Answer=v[0];
		v.clear();
		/////////////////////////////////////////////////////////////////////////////////////////////
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
