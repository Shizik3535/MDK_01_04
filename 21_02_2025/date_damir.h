struct date
{
    int year;
    int month;
    int day;
};

// struct time
// {
//     int hour;
//     int minute;
//     int second;
// };

// Даты
// Создания дат
struct date get_date(int year, int month, int day);

struct date get_day_for_str(char str[]);

// Создание строки даты
void str_date(char str[], struct date d);

// Получения дня, месяца и года из даты
int get_day(struct date d);

int get_month(struct date d);

int get_year(struct date d);

// Сравнение
int eq_date(struct date d1, struct date d2);

int ne_date(struct date d1, struct date d2);

int lt_date(struct date d1, struct date d2);

int le_date(struct date d1, struct date d2);

int gt_date(struct date d1, struct date d2);

int ge_date(struct date d1, struct date d2);


// Увелечение даты
void add_one_day(struct date *pd);


// Массивы дат
struct date get_max_date(struct date arr[], int length);

struct date get_min_date(struct date arr[], int length);

void sort_desc_date_arr(struct date arr[], int length);

void sort_asc_date_arr(struct date arr[], int lenght);

