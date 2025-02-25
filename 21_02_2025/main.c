#include "date_damir.h"
#include <stdio.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 100

struct event {
    int id;
    char name[MAX_EVENT_NAME_LENGTH];
    struct date event_date;
};

int read_events_from_file(const char *filename, struct event events[], int max_events) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int count = 0;
    while (count < max_events && fscanf(file, "%d %[^\n]s", &events[count].id, &events[count].name) == 2) {
        char date_str[11];
        if (fscanf(file, "%s", date_str) != 1) {
            break;
        }
        events[count].event_date = get_day_for_str(date_str);
        count++;
    }

    fclose(file);
    return count;
}


void sort_events_by_date(struct event events[], int num_events) {
    for (int i = 0; i < num_events - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < num_events; ++j) {
            if (lt_date(events[j].event_date, events[min_idx].event_date)) {
                min_idx = j;
            }
        }
        struct event temp = events[i];
        events[i] = events[min_idx];
        events[min_idx] = temp;
    }
}

void write_events_to_file(const char *filename, struct event events[], int num_events) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < num_events; ++i) {
        char time_str[11];
        str_date(time_str, events[i].event_date);
        fprintf(file, "%d %s %s\n", events[i].id, events[i].name, time_str);
    }

    fclose(file);
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = read_events_from_file("schedule.txt", events, MAX_EVENTS);

    for (int i = 0; i < num_events; ++i) {
        char time_str[11];
        str_date(time_str, events[i].event_date);
        printf("ID: %d, Event: %s, Date: %s\n", events[i].id, events[i].name, time_str);
    }
    printf("%s", "\nSort events:\n");
    sort_events_by_date(events, num_events);

    for (int i = 0; i < num_events; ++i) {
        char time_str[11];
        str_date(time_str, events[i].event_date);
        printf("ID: %d, Event: %s, Date: %s\n", events[i].id, events[i].name, time_str);
    }

    write_events_to_file("new_schedule.txt", events, num_events);


    return 0;
}
