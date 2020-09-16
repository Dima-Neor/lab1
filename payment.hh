#pragma once
#include <string>

using uInt = unsigned int; 
using namespace std;

class Payment
{
private:
    string name;
    double salary;     //оклад
    uInt percent;    //процент надбавки
    double tax;        //подоходный налог
    uInt spentDays;   //количество отработанных дней
    uInt workingDays; //кол-во рабочих дней
    double accrued;    //начислено
    double withheld; //удерханно
    void calculeteTax() noexcept;
    void calculeteAccrued() noexcept;
    void calculeteWittheld() noexcept;

public:

    void setName(string PaymentName) noexcept;
    void setSalary(double PaymentSalary);
    void setPercent(uInt PaymentPercent);
    void setSpeentDays(uInt PaymentSpeentDays);
    void setWorkingDays(uInt PaymentWorkingDays);

    void Init(string PaymentName, double PaymentSalary, uInt PaymentPercent, uInt PaymentSpeentDays, uInt PaymentWorkingDays) noexcept;
    void Init(Payment payment) noexcept;

    double getAccrued() noexcept;
    double getWithheld() noexcept;
    double getPaymennt() noexcept;

    string getName() const;
    double getSalary() const;
    uInt getPercent() const;
    double getTax() const;
    uInt getSpentDays() const;
    uInt getWorkingDays() const;
    string toSring() noexcept;

    void Read () noexcept;
    void Display () noexcept;
};