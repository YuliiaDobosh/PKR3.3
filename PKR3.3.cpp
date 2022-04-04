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
    cout << "| � |    ��i�����   |��'�  |  �� - ������� |  ������   | г� �������  | ��������  |"
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
    for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
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
    for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
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
    for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (p[i1].rik > p[i1 + 1].rik)
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int binSearch(Sluzhbovets* p, const int N, const string prizv)
{ // ������� ������ ���������� �������� ��� -1, ���� ������� ������� �������
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
        cout << "������� ��:" << endl << endl;
        cout << " [1] - ���� ����� �� �����" << endl;
        cout << " [2] - ���������� �� �������� " << endl;
        cout << " [3] - ���������� �� ������� " << endl;
        cout << " [4] - ���������� �� ����� ������� " << endl;
        cout << " [5] - ���������� �� �������� " << endl;
        cout << " [6] - ���������� �� ������ " << endl;
        cout << " [7] - ��������� � ������ " << endl;
        cout << " [8] - ����������� ���������� " << endl;
        cout << " [0] - ����� �� ���������� �������� " << endl;
        cout << "������ �������: "; cin >> menuItem;
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
            cout << "������ ����� ������:" << endl;
            cout << " �������: "; cin >> prizv;
            cout << endl;
            cin.get(); // ������� ����� ��������� � �� ����������� �������
            cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
            if ((elem = binSearch(s, N, prizv)) != -1)
                cout << s[elem].prizv << ' ' << s[elem].name << '.' << s[elem].lname << ". �� ������� " << s[elem].posada << " � " << s[elem].rik << " ����. �������� " << s[elem].salary << " ���" << endl;
            else
                cout << "�������� ��������� �� ��������" << endl;
            break;
        case 7:
        {
            Sluzhbovets s1;
            cout << " ������ ��i����� : "; cin >> s1.prizv;
            cout << " ������ ������� ���� : "; cin >> s1.name;
            cout << " ������ ������� ��-������� : "; cin >> s1.lname;
            cout << " ������ ������ : "; cin >> s1.posada;
            cout << " ������ �� : "; cin >> s1.rik;
            cout << " ������ �������� : "; cin >> s1.salary;
            Add(s, N, s1);
            break;
        }
        case 8:
            cout << " ������ ����� ��������� , �� ��� �� ������ ������: "; cin >> index;
            Delete(s, N, index);
            break;
        case 9:
            int i;
            cout << " ������ ����� ��������� , �� ��� �� ������ ������: "; cin >> i;
            if (i >= N || i < 0)
            {
                cout << "������ ��������� �� ����" << endl;
                break;
            }
            cout << " ������ ��i����� : "; cin >> s->prizv;
            cout << " ������ ������� ���� : "; cin >> s->name;
            cout << " ������ ������� ��-������� : "; cin >> s->lname;
            cout << " ������ ������ : "; cin >> s->posada;
            cout << " ������ �� : "; cin >> s->rik;
            cout << " ������ �������� : "; cin >> s->salary;
            case 0:
            break;

        }
    
    } while (menuItem != 0);

    return 0;
}

