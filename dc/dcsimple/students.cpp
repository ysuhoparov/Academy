#include <iostream>
#include <string>
#include <iomanip>

struct student {
    int id;
    std::string name;
    int curs;
    int group;
    int year;
};

bool exist(int ind, int* index, int len) {
    for (int i = 0; i < len; i++) {
        if (index[i] == -1) return false;
        if (index[i] == ind) return true;
    }
    //return false;
}

int main() {
    using namespace std;
    setlocale(LC_ALL, "Russian");

    student st[10] = { 1, "Петров Иван", 3, 111,  2018,
                        2, "Серов Сергей", 2, 112,  2018,
                        3, "Кирилов Александр", 1, 112,  2020,
                        4, "Климова Наталья", 3, 112,  2019,
                        5, "Орлов Сергей", 2, 110,  2018,
                        6, "Борисов Александр", 1, 110,  2020,
                        7, "Семенова Наталья", 2, 111,  2018,
                        8, "Анисимова Мария ", 1, 110,  2020 };

    int i, j, n;
    int slen = sizeof(st) / sizeof(st[0]);

    cout << slen << "\n";

    slen = 8;

    int indexSt[10];
    for (i = 0; i < slen; i++) indexSt[i] = -1;

    string min = "";
    int indexMin = -1;

    cout << "---------------------------------------------\n";
    cout << "| Id | Фамилия Имя          | Группа | Курс |\n";
    cout << "---------------------------------------------\n";

    for (i = 0; i < slen; i++) {    // indexing
        for (n = 0; exist(n, indexSt, slen); n++);
        min = st[n].name; indexMin = n;

        for (j = 0; j < slen; j++) {
            if (exist(j, indexSt, slen)) continue;

            if (st[j].name.compare(min) == -1) {
                min = st[j].name; indexMin = j;
            }
        }
        indexSt[i] = indexMin;
    }

    for (j = 0; j < slen; j++) {
        i = indexSt[j];
        if (st[i].group > 10) {
            cout << "|" << setw(3) << right << st[i].id << " | " << setw(20) << left << st[i].name << " | "
                << setw(6) << right << st[i].group << " | " << setw(4) << st[i].curs << " | " << "\n";
            cout << "---------------------------------------------\n";
        }
    }

    cout << "\n\n";
    cout << "---------------------------------------------\n";
    cout << "| Id | Фамилия Имя          | Группа | Курс |\n";
    cout << "---------------------------------------------\n";

    int found;
    for (j = 0; j < slen; j++) {
        i = indexSt[j];
        found = st[i].name.find("К");
        if (found != string::npos) {
            cout << "|" << setw(3) << right << st[i].id << " | " << setw(20) << left << st[i].name << " | "
                << setw(6) << right << st[i].group << " | " << setw(4) << st[i].curs << " | " << "\n";
            cout << "---------------------------------------------\n";
        }
    }

    for (int k = 0; k < slen; k++)  cout << indexSt[k];

    return(0);
}