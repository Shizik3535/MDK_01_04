// Задание 3. Отпечатать сумму элементов по каждой строке и общую сумму

#include <stdio.h>
#include <string.h>
#define ARR_MAX 1000
#define MAX 100

int sum_arr(char arr[][MAX], int n);
int my_getline(char [], int);

int main() {
    char arr[ARR_MAX][MAX];
    int n;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        my_getline(arr[i], MAX);
    }

    int s;
    s = sum_arr(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}


int my_getline(char s[], int lim) {
	int i;
	int ch;
	for (i = 0; i < lim-1 && (ch = getchar()) != EOF && ch != '\n'; i = i + 1) {
		s[i] = ch;
	}
	s[i] = '\0';
	return i;
}


int sum_arr(char arr[][MAX], int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        printf("%d", strlen(arr[i]));
        total_sum += strlen(arr[i]);
    }
    return total_sum;
}

