#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//tong hop mang
int isPrime(int n) {
	if(n < 2) return 0;
	if(n == 2) return 1;
	int i;
	for(i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int	afterPrime(int n) {
	int i;
	for(i = n + 1; ; i++) {
		if(isPrime(i)) break;
	}		
	return i;
} 

int	beforePrime(int n) {
	int i;
	for(i = n - 1; ; i--) {
		if(isPrime(i)) break;
	}		
	return i;
} 

void swap(int& x, int& y){
	int t = x;
	x = y;
	y = t;
}

void bubbleSort(int a[], int n){
	for (int i = 1; i < n; i++){
		for (int j = 1; j < n; j ++){
			if (a[i] > a[j]) swap(a[j], a[j + 1]);
		}
	}
}

void bubble(int a[], int n){
	int i, j;
	for (i = 0; i < n -1; i++){
		for (j = i + 1; j < n; j++){
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void selection(int a[], int n){
	int i, j, imin;
	for (i = 0; i < n - 1; i ++){
		//find imin where a[imin]=min(a,i+1,n)
		imin = i + 1;
		for (j = i + 1; j < n; j++){
			if(a[j] < a[imin])
				imin = j;
		}
		if (a[imin] < a[i])
			swap(a[i],a[imin]);
	}
}

int imin(int a[],int n){
	int min = 0, i;
	for (i = 1; i < n; i++){
		if (a[i] < a[min]){//tim so nho nhat dau tien trong day
			min = i;
		}
	}
	return min;
}

int imax(int a[],int n){
	int max = 0, i;
	for (i = 1; i < n; i++){
		if (a[i] > a[max]){
			max = i;
		}
	}
	return max;
}

void insert(int a[], int &n, int v, int k){
	if (k < 0 || k > n) return;
	int i;
	for (i = n; i > k; i--){
		a[i] = a[i-1];
	}
	a[k] = v;	n++;
}

void removeAt(int a[],int& n,int k){
	if (k < 0 || k >= n) return;
	int i;
	for (i = k; i < n - 1; i++){
		a[i] = a[i + 1];
	}
	n--;
}

int indexOf(int a[], int n, int v){
	int i;
	for(i = 0; i < n; i++){
		if (a[i] == v){
			return i;
		}
	}
	return -1;//ko tim thay so trong mang
	
}


int main(){
	int a[20];
	int n, i;
	printf("Enter n: ");scanf("%d",&n);
	for(i = 0; i < n; i++){
		printf("a[%d]: ", i);scanf("%d",&a[i]);		
	}
	
	for(i = 0; i < n; i++){
		printf("a[%d]: %d ",i,a[i]);		
	}
	return 0;
}

