#include <stdio.h>
#include <string.h>
//This code is made to processes the raw data into a normal input readable by our other algorithms
void processIntoOutput(FILE *input, FILE *output);
int main(){
    int i = 0;

    FILE *input = fopen("input1Raw.txt","r");
    FILE *output = fopen("input1.html","w");
    processIntoOutput(input,output);
    fclose(input);
    fclose(output);
    
    input = fopen("input2Raw.txt","r");
    output = fopen("input2.html","w");
    processIntoOutput(input,output);
    fclose(input);
    fclose(output);

    input = fopen("input3Raw.txt","r");
    output = fopen("input3.html","w");
    processIntoOutput(input,output);
    fclose(input);
    fclose(output);
}

//Function to convert the raw file
void processIntoOutput(FILE *input, FILE *output){
    int i = 0;
    int cur;

    //Loop that goes over every txt specifically made for this data
    do{
        //Ignores certain parts of the data to leave the reasonable parts
        cur = fgetc(input);
        if(cur == '<'){
            while(cur != -1 && cur != '>'){
                cur = fgetc(input);
            }
            fgetc(input);
        }
        else if(cur == '@'){
            int count = 0;
            cur = fgetc(input);
            if(cur == ' '){
                for(;count < 18; count++){
                    fgetc(input);   
                }
            } 
            else if(cur == '@'){
                while(cur != -1 && cur != '>'){
                    cur = fgetc(input);
                }
                fgetc(input);
            }
            else{
                while(cur != -1 && cur != ' '){
                    cur = fgetc(input);
                }
            }
        }
        else fputc(cur,output);
    } while(cur != -1);
    return;
}
