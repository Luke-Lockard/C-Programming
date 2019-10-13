/* 5 quiz grades from each of 5 students.
 * Computes total score and average score for each student.
 * Computes average score, high score, and low score for each quiz.
 */

#include <stdio.h>

#define STUDENTS 5
#define QUIZES 5

int main(void)
{
    double a[STUDENTS][QUIZES];
    int student, quiz;
    double score, total, high_score, low_score;

    for (student = 0; student < STUDENTS; student++) {
        printf("Enter quiz grades for student %d: ", student + 1);
        scanf("%lf %lf %lf %lf %lf", &a[student][0], &a[student][1], &a[student][2], &a[student][3], &a[student][4]);
    }
    
    printf("\nStudent total, average:\n");
    for (student = 0; student < STUDENTS; student++) {
        total = 0;
        for (quiz = 0; quiz < QUIZES; quiz++) {
            total += a[student][quiz];
        }
        printf("\tStudent %d: %.2lf, %.2lf\n", student + 1, total, total / QUIZES);
    }
    
    printf("\nQuiz average, high score, low score:\n");
    for (quiz = 0; quiz < QUIZES; quiz++) {
        total = 0;
        high_score = 0;
        low_score = 100;
        for (student = 0; student < STUDENTS; student++) {
            score = a[student][quiz];
            if (score < low_score)
                low_score = score;
            if (score > high_score)
                high_score = score;
            total += score;
        }
        printf("\t Quiz %d: %.2lf, %.2lf, %.2lf\n", quiz + 1, total / STUDENTS, high_score, low_score);
    }
    printf("\n");
    
    return 0;

}