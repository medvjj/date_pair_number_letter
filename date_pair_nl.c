#include <stdio.h>

int main(void) {
    int day, month;
    int firstNumber;
    char second;
    int dayOfYear;
    int offset;
    int firstResult, secondResult;
    int result;
    int ch;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    while (1) {
        printf("Enter a date in 2026 (day, month): ");

        result = scanf("%d %d", &day, &month);

        if (result == EOF) {
            return 1;
        }

        if (result == 2 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= daysInMonth[month - 1]) {
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Skip the rest of the line */
            }
            break;
        }

        printf("Invalid date. Please try again.\n");
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Skip the rest of the line */
        }
    }

    while (1) {
        printf("Enter the pair for July 1st (number 1–10 and symbol k–v): ");

        result = scanf("%d %c", &firstNumber, &second);

        if (result == EOF) {
            return 1;
        }

        if (result == 2 &&
            firstNumber >= 1 && firstNumber <= 10 &&
            second >= 'k' && second <= 'v') {
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Skip the rest of the line */
            }
            break;
        }

        printf("Invalid pair. Please try again.\n");
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Skip the rest of the line */
        }
    }

    dayOfYear = day;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    offset = dayOfYear - 182; /* July 1 — the 182nd day of 2026 */

    firstResult = (firstNumber - 1 + offset) % 10;
    secondResult = (second - 'k' + offset) % 12;

    if (firstResult < 0) {
        firstResult += 10;
    }
    if (secondResult < 0) {
        secondResult += 12;
    }

    printf("A number and letter pair for this date: %d %c\n",
           firstResult + 1,
           'k' + secondResult);

    return 0;
}
