#include <stdio.h>
#include<stdlib.h>

const int SIZE = 2048576;
void writeInput1(FILE *output);
void writeInput2(FILE *output);
void writeInput3(FILE *output);
int main(){
    int i = 0;

    FILE *output1= fopen("bitInput1.html","w");
    FILE *output2= fopen("bitInput2.html","w");
    FILE *output3= fopen("bitInput3.html","w");
    writeInput1(output1);
    writeInput2(output2);   
    writeInput3(output3);
}
//Generate a string by randomizing each character
void writeInput1(FILE *output){
    int i;
    for(i = 0; i < SIZE; i++){
        fputc(rand() % 2 == 0 ? '0' : '1',output);
    }
}
//Generate a random string turning random numbers to bits
void writeInput2(FILE *output){
    int current;
    int i,j;
    for(i = 0; i < SIZE; i++){
        current = rand();
        for(j = 0; j < 16; j++){
            putc(current % 2 == 0 ? '0' : '1',output);
            i++;
            current /= 2;
        }
    }
}
//Chooses a random bias from the beginning and randomizes each bit using that bias
void writeInput3(FILE *output){
    int bias = rand();
    int i;
    for(i = 0; i < SIZE; i++){
        fputc(rand() <= bias ? '0' : '1',output);
    }
    
}