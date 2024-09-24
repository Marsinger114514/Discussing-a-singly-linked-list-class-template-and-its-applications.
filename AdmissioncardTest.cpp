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
    int p;
    string schoolname, name, admission, id, str;
    int i;
    string gender;                  // ѧУ����������׼��֤�ţ����֤�ţ��Ա�
    int choice;                     //����ѡ����Ϊ
    bool continueMainLoop = true;  //����һ���������ڿ���ѭ��
                 //����һ���������ڿ��ƽڵ�����

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
            cout << "ѧУ����Ϊ: " << schoolname << endl;
            bool addOrNot = true;
            for (pU = uLink.GoTop(),i=1; pU != nullptr; pU = uLink.Skip(),i++) {
                if(schoolname==x_school.ReturnSchoolname(pU)) {
                    addOrNot=false;
                    break;
                }
                if(i==uLink.NumNodes())
                    break;
            }
            if(addOrNot) {
                uLink.Append(x_school);
            }
        }

         pU = uLink.Locate(string(x_school), true);//�ҵ�����λ��

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
            cout << "4 -- �����У������Ϣ" << endl;
            cout << "5 -- ɾ����ǰ���" << endl;
            cout << "6 -- �޸ĵ�ǰ���" << endl;
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
                    p = uLink.CurPos();
                    for (pU = uLink.GoTop(),i=1; ; pU = uLink.Skip(),i++)   //ѭ���������
                    {
                       cout << uLink.CurData() << endl;
                        if(i==uLink.NumNodes())
                            break;
                    }
                    for (pU = uLink.GoTop();p>0;pU = uLink.Skip(),p--)
                        ;
                }
                break;
            case 4:
                {//�������
                    cout << "��ѡ������ʽ������׼��֤������   ��1�������򣬡�2��������"<< endl;
                    int ascending_num = getche() - '0';
                    bool ascending = (ascending_num == 1);
                    uLink.CurData().SortCards(x_card,ascending);
                    cout << uLink.CurData() << endl;
                }
                break;
            case 5:
                {
                    cout << "������׼��֤��( ��׼��֤��ɾ�� ��: ";        // ��׼��֤��ɾ��
                    string admissionToDelete;
                    cin >> admissionToDelete;

                    bool cardFound = false;
                    for (pU = uLink.GoTop(); pU != nullptr; pU = uLink.Skip()) {
                        if (pU->data.RemoveCardByAdmission(admissionToDelete)) {            // ����ѧУ��ɾ��׼��֤����
                            cout << "׼��֤�� " << admissionToDelete << " �Ŀ�����Ϣ��ɾ����" << endl;
                            cardFound = true;
                            break;
                            }
                        }

                    if (!cardFound) {
                        cout << "δ�ҵ�׼��֤��Ϊ " << admissionToDelete << " �Ŀ�����Ϣ��" << endl;
                        }
                }
                break;
            case 6:
                {
                    // �޸ĵ�ǰ���
                    cout << "��ѡ���޸����ͣ�1: �޸�ѧУ��Ϣ��2: �޸�׼��֤��Ϣ����";
                    int modifyChoice = getche() - '0';
                    cout << endl;
                    if (modifyChoice == 1) {
                        // �޸�ѧУ��Ϣ
                        cout << "�������µ�ѧУ����: ";
                        getline(cin, schoolname);
                        uLink.CurData().Set(schoolname);
                        cout << "��ǰѧУ�������޸�Ϊ: " << schoolname << endl;
                    } else if (modifyChoice == 2) {
                        // �޸�׼��֤��Ϣ
                        cout << "������Ҫ�޸ĵ�׼��֤��: ";
                        cin >> admission;
                        cin.ignore();
                        Card* card = uLink.CurData().FindCardByAdmission(admission);
                        if (card != nullptr) {
                            cout << "�������µ���Ϣ��ѧ������ ѧ���Ա� ѧ��׼��֤�ţ�8λ�� ѧ�����֤�ţ�8λ����: ";
                            cin >> name >> gender >> admission >> id;
                            card->Set(name, gender, admission, id);
                            cout << "׼��֤��Ϣ�Ѹ��£�" << endl;
                        } else {
                            cout << "�Ҳ�����׼��֤�ŵ�ѧ����" << endl;
                        }
                    } else {
                        cout << "��Ч��ѡ��" << endl;
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

