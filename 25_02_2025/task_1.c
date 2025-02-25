// Задание 1. Есть массив строк. Отсортировать по длине

#include <stdio.h>
#include <string.h>
#define ARR_MAX 1000
#define MAX 100

void sort_arr_by_len(char arr[][MAX], int n);
int my_getline(char [], int);

int main() {
    char arr[ARR_MAX][MAX];
    int i = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        my_getline(arr[i], MAX);
    }

    sort_arr_by_len(arr, n);

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


void sort_arr_by_len(char arr[][MAX], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(arr[i]) > strlen(arr[j])) {
                char temp[MAX];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

