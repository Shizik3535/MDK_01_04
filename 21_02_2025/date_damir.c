#include <stdio.h>
#include "date_damir.h"

// Даты
// Создание дат
struct date get_date(int year, int month, int day) {
    struct date d = {year, month, day};
    return d;
}

struct date get_day_for_str(char str[]) {
    int year, month, day;
    sscanf(str, "%d-%d-%d", &year, &month, &day);
    struct date d = {year, month, day};
    return d;
}

// Создание строки даты
void str_date(char str[], struct date d) {
    sprintf(str, "%04d-%02d-%02d", d.year, d.month, d.day);
}

// Получения дня, месяца и года из даты
int get_day(struct date d) {
    return d.day;
}

int get_month(struct date d) {
    return d.month;
}

int get_year(struct date d) {
    return d.year;
}

// Сравнение
int eq_date(struct date d1, struct date d2) {
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}

int ne_date(struct date d1, struct date d2) {
    return (d1.day != d2.day || d1.month != d2.month || d1.year != d2.year);
}

int lt_date(struct date d1, struct date d2) {
    if (d1.year < d2.year) {
        return 1;
    } else if (d1.year > d2.year) {
        return 0;
    }

    if (d1.month < d2.month) {
        return 1;
    } else if (d1.month > d2.month) {
        return 0;
    }

    return d1.day < d2.day;
}

int le_date(struct date d1, struct date d2) {
    if (d1.year > d2.year) {
        return 1;
    } else if (d1.year < d2.year) {
        return 0;
    }

    if (d1.month > d2.month) {
        return 1;
    } else if (d1.month < d2.month) {
        return 0;
    }

    return d1.day > d2.day;
}

int gt_date(struct date d1, struct date d2) {
    int f = 0;
    if (eq_date(d1, d2)) {
        f = 1;
    }
    else if (d1.year < d2.year) {
        f = 1;
    } else if (d1.month < d2.month) {
        f = 1;
    } else if (d1.day < d2.day) {
        f = 1;
    }
    return f;
}

int ge_date(struct date d1, struct date d2) {
    int f = 0;
    if (eq_date(d1, d2)) {
        f = 1;
    }
    else if (d1.year > d2.year) {
        f = 1;
    } else if (d1.month > d2.month) {
        f = 1;
    } else if (d1.day > d2.day) {
        f = 1;
    }
    return f;
}


// Увелечение даты
void add_one_day(struct date *pd) {
    pd->day = pd->day + 1;
    if (
        (pd->month == 1 || pd->month == 3 || pd->month == 5 ||
         pd->month == 7 || pd->month == 8 || pd->month == 10 ||
         pd->month == 12) && pd->day == 32 ||
        pd->month == 2 && pd->day == 29 ||
    pd->day == 31) {
        pd->month = pd->month + 1;
        pd->day = 1;
    }

    if (pd->month > 12) {
        pd->month = 1;
        pd->year = pd->year + 1;
    }
}


// Массивы дат
struct date get_max_date(struct date arr[], int length) {
    struct date max_d;
    max_d = arr[0];
    for (int i = 1; i < length; i++) {
        if (lt_date(max_d, arr[i])) {
            max_d = arr[i];
        }
    }
    return max_d;
}

struct date get_min_date(struct date arr[], int length) {
    struct date min_d;
    min_d = arr[0];
    for (int i = 1; i < length; i++) {
        if (le_date(min_d, arr[i])) {
            min_d = arr[i];
        }
    }
    return min_d;
}

void sort_desc_date_arr(struct date arr[], int length) {
    struct date d;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (lt_date(arr[i], arr[j])) {
                d = arr[i];
                arr[i] = arr[j];
                arr[j] = d;
            }
        }
    }
}

void sort_asc_date_arr(struct date arr[], int length) {
    struct date d;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (le_date(arr[i], arr[j])) {
                d = arr[i];
                arr[i] = arr[j];
                arr[j] = d;
            }
        }
    }
}


void sort_date_arr(struct date arr[], int length, int desc) {
    int (*func)(struct date, struct date);

    if (desc) {
        func = lt_date;
    } else {
        func = le_date;
    }

    struct date d;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (func(arr[i], arr[j])) {
                d = arr[i];
                arr[i] = arr[j];
                arr[j] = d;
            }
        }
    }
}
