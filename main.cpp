#include <iostream>
#include "payment.hh"
using namespace std;


int main()
{
    cout << "ЛАбараторная № 1 Вариант № 6 Выполнил: Булатов Дмитрий\n";
    Payment pay;
    Payment pay2;
    int menu;
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
        pay2.Init ("nickname", 15000.20, 30, 20, 28);
        cout << "Значение полей в копируемом экземпляре (pay2): ";
        pay2.Display();
        pay.Init (pay2);
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
        pay.Display();
        break;
    default:
        cout << " Не верный ввод!\n";
        break;
    }
    return 0;
}