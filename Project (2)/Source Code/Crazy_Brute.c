#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100000
#define OUTPUT_FILE_NAME "output.txt"

typedef struct {
    int id;
    int x;
    int y;
    bool visited;
} City;

City cities[MAX_CITIES];
int *selected1;
int *selected2;
FILE *outputTest;
int meanC = 0;
int *distanceToBeginningSorted;

int dist(City c1, City c2) {
    long dx = c1.x - c2.x;
    long dy = c1.y - c2.y;
    return round(sqrt(dx * dx + dy * dy));
}


int *calculateLengthArray(int length){
    int *vals = calloc(length * length, sizeof(int));
    int i,k,temp;
    temp = 0;
    for(i = 0; i < length; i++){ 
        for(k = 0; k < length; k++){
            vals[temp + k] = dist(cities[i],cities[k]);
        }
        temp += length;
    }
    return vals;
}
float calculateMean(int *array, int length){
    int i,k,temp;
    float mean = 0;
    for(i = 0, temp = 0; i < length; i++){
        for(k = 0; k < length; k++){
            mean += array[temp + k];
        }
        temp += length;
    }
    return mean / (length * length);
}



void bSortretIndex(int *returnArray,int *array, int length){
    int i,k,prev;
    prev = __INT32_MAX__;
    int smallestVal, smallestValIndex, temp;
    for(i = 0; i < length; i++){
        smallestVal = 0;
        smallestValIndex = i;
        for(k = 0; k < length; k++){
            if(smallestVal < array[k] && array[k] < prev){
                smallestVal = array[k];
                smallestValIndex = k;
            }
        }
        returnArray[i] = smallestValIndex;
        prev = smallestVal;
    }
    
}
int *copyArray(int *array, int length){
	int i;
    int *retArray = malloc(length * sizeof(int));
    for(i = 0; i < length; i++){
        retArray[i] = array[i];
    } 
    return retArray;
}
void resetOutput(int length){
    meanC = 0;
    int i;
    for(i = 1; i < length; i++){
        cities[selected1[i]].visited = false;
        selected1[i] = 0;
    }
}

void twoLongSticksFunction(int length, float mean, int *distanceArray, int meanDivide){
    int totalLength = 0;
    int i,k,l,index;
    int prevCity1 = 0;
    int prevCity2 = 0;
    int currentDistance;
    int smallestCurDistance;
    int smallestCurDistCity;
    int total = (length + 2) / 4;
    mean /= meanDivide;
    for(i = 1, k = (length + 1) / 2; i < k; i++, k--){

        smallestCurDistance = __INT32_MAX__;
        for(l = 1; l < length; l++) {
            index = distanceToBeginningSorted[l];
            if(!cities[index].visited){
                currentDistance = distanceArray[prevCity1 * length + index];
                if(currentDistance < mean){
                    meanC++;
                    smallestCurDistance = currentDistance;
                    smallestCurDistCity = index;
                    break;
                }
                else{
                    if(currentDistance < smallestCurDistance){
                        smallestCurDistance = currentDistance;
                        smallestCurDistCity = index;
                    }
                }
            }   
        }
        prevCity1 = smallestCurDistCity;
        selected1[i] = smallestCurDistCity;
        cities[smallestCurDistCity].visited = true;
        
        smallestCurDistance = __INT32_MAX__;

        for(l = 1; l < length; l++) {
            index = distanceToBeginningSorted[l];
            if(!cities[index].visited){
                currentDistance = distanceArray[prevCity2 * length + index];
                if(currentDistance < mean){
                    meanC++;
                    smallestCurDistance = currentDistance;
                    smallestCurDistCity = index;
                    break;
                }
                else{
                    if(currentDistance < smallestCurDistance){
                        smallestCurDistance = currentDistance;
                        smallestCurDistCity = index;
                    }
                }
            }
        }
        
        prevCity2 = smallestCurDistCity;
        selected1[k] = smallestCurDistCity;
        cities[smallestCurDistCity].visited = true;
        
    } 
    if(i == k){
        smallestCurDistance = __INT32_MAX__;
        for(l = 1; l < total; l++) {
            index = distanceToBeginningSorted[l];
            if(!cities[index].visited){
                currentDistance = distanceArray[prevCity2 * length + index];
                if( currentDistance < mean){
                    meanC++;
                    smallestCurDistance = currentDistance;
                    smallestCurDistCity = index;
                    break;
                }
                else{
                    if(currentDistance < smallestCurDistance){
                        smallestCurDistance = currentDistance;
                        smallestCurDistCity = index;
                    }
                }
            }
        }
        selected1[k] = smallestCurDistCity;
        cities[smallestCurDistCity].visited = true;
    }
}
void twoLongSticksFunctionCall(int length, float mean, int *distanceArray){
    float ratio = 1;
    int divider = 1;
    int checker = 1;
    int val = -1;
    int halfLength = (length + 2) / 2;
    while(checker){
        twoLongSticksFunction(length, mean, distanceArray, divider);
        if(meanC == halfLength){
            ratio = 1.1;
        }
        else{
            ratio = (meanC * 1.0) / halfLength;
        }
        printf("ratio%f:meanC%d\n",ratio,meanC);
        checker = ratio > 0.9 || ratio < 0.8;
        if(checker){
            if(ratio > 0.9){
                divider *= 2;
            }
            else {
                if(val == -1){
                    val = divider / 2;
                    divider -= val;
                }
                else if(val == 0){
                    ratio = 0.85;
                    return;
                }else{
                    val /= 2;
                    divider -= val;
                }
            }
            resetOutput(halfLength);
        }
    }
    
    return;

}
int main() {
    printf("Enter file name :");
    char inputStr[100];
    scanf("%s", inputStr);
    FILE* input = fopen(inputStr, "r");
    if(input == NULL){
        printf("File \"%s\" not found", inputStr);
        exit(errno);
    }
    long time = clock();
    FILE* output = fopen(OUTPUT_FILE_NAME, "w");
    int n = 0;
    char c;
    outputTest = fopen("output1.txt","w");
    while (fscanf(input, "%d %d %d", &cities[n].id, &cities[n].x, &cities[n].y) > 0) {
        cities[n].visited = false;
        n++;
    }
    n--;
    int *lengthArray = calculateLengthArray(n);
    float mean = calculateMean(lengthArray, n);
    printf("mean:%f\n", mean);
    int total_distance = 0;
    int i = 0;
    cities[0].visited = true;
    selected1 = calloc(sizeof(int), (n + 1) / 2);
    selected2 = calloc(sizeof(int), (n + 1)/ 2);
    selected1[0] = 0;
    selected2[0] = 0;

    distanceToBeginningSorted = calloc(n, sizeof(int));
    int *tempArray = copyArray(lengthArray, n);
    bSortretIndex(distanceToBeginningSorted , tempArray, n);
    free(tempArray);

    twoLongSticksFunctionCall(n, mean, lengthArray);
    printf("took %f sec, mean count : %d out of %d\n", (clock() - time) / 1000.0, meanC, (n+2) / 2);

    for (i = 0; i < (n + 2) / 2; i++) {
        total_distance += dist(cities[selected1[i]], cities[selected1[(i+1) % ((n + 2) / 2)]]);
    }
    // Write total distance to the first line
    fprintf(output, "%d\n", total_distance);

    for (i = 0; i < (n + 2) / 2; i++) {
        fprintf(output, "%d\n", cities[selected1[i]].id);
    }

    fclose(input);
    fclose(output);


    return 0;
}

