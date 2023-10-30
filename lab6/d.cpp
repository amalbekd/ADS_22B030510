#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Date {
    int day, month, year;
};

void swap(Date &date1, Date &date2) {
    Date temp = date1;
    date1 = date2;
    date2 = temp;
}

int partition(vector<Date> &dates, int low, int high) {
    Date pivot = dates[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (dates[j].year < pivot.year || (dates[j].year == pivot.year && dates[j].month < pivot.month) ||
            (dates[j].year == pivot.year && dates[j].month == pivot.month && dates[j].day < pivot.day)) {
            i++;
            swap(dates[i], dates[j]);
        }
    }
    swap(dates[i + 1], dates[high]);
    return i + 1;
}

void quick_sort(vector<Date> &dates, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(dates, low, high);
        quick_sort(dates, low, partitionIndex - 1);
        quick_sort(dates, partitionIndex + 1, high);
    }
}

int main() {
    
    int n;
    cin >> n;

    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        string date;
        cin >> date;

        sscanf(date.c_str(), "%d-%d-%d", &dates[i].day, &dates[i].month, &dates[i].year);

    }

    quick_sort(dates, 0, n - 1);

    for (int i = 0; i < n; i++) {

        printf("%02d-%02d-%d\n", dates[i].day, dates[i].month, dates[i].year);

    }

    return 0;
}