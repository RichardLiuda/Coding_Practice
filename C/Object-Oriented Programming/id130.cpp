#include <iostream>
using namespace std;

class MyDate
{
private:
    int year, month, day;

public:
    void set(int ty = 0, int tm = 0, int td = 0)
    {
        year = ty, month = tm, day = td;
    }
    void print()
    {
        cout << year << "-" << month << "-" << day << endl;
    }
};
MyDate today; // ȫ�ֱ��������ڱ�ҵ��������

class STU
{
private:
    long id;          // ѧ��
    int gra_state;    // δ��ҵΪ0����ҵΪ1
    MyDate *gra_date; // ��ҵ���ڣ���ʼΪ��
public:
    STU(int ti);  // �вι��죬��������Ϣ
    STU(STU &rs); // �������죬���ñ�ҵ״̬�ͱ�ҵ���ڣ���������Ϣ
    ~STU()
    {
        if (gra_state == 1) // �ж��Ƿ��ҵ
        {
            cout << "��ҵ��" << id << "������" << endl;
            cout << "��ҵ����";
            gra_date->print();
            delete gra_date;
        }
        else
            cout << "ѧ��" << id << "������" << endl;
    }
};
// ʵ��STU����вι���Ϳ�������
/********** Write your code here! **********/
STU::STU(int ti)
{
    id = ti;
    gra_state = 0;
    gra_date = nullptr;
    cout << "ѧ��" << id << "�ѹ���" << endl;
}

STU::STU(STU &rs)
{
    id = rs.id;
    gra_state = 1;
    gra_date = new MyDate;
    *gra_date = today;
    cout << "��ҵ��" << id << "�ѹ���" << endl;
}

/*******************************************/
// ����������
int main()
{
    int y, m, d, ti;
    cin >> y >> m >> d;
    today.set(y, m, d);
    cin >> ti;
    STU s1(ti);  // ͨ�����캯������һ����Уѧ��
    STU s2 = s1; // ͨ�������������ɱ�ҵ��

    return 0;
}