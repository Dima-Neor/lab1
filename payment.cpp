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
    double salary = 0;     //оклад
    uInt percent = 200;    //процент надбавки
    double tax = 0;        //подоходный налог
    uInt spentDays = 40;   //количество отработанных дней
    uInt workingDays = 40; //кол-во рабочих дней
    double accrued = 0;    //начислено
    double withheld = 0;   //удерханно
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
        throw std::out_of_range("Недопустимый ввод, значение должно быть больше нуля");
    }
    salary = PaymentSalary;
}
void Payment::setPercent(uInt PaymentPercent)
{
    if (PaymentPercent > 100)
    {
        throw std::out_of_range("Недопустимый ввод, значение должно быть не больше ста");
    }
    percent = PaymentPercent;
}
void Payment::setSpeentDays(uInt PaymentSpeentDays)
{

    if (PaymentSpeentDays > 31)
    {
        throw std::out_of_range("Недопустимый ввод, значение должно быть не больше 31");
    }
    spentDays = PaymentSpeentDays;
}
void Payment::setWorkingDays(uInt PaymentWorkingDays)
{
    if (PaymentWorkingDays > 31)
    {
        throw std::out_of_range("Недопустимый ввод, значение должно быть не больше 31");
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

    cout << "Введите имя пользователя: ";
    cin >> name;
    cout << "Введите оклад: ";
    cin >> salary;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите значение снова: ";
        cin >> salary;
    }
    cout << "Введите процент надбавки: ";
    cin >> percent;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите значение снова: ";
        cin >> percent;
    }
    cout << "Введите количество отработанных дней: ";
    cin >> speentDays;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите значение снова: ";
        cin >> speentDays;
    }
    cout << "Введите количество рабочих дней: ";
    cin >> workingDays;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите значение снова: ";
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
    cout << "ЛАбараторная № 1 Вариант № 6 Выполнил: Булатов Дмитрий\n";
    Payment pay;
    Payment pay2;
    int menu;
    while (menu != 0)
    {
        /* code */
        cout << "\n_MENU_\n[1]- Заполнить поля(ручной ввод)\n[2]- Заполнить поля(значениями поля другого экземпляра)\n";
        cout << "[3]- Вычисление начисленной суммы\n[4]- Вычисление удержанной суммы\n[5]- Вычисление выдоваймой суммы\n";
        cout << "[6]- Вывод полей на экран\n";
        cout << "Ваш выбор: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            pay.Read();
            break;
        case 2:
            pay2.Init("nickname", 15000.20, 30, 20, 28);
            cout << "Значение полей в копируемом экземпляре (pay2): ";
            pay2.Display();
            pay.Init(pay2);
            cout << "Теперь эти значения скопировались в оснавной экземпляр(pay): ";
            pay.Display();
            break;
        case 3:
            cout << "Сумма равна: " << pay.getAccrued();
            break;
        case 4:
            cout << "Сумма равна: " << pay.getWithheld();
            break;
        case 5:
            cout << "Сумма равна: " << pay.getPaymennt();
            break;
        case 6:
            try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
                pay.Display();
            }
            catch (int e) // обработчик исключений типа const char*
            {
                cout << "Error: " << e << '\n';
            }
            break;
        default:
            cout << " Не верный ввод!\n";
            break;
        }
    }
    return 0;
}