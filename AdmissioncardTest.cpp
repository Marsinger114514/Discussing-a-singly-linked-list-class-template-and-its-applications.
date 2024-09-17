#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
#include <string>
using namespace std;

void AdmissionTest()
{
    LinkList<School> uLink;          //��������ͽ��
    School x_school;
    Node<School> *pU;
    Card x_card;
    string schoolname, name, admission, id, str;
    string gender;                  // ѧУ����������׼��֤�ţ����֤�ţ��Ա�
    int choice;                     //����ѡ����Ϊ
    bool continueMainLoop = true;   //����һ���������ڿ���ѭ��

    while (continueMainLoop)
    {
        cout << "\n������ѧУ(�����뺺�֣�ֱ�ӻس����˳�)��";
        getline(cin, schoolname);

        if (schoolname.empty()) { // �ĳɼ���ַ����Ƿ�Ϊ��
            continueMainLoop = false; // ����Ϊ false ��ʾ�˳�ѭ��
            break;
        }
        else {
            x_school.Set(schoolname);
            cout << "����ѧУ����Ϊ: " << schoolname << endl;
            uLink.Append(x_school);
        }

        pU = uLink.Locate(string(x_school), true);  //�ҵ�����λ��

        if (pU == nullptr)
        {
            cout << "ѧУ�����������" << endl;
            continue;
        }

        bool continueSubLoop = true;

        while (continueSubLoop)
        {
            cout << endl;
            uLink.CurData().Show(cout);
            cout << "1 -- ¼��׼��֤����" << endl;
            cout << "2 -- ��ѯ��У������Ϣ" << endl;
            cout << "3 -- ��ѯ���п�����Ϣ" << endl;
            cout << "0 -- ����" << endl;
            cout << "��ѡ��";
            choice = getche() - '0';
            cout << endl;

            if (choice == 0)
            {
                continueSubLoop = false;
                continue;
            }

            switch (choice)
            {
            case 1:
                {
                    cout << "�����루ѧ������ ѧ���Ա� ѧ��׼��֤�ţ�8λ�� ѧ�����֤�ţ�8λ����: ";
                    cin >> name >> gender >> admission >> id;
                    cin.ignore(); 
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                }
                break;
            case 2:
                cout << uLink.CurData() << endl; //���
                break;
            case 3:
                {
                    cout << "���п�����Ϣ��" << endl;
                    for (pU = uLink.GoTop(); pU != nullptr; pU = uLink.Skip())   //ѭ���������
                    {
                       cout << uLink.CurData() << endl;
                    }
                }
                break;
            default:
                cout << "��Ч��ѡ�����������룡" << endl;
                break;
            }
        }
    }

    cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}

