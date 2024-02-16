// Use the provided rubric and criteria to rate each response.

// Given an array representing the weights of bananas of each owner, the maximum limit that the vehicle can hold, find the minimum number vehicles needed to transport all the bananas to the airport.
// Note: There are no loads which are heavier than the given limit.
// The weight of the bananas is measured in tons.

// Constraints
// 0 <= len(arr) <= 10^5
// 0 <= arr[i] <= 10^5
// The array may have duplicate numbers.

// Input
// Variable arr consists of an array of integers denoting the weights of bananas in the godown.
// Variable k consists of a single integer k which denotes the maximum weight limit of the vehicle in tons.

// Output
// Print the minimum number of vehicles needed.

// Time Limit (secs)
// 1

// Examples
// Example 1
// Input
// 4 2 8 5 1 3 6
// 8
// Output
// 4
// Explanation
// We can load (8), (4,3), (6,2), (5, 1) in 4 different vehicles. Any other arrangements will never give less than 4 vehicles.
// Example 2
// Input
// 4 7 9 11 6 8 3
// 12
// Output
// 5
// Explanation
// We can load (11), (8,3), (6,4), (9), (7) in 5 different vehicles. Any other arrangements will never give less than 5 vehicles.
// write c code


// To find the minimum number of vehicles needed to transport all the bananas to the airport, you can follow these steps in C programming:

// Read the number of owners and the maximum weight limit for the vehicle.
// Read the array representing the weights of bananas for each owner.
// Initialize a variable totalWeight to keep track of the total weight of bananas.
// Initialize a variable numVehicles to keep track of the number of vehicles needed.
// Iterate through the array of banana weights and add each weight to totalWeight.
// Check if totalWeight exceeds the maximum weight limit for the vehicle.
// If it does, increment numVehicles by 1, reset totalWeight to the current owner's banana weight, and continue to the next owner.
// After the loop, if there is any remaining weight in totalWeight, increment numVehicles by 1.
// Print the value of numVehicles as the minimum number of vehicles needed.
// Here's a sample C program to implement the above algorithm:



#include <stdio.h>

int main() {
    int numOwners, maxWeightLimit;

    // Read the number of owners and the maximum weight limit
    printf("Enter the number of owners: ");
    scanf("%d", &numOwners);
    printf("Enter the maximum weight limit for the vehicle: ");
    scanf("%d", &maxWeightLimit);

    int bananaWeights[numOwners];

    // Read the array representing the weights of bananas for each owner
    printf("Enter the banana weights for each owner:\n");
    for (int i = 0; i < numOwners; i++) {
        scanf("%d", &bananaWeights[i]);
    }

    int totalWeight = 0;
    int numVehicles = 0;

    for (int i = 0; i < numOwners; i++) {
        totalWeight += bananaWeights[i];

        if (totalWeight > maxWeightLimit) {
            numVehicles++;
            totalWeight = bananaWeights[i];
        }
    }

    if (totalWeight > 0) {
        numVehicles++;
    }

    printf("Minimum number of vehicles needed: %d\n", numVehicles);

    return 0;
}
// This program will read the necessary input and calculate the minimum number of vehicles needed to transport all the bananas to the airport based on the given weights and weight limit.

// Choose the response which you think is better
// After you complete the individual ratings of the responses, make to adjust your response if it is misaligned with the individual ratings.
// Response 1

// To find the minimum number of vehicles needed to transport all the bananas to the airport, you can follow these steps in C programming:

// Read the number of owners and the maximum weight limit for the vehicle.
// Read the array representing the weights of bananas for each owner.
// Initialize a variable totalWeight to keep track of the total weight of bananas.
// Initialize a variable numVehicles to keep track of the number of vehicles needed.
// Iterate through the array of banana weights and add each weight to totalWeight.
// Check if totalWeight exceeds the maximum weight limit for the vehicle.
// If it does, increment numVehicles by 1, reset totalWeight to the current owner's banana weight, and continue to the next owner.
// After the loop, if there is any remaining weight in totalWeight, increment numVehicles by 1.
// Print the value of numVehicles as the minimum number of vehicles needed.
// Here's a sample C program to implement the above algorithm:


// Copy
// Copied!
#include <stdio.h>

int main() {
    int numOwners, maxWeightLimit;

    // Read the number of owners and the maximum weight limit
    printf("Enter the number of owners: ");
    scanf("%d", &numOwners);
    printf("Enter the maximum weight limit for the vehicle: ");
    scanf("%d", &maxWeightLimit);

    int bananaWeights[numOwners];

    // Read the array representing the weights of bananas for each owner
    printf("Enter the banana weights for each owner:\n");
    for (int i = 0; i < numOwners; i++) {
        scanf("%d", &bananaWeights[i]);
    }

    int totalWeight = 0;
    int numVehicles = 0;

    for (int i = 0; i < numOwners; i++) {
        totalWeight += bananaWeights[i];

        if (totalWeight > maxWeightLimit) {
            numVehicles++;
            totalWeight = bananaWeights[i];
        }
    }

    if (totalWeight > 0) {
        numVehicles++;
    }

    printf("Minimum number of vehicles needed: %d\n", numVehicles);

    return 0;
}
//This program will read the necessary input and calculate the minimum number of vehicles needed to transport all the bananas to the airport based on the given weights and weight limit.


// Response 2

// To solve this problem, we can use a greedy approach. The idea is to sort the weights of the bananas in descending order and then try to fit the heaviest remaining banana with the lightest one in the vehicle, as long as the total weight doesn't exceed the vehicle's limit. This way, we can minimize the number of vehicles needed.

// Here's a C code snippet that implements this solution:



#include <stdio.h>
#include <stdlib.h>

// Comparator function for descending order sorting
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Function to find the minimum number of vehicles needed
int minVehicles(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare); // Sort the array in descending order

    int start = 0, end = n - 1;
    int vehicles = 0;

    while (start <= end) {
        if (arr[start] + arr[end] <= k) {
            // If the heaviest and lightest can be combined, move both pointers
            start++;
            end--;
        } else {
            // Otherwise, move only the heaviest pointer
            start++;
        }
        vehicles++;
    }

    return vehicles;
}

int main() {
    int arr[] = {4, 2, 8, 5, 1, 3, 6};
    int k = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of vehicles needed: %d\n", minVehicles(arr, n, k));

    return 0;
}
// In this code:

// We use qsort to sort the array in descending order.
// We have two pointers, start and end, initially pointing to the beginning and end of the array.
// We loop through the array, trying to fit the heaviest and lightest bananas together in a vehicle.
// If the combined weight of the heaviest and lightest is less than or equal to the vehicle's limit, we increment both start and end. Otherwise, we only increment start.
// Each iteration represents the use of one vehicle, so we increment the vehicles count accordingly.
// When start exceeds end, we have considered all the weights, and we return the total number of vehicles used.
// This approach ensures that we always try to optimize the usage of each vehicle's capacity, leading to the minimum number of vehicles needed.

