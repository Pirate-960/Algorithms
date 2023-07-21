#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_CITIES 100000
#define OUTPUT_FILE_NAME "output.txt"

typedef struct {
    int id;
    long long x;
    long long y;
    bool visited;
} City;

City cities[MAX_CITIES];
City selected[MAX_CITIES / 2 + 1];
long long total_distance;

// Function to calculate the distance between two cities
long long dist(City c1, City c2) {
    long long dx = c1.x - c2.x;
    long long dy = c1.y - c2.y;
    return round(sqrt(dx * dx + dy * dy));
}

// Function to optimize the tour using 2-opt algorithm
void optimize_tour(int n, long long distances[]){
    int i,j;
    long long first_distance; // Current i-1,i,i+1 + j-1,j,j+1 path length
    long long changed_distance;   // new i-1,j,i+1 + j-1,i,j+1 path lenght, calculations are below
    int improved = 1;       // if there is improvment, run algorithm again
    while (improved) {
        improved = 0;
        // Check if i and j are consecutive cities
        for (i = 0; i < n-1; i++) {
            for (j = i + 1; j < n-1; j++) {
                if (j != i + 1) {       // in example if i=1 and j=2, in changed distance = i-1,j,i+1 + j-1,i,j+1 there is a problem occurs. because in calculation of path i-1,j,i+1  j and i+1 is the same city, same way in j-1,i,j+1 j-1 and i are the same city(i=1,j=2 so i+1=j, j-1=i) this breakes the calculations. So with a if check, we have to do another calculation.
                    if (i == 0) {          // If i=0 we cant calculate dist(selected[i - 1], selected[j]) because there is no selected[-1], so it is selected[n-1]
                        // If i is the first city, calculate the changed distance with selected[n-1]
						changed_distance = dist(selected[j - 1], selected[i]) + dist(selected[i], selected[(j + 1) % n]) + dist(selected[n - 1], selected[j]) + dist(selected[j % n], selected[(i + 1) % n]);   // new i-1,j,i+1 + j-1,i,j+1 path lenght
                    } else {    // else selected[i-1] is ok
                    	// Calculate the changed distance with selected[i-1]
                        changed_distance = dist(selected[j - 1], selected[i]) + dist(selected[i], selected[(j + 1) % n]) + dist(selected[i - 1], selected[j]) + dist(selected[j % n], selected[(i + 1) % n]);   // new i-1,j,i+1 + j-1,i,j+1 path lenght
                    }
                } else {    // if j = i+1, then the changed distance have to be calculated like this for to be comparable with first_distance correctly.
                    if (i == 0) {   // same thing: selected[n-1] vs selected[i-1]
                    	// If i and j are consecutive, calculate the changed distance accordingly
                        changed_distance = 2 * dist(selected[i], selected[j]) + dist(selected[n - 1], selected[j]) + dist(selected[i], selected[(j + 1) % n]);  // new i-1,j,i+1 + j-1,i,j+1 path lenght
                    } else {
                        changed_distance = 2 * dist(selected[i], selected[j]) + dist(selected[i - 1], selected[j]) + dist(selected[i], selected[(j + 1) % n]);  // new i-1,j,i+1 + j-1,i,j+1 path lenght
                    }
                }
                // Calculate the first distance
                if (i == 0) {   // same thing
                    first_distance = distances[n - 1] + distances[i] + distances[j - 1] + distances[j % n]; // Current i-1,i,i+1 + j-1,j,j+1 path length
                }  else {
                    first_distance = distances[i - 1] + distances[i] + distances[j - 1] + distances[j % n]; // Current i-1,i,i+1 + j-1,j,j+1 path length
                }
                
                // If the changed distance is shorter, swap the cities and update distances
                if (changed_distance < first_distance) {    // swap part if new distance is shorter
                    improved = 1;
                    City temp = selected[j];
                    selected[j] = selected[i];
                    selected[i] = temp;

                    if (i == 0) {   // same thing
                        distances[n - 1] = dist(selected[n - 1], selected[i]);  // Distances array updates for ongoing calculations
                    } else {
                        distances[i - 1] = dist(selected[i - 1], selected[i]);
                    }
                    distances[i] = dist(selected[i], selected[(i + 1) % n]);
                    distances[j - 1] = dist(selected[j - 1], selected[j]);
                    distances[j] = dist(selected[j], selected[(j + 1) % n]);
                }
            }
        }
    }
}

int main() {
    struct timespec start_time, end_time;
    int n = 0;
    char InputFileName[100];
    double execution_time = 0;
    printf("***=====================***H-TSP***=====================***\n");
    printf("Enter File Name (Input.txt): ");
    scanf("%s", InputFileName);
    // Reading Input File
    FILE* input = fopen(InputFileName, "r");
    FILE* output = fopen(OUTPUT_FILE_NAME, "w");

    // Start measuring execution time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    // Read city coordinates from input file
    while (fscanf(input, "%d %d %d", &cities[n].id, &cities[n].x, &cities[n].y) != EOF) {
        cities[n].visited = false;
        n++;
    }
    if (cities[n-1].id == n-1) puts("Scanning File -> Successful!\n");
    else {
        puts("Scanning File -> Unsuccesful!\n");
        exit(1);
    }

    total_distance = 0;
    int visited_cities = 0;
    int current_city = 0;
    int i = 0;
    cities[current_city].visited = true;
    selected[visited_cities] = cities[current_city];
    
    // Apply Nearest Neighbor algorithm to construct an initial tour
    while (visited_cities < (n + 1) / 2) {
        long long min_distance = LONG_LONG_MAX;
        int next_city = -1;
        for (i = 0; i < n; i++) {
            if (!cities[i].visited && dist(cities[current_city], cities[i]) < min_distance) {
                min_distance = dist(cities[current_city], cities[i]);
                next_city = i;
            }
        }
        if (next_city != -1) {
            cities[next_city].visited = true;
            current_city = next_city;
            selected[visited_cities++] = cities[current_city];
        } else {
            break;
        }
    }

    long long distances[visited_cities];
    
    // Calculate the distances between consecutive cities in the initial tour
    for (i = 0; i < visited_cities; i++) {
        long long temp = dist(selected[i], selected[(i+1) % visited_cities]);
        distances[i] = temp;
        total_distance += temp;
    }

    fprintf(output, "%d\n", total_distance);

    for (i = 0; i < visited_cities; i++) {
        fprintf(output, "%d\n", selected[i].id);
    }

    fclose(output); // close the output for Nearest Neighbor tour.
    
    // Optimize the tour using the 2-opt algorithm
    optimize_tour(visited_cities, distances);

    long long total_distance_new = 0;
    for (i = 0; i < visited_cities; i++) {
        total_distance_new += distances[i];
    }
    printf("Nearest Neighbor Algorithm: %llu\n", total_distance);
    printf("Optimized Tour Algorithm: %llu\n", total_distance_new);


    int improvment = 1;
    while (improvment) {	// Continue if there is improvment
        improvment = 0;
        City temp = selected[0];
        long long temp2 = distances[0];
        for (i = 0; i < visited_cities - 1; i++) {	// Moves each element in the selected_city array back one, I don't know why this works but changing the array (probably only the first and last element's change matters) improves the path a bit :)
            selected[i] = selected[i + 1];
            distances[i] = distances[i + 1];	// Change distances too
        }
        selected[visited_cities - 1] = temp;
        distances[visited_cities - 1] = temp2;

        optimize_tour(visited_cities, distances);	// Call function again

        long long temp_distance = 0;
        for (i = 0; i < visited_cities; i++) {	// Calculate distance
            temp_distance += distances[i];
        }
        if (temp_distance < total_distance_new){	// Check
            improvment = 1;
            total_distance_new = temp_distance;
            printf("Optimized Tour Algorithm: %llu\n", total_distance_new);
        }


    }

    if (total_distance_new <= total_distance) {
        printf("\n");
        puts("Optimized Tour Algorithm Chosen!");
        output = fopen(OUTPUT_FILE_NAME, "w");  // open output for print the new shortest tour.
        fprintf(output, "%llu\n", total_distance_new);

        for (i = 0; i < visited_cities; i++) {
            fprintf(output, "%d\n", selected[i].id);
        }
    } else {
        printf("\n");
        puts("Nearest Neighbor Algorithm Chosen!");
    }

    fclose(input);
    fclose(output);

    // Stop measuring execution time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate the execution time in milliseconds
    execution_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0; // seconds to milliseconds
    execution_time += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0; // nanoseconds to milliseconds

    printf("Running time: %.6f ms\n", execution_time);
    printf("***=====================***H-TSP***=====================***\n");
    return 0;
}
