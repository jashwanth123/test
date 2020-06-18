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
  long long int loopelement[1000]={0};
  long long int k;
  long long int i = 0;
  long long int minimum;
  long long int j;
  long long int count=0;
  long long int flag=0;
  long long int hashmap[1000]={0};

  /*
  Considering only 1000 since any number greater than 1000 will eventually converge to less than 1000.
  because for any 4 digit integer sum of Squares of digits
  will always be less than the given number.

  It is enough to loop over all three digit numbers and find the looping element.
 */

 // Loop for traversing through 1000 numbers
  for(i=0;i<1000;i++){

    //Initializing visited to 0 because we need to calculate for every number
    for(j=0;j<1000;j++){
      array[j]=0;
    }
    k = i;

    //Traversing the loop until we find the first repeated element.
    while(array[k]!=1){
      array[k]=1;
      k=squared_digit_sum(k);
    }
    loopelement[i]=k;
  }

  // Using hashmap here inorder to find the distinct elements which starts loop.
  for(i=0;i<1000;i++) {
    hashmap[loopelement[i]]=1;
  }

  // Printing all the elements which starts a loop.
  for(i=0;i<1000;i++) {
    if(hashmap[i]==1){
      printf("%lld ",i);
    }
  }
  printf("\n");
  return 0;
}
