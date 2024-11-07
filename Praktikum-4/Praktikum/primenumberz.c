#include <stdio.h>

int main(){
	int primenums[1000];
	int primenumcount = 1;
	int boolnum = 1;
	int temp = 0;
	primenums[1] = 2;
	for (int i=3; i<=1000; i++){
		boolnum = 1;
		for(int j=1;j<=primenumcount;j++){
			temp = primenums[j];
			if(i%temp == 0){
				boolnum = 0;
			}
		}
		if(boolnum == 1){
			primenumcount++;
			primenums[primenumcount] = i;
		}
	}
	int n;
	scanf("%d", &n);
	int answers[999999];
	int countr = 0;
	int a;
	for(int i=1;i<=n;i++){
		scanf("%d", &a);
		boolnum = 1;
		for(int j=1; j<=primenumcount;j++){
			temp = primenums[j];
			while(a != 1){
				if(a%temp == 0){
					a = a/temp;
					countr++;
					answers[countr] = temp;
				}
				else{
					break;
				}
			}
			if(a == 1){
				break;
			}
		}
	}
	for(int i=1;i<=countr;i++){
		if(i==countr){
			printf("%d\n", answers[i]);
		}
		else{
			printf("%d ", answers[i]);
		}
	}
}
