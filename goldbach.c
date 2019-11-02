#include <stdio.h>
#include <math.h>

//Function declerations
int is_prime(int n);
void goldbach(int g, int primes[], int last_prime_index);

int main(){
    //Buffer for primes
    int primes[100000] = {2};
    int last_prime_index = 0;

    int number = 0;
    while(1){
        printf("Enter even number:");
        scanf("%d",&number);
        if(number>2 && number%2==0){
            goldbach(number, primes[100000], last_prime_index);
        }
        else{
            printf("Incorrect number!\n");
        }
        printf("\n");
    }
    return 0;
}

//Check is prime?
int is_prime(int n){
    // Checks if j <= sqrt(n). This will make your code much more performant for larger numbers
    for (int j = 2; j <= sqrt(n); j++)
    {
        if((n%j) == 0){
            return 0;
        }
    }
    return 1;
}

//Goldbach solutions of a double integer greater than 2.
void goldbach(int g, primes[], last_prime_index){
    if(primes[j]<g){
        for (int i = primes[j]+1; i < g; i++)
        {
            if(is_prime(i) == 1){
                j++;
                primes[j] = i;
            }
        }       
    }

    for (int i = 0; i < last_prime_index; i++)
    {
        for (int k = 0; k < last_prime_index; k++)
        {
            if(primes[i] + primes[k] == g){
                printf("%d = %d + %d\n",g,primes[i],primes[k]);
                break;
            }
        }
    }

}

/*
You can easily avoid the global variables primes and j by declaring them inside main. Yes, you will have to pass additional arguments to goldbach but that's fine.

It is hard to understand what the meaning of j is. You should use a more expressive name like last_prime_index.

In is_prime you declare another variable j which shadows the global j. This can easily cause errors..



The goldbach function does two different things, calculation and output. It could be split into two separate functions.

You should check if j < 100000 before incrementing it.