#include<stdio.h>

int squared_digit_sum(int x) {

    long long int sum = 0;
    long long int last_digit;
    while(x > 0) {
        last_digit = x % 10;
        sum = sum + last_digit * last_digit;
        x = x/10;
      }
    return sum;
}

int main() {

  long long int array[1000]={0};
  long long int k;
  scanf("%lld", &k);
  long long int i = 0;
  long long int minimum;
  long long int j;
  long long int count=0;
  long long int flag=0;

  //Given the range of k from 1 to 10^9 maximum squared digit value possible will be 81 x 10 = 810(Since it has ten digits)

  // Finding max of k, 810 inorder to maintain an array.

  if(k>=810) {
    minimum = 810;
  }
  else {
    minimum = k;
  }

  // Incrementing the array until minimum
  for(i=0;i<=minimum;i++) {
    array[i]++;
  }

  // If minimum is not equal to k we need to find squared digit sum for elements greater than minimum.
  // As it falls in the range of 810. We are maintaing an array of 810 elements.

  // We are finding map for all the numbers greater than 810 with the elements less than 810 and incrementing the count.
  if(minimum != k) {
    for(i=minimum+1; i<=k; i++) {
      j = squared_digit_sum(i);
      array[j]++;
    }
  }

  count = 0;

  // Looping through the 810 elements.
  // If one elements converges to 1. Then adding the corresponding array[i] to the count.
  // We know that any element converges to any of the below numbers.
   
  for (i=1;i<=minimum;i++) {
    j = i;
    flag = 0;
    while(flag!=1){
      if(j==1){
        count=count+array[i];
        flag = 1;
      }
      else if(j==89 || j==145 || j==42 || j==20 || j==4 || j==16 || j==37 || j==58){
        flag = 1;
      }
      else {
        j=squared_digit_sum(j);
      }
     }
  }
  printf("%lld",count);
}
