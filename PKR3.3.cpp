#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;


struct Sluzhbovets
{
    string prizv;
    char name;
    char lname;
    string posada;
    unsigned rik;
    int salary;
};

void print(Sluzhbovets* s, int N)
{
    cout << "------------------------------------------------------------------------------------"
        << endl;
    cout << "| № |    Прiзвище   |Ім'я  |  По - батькові |  Посада   | Рік прийому  | Зарплата  |"
        << endl;
    cout << "------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].prizv
            << "| " << setw(5) << right << s[i].name
            << "| " << setw(15) << right << s[i].lname
            << "| " << setw(10) << s[i].posada
            << "| " << setw(13) << right << s[i].rik;
        cout << "| " << setw(10) << right << s[i].salary
            << "| " << setw(16) << right << " ";
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------------"
        << endl;
}

void Sort_p(Sluzhbovets* p, const int N)
{
    Sluzhbovets tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (p[i1].prizv > p[i1 + 1].prizv)
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}
void Sort_s(Sluzhbovets* p, const int N)
{
    Sluzhbovets tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (p[i1].salary > p[i1 + 1].salary)
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}
void Sort_r(Sluzhbovets* p, const int N)
{
    Sluzhbovets tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (p[i1].rik > p[i1 + 1].rik)
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int binSearch(Sluzhbovets* p, const int N, const string prizv)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].prizv == prizv)
            return m;
        if (p[m].prizv < prizv)
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}

void Add(Sluzhbovets*& p, int& N , Sluzhbovets s )
{
    Sluzhbovets* tmp = new Sluzhbovets[N + 1]();
    for (size_t i = 0; i < N; i++)
        tmp[i] = p[i];
    tmp[N++] = s;

    if (p != nullptr)
        delete[] p;
    p = tmp;

}
void Delete(Sluzhbovets*& p,  int& N , int index)
{
    if (index >= 0 && index < N) {
        Sluzhbovets* tmp = new Sluzhbovets[N - 1]();
        for (size_t i = 0, i1 = 0; i < N; i++, i1++)
        {
            if (i == index) {
                i1--;
                continue;
            }
            tmp[i1] = p[i];
        }
        N--;
        if (p != nullptr)
            delete[] p;
        p = tmp;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N; int elem; int index;
    string prizv;
    
    Sluzhbovets* s = nullptr ;
    N = 0;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - вивід даних на екран" << endl;
        cout << " [2] - сортування за прізвищем " << endl;
        cout << " [3] - сортування за окладом " << endl;
        cout << " [4] - сортування за роком прийому " << endl;
        cout << " [5] - інформація за прізвищем " << endl;
        cout << " [6] - добавлення до списку " << endl;
        cout << " [7] - вилучення з списку " << endl;
        cout << " [8] - редагування інформації " << endl;
        cout << " [0] - вихід та завершення програми " << endl;
        cout << "Введіть значеня: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 2:
            print(s, N);
            break;
        case 3:
            Sort_p(s, N);
            break;
        case 4:
            Sort_s(s, N);
            break;
        case 5:
            Sort_r(s, N);
            break;
        case 6:
            cout << "Введіть ключі пошуку:" << endl;
            cout << " Прізвище: "; cin >> prizv;
            cout << endl;
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
            if ((elem = binSearch(s, N, prizv)) != -1)
                cout << s[elem].prizv << ' ' << s[elem].name << '.' << s[elem].lname << ". За професією " << s[elem].posada << " з " << s[elem].rik << " року. Зарплата " << s[elem].salary << " грн" << endl;
            else
                cout << "Шуканого службовця не знайдено" << endl;
            break;
        case 7:
        {
            Sluzhbovets s1;
            cout << " Введіть прiзвище : "; cin >> s1.prizv;
            cout << " Введіть ініціали імені : "; cin >> s1.name;
            cout << " Введіть ініціали по-батькові : "; cin >> s1.lname;
            cout << " Введіть посаду : "; cin >> s1.posada;
            cout << " Введіть рік : "; cin >> s1.rik;
            cout << " Введіть зарплату : "; cin >> s1.salary;
            Add(s, N, s1);
            break;
        }
        case 8:
            cout << " Введіть номер службовця , чиї дані ви хочете змінити: "; cin >> index;
            Delete(s, N, index);
            break;
        case 9:
            int i;
            cout << " Введіть номер службовця , чиї дані ви хочете змінити: "; cin >> i;
            if (i >= N || i < 0)
            {
                cout << "Такого службовця не існує" << endl;
                break;
            }
            cout << " Введіть прiзвище : "; cin >> s->prizv;
            cout << " Введіть ініціали імені : "; cin >> s->name;
            cout << " Введіть ініціали по-батькові : "; cin >> s->lname;
            cout << " Введіть посаду : "; cin >> s->posada;
            cout << " Введіть рік : "; cin >> s->rik;
            cout << " Введіть зарплату : "; cin >> s->salary;
            case 0:
            break;

        }
    
    } while (menuItem != 0);

    return 0;
}

