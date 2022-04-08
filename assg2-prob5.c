/*
3000 assignment 2, problem 5
Use multithreads to run statistics on a list of numbers
Authors: Seymone Gugneja, Shannen Geller, Austin Yarbray
*/

// preliminaries: imports and initialize variables
#include<stdio.h>
#include<pthread.h>

int a[70], len, min, max, avg;

// calculate averages
void *avgNums() {
  float sum=0;

  // enter digits in array
  printf("Enter number of elements in array: ");
  scanf("%d",&len);
  for(int i=0;i<len;i++) {
    scanf("%d",&a[i]);
  }

  // calculate sum and average
  for(int i=0;i<len;i++) {
    sum=sum+a[i];
  }
  avg=sum/len;
  printf("\nThe program will report: \n");
  printf("\nThe average value is %d\n",avg);
}

// calculate minimum number
void *minNum() {
  int tmp=a[0];
  for(int i=1;i<len;i++) {
    if(tmp>a[i]) {
      tmp=a[i];
    }
  }
  min=tmp;
  printf("The minimum value is %d\n",min);
}

// calculate maximum number
void *maxNum() {
  int tmp=a[0];
  for(int i=1;i<len;i++) {
    if(tmp<a[i]) {
      tmp=a[i];
    }
  }
  max=tmp;
  printf("The maximum value is %d\n",max);
}

int main() {

  //initialize threads
  int len;
  pthread_t tid1;
  pthread_t tid2;
  pthread_t tid3;

  // create threads and suspend execution of threads until target thread terminates
  len=pthread_create(&tid1,NULL,&avgNums,NULL);
  len=pthread_create(&tid2,NULL,&minNum,NULL);
  len=pthread_create(&tid3,NULL,&maxNum,NULL);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);
}
