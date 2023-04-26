#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t collatz_orbit(uint64_t n, uint64_t k) {
   for (uint64_t i = 0; i < k; i++) {
     if (n%2==0) {
       n=n>>1;
     }
     else {
       if (n >= 6148914691236517205) return 0;
       n=(n << 1) + n + 1;
     }
     if (n==1) {
       char m=(k-i)%3;
       if (m==0) return 2;
       else if (m==1) return 1;
       else return 4;
     }
    }
  return n; // FIXME!
}



int main() {
  uint64_t n, k;

  printf("Enter the value of n: ");
   scanf("%llu", &n);

  printf("Enter the value of k: ");
  scanf("%llu", &k);

  uint64_t result=collatz_orbit(n,k);


  printf("\nThe value of n after k iterations in hexadecimal is %" PRIX64 "\n", result);
  printf("The value of n after k iterations in decimal is %" PRIu64 "\n\n", result);
  printf("Type anything and press Enter to leave...");
  scanf("%d");

  return 0;
}