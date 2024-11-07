#include <stdio.h>

int main(){
	long int numo;
	long int n;
	long int arr[999999];
	long int genapco=0;
	long int ganjilco=1;
	scanf("%ld", &numo);
	scanf("%ld", &n);
	arr[0]=0;
	arr[1]=1;
	if(n==0){
		printf("0\n");
		printf("[0]\n");
		return 0;
	}
	if(n==1){
		if(numo==0){
			printf("0\n");
			printf("[0,1]\n");
		return 0;
		}
		else{
			printf("1\n");
			printf("[0,1]\n");
		return 0;
		}
	}
	for(int i=2;i<=n;i++){
		int num;
		num = arr[i-1]+arr[i-2];
		arr[i]=num;
		if(num%2==0){
			genapco+=num;
		}
		else{
			ganjilco+=num;
		}
	}
	if(numo==0){
		printf("%ld\n", genapco);
	}
	else{
		printf("%ld\n", ganjilco);
	}
	printf("[");
	for(int i=0;i<=n;i++){
		if(i==n){
			printf("%ld", arr[i]);
		}
		else{
			printf("%ld,", arr[i]);
		}
	}
	printf("]\n");
}

