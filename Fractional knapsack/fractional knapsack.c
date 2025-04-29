#include <stdio.h>

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sortByRatio(double value[], double weight[], double ratio[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ratio[j] > ratio[i]) {
                swap(&ratio[i], &ratio[j]);
                swap(&value[i], &value[j]);
                swap(&weight[i], &weight[j]);
            }
        }
    }
}

double fractionalKnapsack(int capacity, double value[], double weight[], int n) {
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    sortByRatio(value, weight, ratio, n);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += value[i] * ((double)capacity / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    int capacity ;
    printf("Enter no of objects\n");
    scanf("%d",&n);
    printf("Enter the capacity\n");
    scanf("%d",&capacity);


    double value[n];
    double weight[n];
    printf("Enter the weight and profit of each object\n");
    for(int i=0;i<n;i++)
    {

        printf("For object %d\n",(i+1));
        scanf("%lf %lf",&weight[i],&value[i]);
    }

    double maxValue = fractionalKnapsack(capacity, value, weight, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}

