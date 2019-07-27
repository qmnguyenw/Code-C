
#include<stdio.h>
#include <cstdlib>

int main() {
   int i, j, mat1[10][10], mat2[10][10], mat3[10][10];
   int row1, col1, row2, col2;

   printf("\nNhap so hang cua Mat1: ");
   scanf("%d", &row1);
   printf("\nNhap so cot cua Mat1: ");
   scanf("%d", &col1);

   printf("\nNhap so hang cua Mat2: ");
   scanf("%d", &row2);
   printf("\nNhap so cot cua Mat2: ");
   scanf("%d", &col2);

   /* Truoc khi nhap cac phan tu, kiem tra xem so hang va so cot
    cua hai ma tran co bang nhau khong */
   if (row1 != row2 || col1 != col2) {
      printf("\nHai ma tran khong cung kich co!!!");
      exit(0);
   }

   //Nhap cac phan tu cua ma tran 1
   printf("\nNhap ma tran 1\n");
   for (i = 0; i < row1; i++) {
      for (j = 0; j < col1; j++) {
         printf("Nhap phan tu a[%d][%d] : ", i, j);
         scanf("%d", &mat1[i][j]);
      }
   }

   //Nhap cac phan tu cua ma tran 2
   printf("\nNhap ma tran 2\n");
   for (i = 0; i < row2; i++)
      for (j = 0; j < col2; j++) {
         printf("Nhap phan tu b[%d][%d] : ", i, j);
         scanf("%d", &mat2[i][j]);
      }

   //Cong hai ma tran
   for (i = 0; i < row1; i++)
      for (j = 0; j < col1; j++) {
         mat3[i][j] = mat1[i][j] + mat2[i][j];
      }

   //Hien thi ma tran ket qua
   printf("\nKet qua cua phep cong hai ma tran la: \n");
   for (i = 0; i < row1; i++) {
      for (j = 0; j < col1; j++) {
         printf("%d\t", mat3[i][j]);
      }
      printf("\n");
   }

   return (0);
}

