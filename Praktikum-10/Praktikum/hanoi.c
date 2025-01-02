#include <stdio.h>
#include "stacklinked.h"

int main() {
  int N, s, d;
  Stack S1, S2, S3;
  ElType temp;

  CreateStack(&S1);
  CreateStack(&S2);
  CreateStack(&S3);

  for (int i = 5; i > 0; i--) {
    push(&S1, i);
  }

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &s, &d);

    if (s == 1) {
      if (isEmpty(S1)) {
        printf("Menara kosong\n");
      } else {
        if (d == 2) {
          if (isEmpty(S2) || TOP(S1) < TOP(S2)) {
            push(&S2, TOP(S1));
            pop(&S1, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        } else {
          if (isEmpty(S3) || TOP(S1) < TOP(S3)) {
            push(&S3, TOP(S1));
            pop(&S1, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        }
      }
    } else if (s == 2) {
      if (isEmpty(S2)) {
        printf("Menara kosong\n");
      } else {
        if (d == 1) {
          if (isEmpty(S1) || TOP(S2) < TOP(S1)) {
            push(&S1, TOP(S2));
            pop(&S2, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        } else {
          if (isEmpty(S3) || TOP(S2) < TOP(S3)) {
            push(&S3, TOP(S2));
            pop(&S2, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        }
      }
    } else if (s == 3) {
      if (isEmpty(S3)) {
        printf("Menara kosong\n");
      } else {
        if (d == 1) {
          if (isEmpty(S1) || TOP(S3) < TOP(S1)) {
            push(&S1, TOP(S3));
            pop(&S3, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        } else {
          if (isEmpty(S2) || TOP(S3) < TOP(S2)) {
            push(&S2, TOP(S3));
            pop(&S3, &temp);
          } else {
            printf("Piringan tidak dapat dipindah\n");
          }
        }
      }
    }
  }

  // Print hasil
  printf("Menara 1: ");
  DisplayStack(S1);
  printf("\n");
  printf("Menara 2: ");
  DisplayStack(S2);
  printf("\n");
  printf("Menara 3: ");
  DisplayStack(S3);
  printf("\n");
}