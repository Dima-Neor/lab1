#include <iostream>
#include "payment.hh"
using namespace std;


int main()
{
    cout << "������ୠ� � 1 ��ਠ�� � 6 �믮����: �㫠⮢ ����਩\n";
    Payment pay;
    Payment pay2;
    int menu;
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
        pay2.Init ("nickname", 15000.20, 30, 20, 28);
        cout << "���祭�� ����� � �����㥬�� ������� (pay2): ";
        pay2.Display();
        pay.Init (pay2);
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
        pay.Display();
        break;
    default:
        cout << " �� ���� ����!\n";
        break;
    }
    return 0;
}