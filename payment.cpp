//#include "payment.hh"
#include <string>
#include <iostream>
#include <stdexcept>

using uInt = unsigned int;
using namespace std;

class Payment
{
private:
    string name;
    double salary = 0;     //�����
    uInt percent = 200;    //��業� ��������
    double tax = 0;        //����室�� �����
    uInt spentDays = 40;   //������⢮ ��ࠡ�⠭��� ����
    uInt workingDays = 40; //���-�� ࠡ��� ����
    double accrued = 0;    //���᫥��
    double withheld = 0;   //㤥�堭��
    void calculeteTax() noexcept;
    void calculeteAccrued() noexcept;
    void calculeteWittheld() noexcept;

public:
    void setName(string PaymentName) noexcept;
    void setSalary(double PaymentSalary);
    void setPercent(uInt PaymentPercent);
    void setSpeentDays(uInt PaymentSpeentDays);
    void setWorkingDays(uInt PaymentWorkingDays);

    void Init(string PaymentName, double PaymentSalary, uInt PaymentPercent, uInt PaymentSpeentDays, uInt PaymentWorkingDays) noexcept
    {
        setName(PaymentName);
        setSalary(PaymentSalary);
        setPercent(PaymentPercent);
        setSpeentDays(PaymentSpeentDays);
        setWorkingDays(PaymentWorkingDays);
    }
    void Init(Payment payment) noexcept
    {
        name = payment.getName();
        salary = payment.getSalary();
        percent = payment.getPercent();
        spentDays = payment.getSpentDays();
        workingDays = payment.getWorkingDays();
    }

    double getAccrued() noexcept;
    double getWithheld() noexcept;
    double getPaymennt() noexcept;

    string getName() const;
    double getSalary() const;
    uInt getPercent() const;
    double getTax() const;
    uInt getSpentDays() const;
    uInt getWorkingDays() const;
    string toSring() noexcept
    {
        string str = "Name: ";
        str += getName();
        str += " Salary: ";
        str += getSalary();
        str += " Percent: ";
        str += getPercent();
        str += " Tax: ";
        str += getTax();
        str += " Spent Days: ";
        str += getSpentDays();
        str += " WorkinDays: ";
        str += getWorkingDays();
        str += " Accrued: ";
        str += getAccrued();
        str += " Wittheld: ";
        str += getWithheld();
        return str;
    }

    void Read() noexcept;
    void Display() noexcept;
};

void Payment::calculeteTax() noexcept
{
    tax = getAccrued() * 0.13;
}
void Payment::calculeteAccrued() noexcept
{
    accrued = (salary * spentDays);
    accrued += accrued * (percent / 100);
}
void Payment::calculeteWittheld() noexcept
{
    if (accrued == 0)
    {
        calculeteAccrued();
    }
    withheld = getTax() + (accrued * 0.01);
}

void Payment::setName(string PaymentName) noexcept
{
    name = PaymentName;
}
void Payment::setSalary(double PaymentSalary)
{
    if (PaymentSalary < 0)
    {
        throw std::out_of_range("�������⨬� ����, ���祭�� ������ ���� ����� ���");
    }
    salary = PaymentSalary;
}
void Payment::setPercent(uInt PaymentPercent)
{
    if (PaymentPercent > 100)
    {
        throw std::out_of_range("�������⨬� ����, ���祭�� ������ ���� �� ����� ��");
    }
    percent = PaymentPercent;
}
void Payment::setSpeentDays(uInt PaymentSpeentDays)
{

    if (PaymentSpeentDays > 31)
    {
        throw std::out_of_range("�������⨬� ����, ���祭�� ������ ���� �� ����� 31");
    }
    spentDays = PaymentSpeentDays;
}
void Payment::setWorkingDays(uInt PaymentWorkingDays)
{
    if (PaymentWorkingDays > 31)
    {
        throw std::out_of_range("�������⨬� ����, ���祭�� ������ ���� �� ����� 31");
    }
    workingDays = PaymentWorkingDays;
}

double Payment::getAccrued() noexcept
{
    if (accrued == 0)
    {
        calculeteAccrued();
    }
    return accrued;
}
double Payment::getWithheld() noexcept
{
    if (withheld == 0)
    {
        calculeteWittheld();
    }
    return withheld;
}
double Payment::getPaymennt() noexcept
{
    if (withheld == 0)
    {
        calculeteWittheld();
    }
    return accrued - withheld;
}

string Payment::getName() const
{
    if (name.length() < 1)
    {
        throw 1;
    }
    return name;
}
double Payment::getSalary() const
{
    if (salary == 0)
    {
        throw 1;
    }
    return salary;
}
uInt Payment::getPercent() const
{
    if (percent == 200)
    {
        throw 1;
    }
    return percent;
}
double Payment::getTax() const
{
    if (tax == 0)
    {
        throw 1;
    }
    return tax;
}
uInt Payment::getSpentDays() const
{
    if (spentDays == 40)
    {
        throw 1;
    }
    return spentDays;
}
uInt Payment::getWorkingDays() const
{
    if (workingDays == 40)
    {
        throw 1;
    }
    return workingDays;
}

void Payment::Read() noexcept
{
    string name;
    double salary;
    uInt percent, speentDays, workingDays;

    cout << "������ ��� ���짮��⥫�: ";
    cin >> name;
    cout << "������ �����: ";
    cin >> salary;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ���祭�� ᭮��: ";
        cin >> salary;
    }
    cout << "������ ��業� ��������: ";
    cin >> percent;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ���祭�� ᭮��: ";
        cin >> percent;
    }
    cout << "������ ������⢮ ��ࠡ�⠭��� ����: ";
    cin >> speentDays;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ���祭�� ᭮��: ";
        cin >> speentDays;
    }
    cout << "������ ������⢮ ࠡ��� ����: ";
    cin >> workingDays;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ���祭�� ᭮��: ";
        cin >> workingDays;
    }
    Init(name, salary, percent, speentDays, workingDays);
}
void Payment::Display() noexcept
{
    cout << toSring();
}

int main()
{
    cout << "������ୠ� � 1 ��ਠ�� � 6 �믮����: �㫠⮢ ����਩\n";
    Payment pay;
    Payment pay2;
    int menu;
    while (menu != 0)
    {
        /* code */
        cout << "\n_MENU_\n[1]- ��������� ����(��筮� ����)\n[2]- ��������� ����(���祭�ﬨ ���� ��㣮�� �������)\n";
        cout << "[3]- ���᫥��� ���᫥���� �㬬�\n[4]- ���᫥��� 㤥ঠ���� �㬬�\n[5]- ���᫥��� �뤮������ �㬬�\n";
        cout << "[6]- �뢮� ����� �� �࠭\n";
        cout << "��� �롮�: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            pay.Read();
            break;
        case 2:
            pay2.Init("nickname", 15000.20, 30, 20, 28);
            cout << "���祭�� ����� � �����㥬�� ������� (pay2): ";
            pay2.Display();
            pay.Init(pay2);
            cout << "������ �� ���祭�� ᪮��஢����� � �᭠���� �������(pay): ";
            pay.Display();
            break;
        case 3:
            cout << "�㬬� ࠢ��: " << pay.getAccrued();
            break;
        case 4:
            cout << "�㬬� ࠢ��: " << pay.getWithheld();
            break;
        case 5:
            cout << "�㬬� ࠢ��: " << pay.getPaymennt();
            break;
        case 6:
            try // �饬 �᪫�祭�� ����� �⮣� ����� � ��ࠢ�塞 �� � ᮮ⢥�����騩 ��ࠡ��稪 catch
            {
                pay.Display();
            }
            catch (int e) // ��ࠡ��稪 �᪫�祭�� ⨯� const char*
            {
                cout << "Error: " << e << '\n';
            }
            break;
        default:
            cout << " �� ���� ����!\n";
            break;
        }
    }
    return 0;
}