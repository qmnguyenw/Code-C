#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void insertAt(char a[][50], int &n, char v[], int i) {
	if(i < 0 || i > n) return;
	int k;
	for(k = n; k > i; k--) { 
	 	strcpy(a[k],a[k - 1]);
	} 
	strcpy(a[i],v); n++;
} 
int imax(char a[][50], int n) {
	int max = 0, i;
	for(i = 1; i < n; i++) 
		if(strlen(a[i]) > strlen(a[max])) max = i;
	return max;
}
int imin(char a[][50], int n) {
	int min = 0, i;
	for(i = 1; i < n; i++) 
		if(strlen(a[i]) < strlen(a[min])) min = i;
	return min;
}
int indexOf(char a[][50], int n, char v[]) {
	int i;
	for(i = 0; i < n; i++){
		if(strcmp(a[i],v) == 0) return i;
	}
	return -1;
}
void removeAt(char a[][50], int&n, int i) {
	if(i < 0 || i >= n) return;
	int k;
	for(k = i; k < n - 1; k++) {
		strcpy(a[k],a[k + 1]);
	}
	n--;
}
void swap(char x[], char y[]) {
	char tg[50];
	strcpy(tg,x); strcpy(x,y); strcpy(y,tg);
}
void bubble(char a[][50], int n) {
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(strcmp(a[i],a[j]) > 0) swap(a[i],a[j]);
}

void split(char st[][50], int &n, char s[]) {//ham chat chuoi thanh mang 
	int i, j, k, len;
	len = strlen(s);
	i = 0;
	n = 0;
	while(i < len) {
		//i la vi tri dau tien ma s[i] != ' '
		while(i < len && s[i] == ' ') i++;
		if(i < len) {
			j = 0;
			char t[50];
			//chep moi ky tu tu i den khi gap ' ' vao t
			while(i < len && s[i] != ' ') {
				t[j] = s[i];i++;j++;
			}
			//copy t vao st
			t[j] = '\0';
			strcpy(st[n],t);
			n++;
		}
		i++;
	}
} 
void toString(char st[][50], int n, char s[]) {// tao mang cac tu thanh chuoi
	strcpy(s,"");
	for(int i = 0; i < n; i++) {
		strcat(s,st[i]);
		if(i < n - 1) strcat(s," ");
	}
}

void toUpper(char s[]) {
	int len = strlen(s), i;
	for(i = 0; i < len; i++) s[i] = toupper(s[i]);
}

void toLower(char s[]) {
	int len = strlen(s), i;
	for(i = 0; i < len; i++) s[i] = tolower(s[i]);
}


int main(){
	
	return 0;
}



