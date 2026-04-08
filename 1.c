#include <stdio.h>

#define MAX 100

// Function: Static Predictor (Always Taken)
void static_taken(int arr[], int n) {
    int correct = 0;

    for (int i = 0; i < n; i++) {
        int prediction = 1; // Always Taken
        if (prediction == arr[i]) {
            correct++;
        }
    }

    printf("\n[Static Predictor - Always Taken]");
    printf("\nCorrect Predictions: %d", correct);
    printf("\nAccuracy: %.2f%%\n", (float)correct / n * 100);
}

// Function: 1-bit Predictor
void one_bit(int arr[], int n) {
    int correct = 0;
    int prediction = 1; // initial guess

    for (int i = 0; i < n; i++) {
        if (prediction == arr[i]) {
            correct++;
        } else {
            prediction = arr[i]; // update on misprediction
        }
    }

    printf("\n[1-bit Predictor]");
    printf("\nCorrect Predictions: %d", correct);
    printf("\nAccuracy: %.2f%%\n", (float)correct / n * 100);
}

// Function: 2-bit Predictor
void two_bit(int arr[], int n) {
    int correct = 0;
    int state = 3; // Strongly Taken

    for (int i = 0; i < n; i++) {
        int prediction = (state >= 2) ? 1 : 0;

        if (prediction == arr[i]) {
            correct++;
        }

        // Update state
        if (arr[i] == 1 && state < 3) {
            state++;
        } else if (arr[i] == 0 && state > 0) {
            state--;
        }
    }

    printf("\n[2-bit Predictor]");
    printf("\nCorrect Predictions: %d", correct);
    printf("\nAccuracy: %.2f%%\n", (float)correct / n * 100);
}

// Main Function
int main() {
    int arr[MAX], n;

    printf("Enter number of branches: ");
    scanf("%d", &n);

    printf("Enter branch outcomes (1 = Taken, 0 = Not Taken):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    static_taken(arr, n);
    one_bit(arr, n);
    two_bit(arr, n);

    return 0;
}