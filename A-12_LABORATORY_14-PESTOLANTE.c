#include <stdio.h>

// Define constants for the number of students and grades
#define numStudents 5
#define numGrades 3

// Function prototypes
void inputStudentData(int ids[], char names[][50], float grades[][numGrades]);
void calculateAverage(float grades[][numGrades], float average[]);
void findTopStudents(int ids[], char names[][50], float average[]);

int main() {
    int ids[numStudents];
    char names[numStudents][50];
    float grades[numStudents][numGrades];
    float average[numStudents];

    // Input student data
    inputStudentData(ids, names, grades);

    // Calculate average
    calculateAverage(grades, average);

    // Find and display the top 3 students
    findTopStudents(ids, names, average);

    return 0;
}

// Function to input student IDs, names, and grades
void inputStudentData(int ids[], char names[][50], float grades[][numGrades]) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("  ID: ");
        scanf("%d", &ids[i]);


        printf("  Name: ");
        scanf(" %[^\n]", names[i]); // "%[^\n]" reads all characters except the newline ('\n'), allowing input with spaces
                                    // Utilized to get full names (ex. Kurt Cobain)

        printf("  Enter %d grades:\n", numGrades);
        for (int j = 0; j < numGrades; j++) {
            printf("    Grade %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
        printf("-----------------------------\n");
    }
    printf("-----------------------------\n");
}

// Function to calculate average
void calculateAverage(float grades[][numGrades], float average[]) {
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < numGrades; j++) {
            sum += grades[i][j];
        }
        average[i] = sum / numGrades;
    }
}

// Function to find and display the top 3 students
void findTopStudents(int ids[], char names[][50], float average[]) {
    // Array to track positions of the top 3 students
    int topPosition[3] = {-1, -1, -1};

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < 3; j++) {
            if (topPosition[j] == -1 || average[i] > average[topPosition[j]]) {
                // Shift lower scores down the list
                for (int k = 2; k > j; k--) {
                    topPosition[k] = topPosition[k - 1];
                }
                topPosition[j] = i;
                break;
            }
        }
    }

    printf("Top 3 Students:\n");
    for (int i = 0; i < 3 && topPosition[i] != -1; i++) {
        int index = topPosition[i];
        printf("%d. %s (ID: %d) - Average: %.2f\n",
               i + 1, names[index], ids[index], average[index]);
    }
    printf("-----------------------------\n");
}
