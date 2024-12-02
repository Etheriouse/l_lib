#define true 1
#define false 0

typedef struct t {
    long long unsigned int time;
} time_ ;

void print_arr(int *t, int size);
int *clone_arr(int *t, int size);
void swap(int *arr, int i, int j);
int *random_arr(int lenght);
int *invert_arr(int lenght);
time_ get_time_in_ns();
long double gap(time_ start, time_ end);
long long unsigned int gap_ns(time_ start, time_ end);
void append(char *filename, char *line);
void clear_file(char *filename);
void substring(char *src, char *dest, int start, int end);