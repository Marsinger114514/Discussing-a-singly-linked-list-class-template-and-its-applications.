#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
using namespace std;
void AdmissionTest()
{
    LinkList<School> uLink;
    School x_school;
    Node<School> *pU;
    Card x_card;
    char schoolname[80],name[80],admission[80],id[80],gender,str[80];                  //学校名，姓名，准考证号，身份证号，性别
    int choice;
    while(true)
    {
        cout << "\n请输入学校(请输入四位汉字，直接回车则退出)：";
        cin.getline(schoolname, 80);
        if(schoolname[0] == '\0'){
            cout << "退出录入程序。" << endl;
            break;
        }
        else{
            x_school.Set(schoolname);
            cout << "设置学校名称为: " << x_school << endl;
        }

        pU = uLink.Locate(string(x_school), true);

        if(pU==nullptr)
        {
            cout << "学校姓名输入错误！" << endl;
            continue;
        }

        while(true)
        {
            cout << endl;
            uLink.CurData().Show(cout);
            cout << "0 -- 录入准考证数据" << endl;
            cout << "1 -- 查询" << endl;
            cout << "2 -- 返回" << endl;
            cout << "请选择：";
            choice = getche() - '0';
            cout << endl;
            if(choice == 2) break;
            switch (choice)
            {
                case 0:
                    cout << "请输入（学生姓名 学生性别 学生准考证号 学生身份证号）: ";
                    cin.ignore();  // 忽略缓冲区中的换行符
                    cin >> name >> gender >> admission >> id;
                    cin.ignore();  // 忽略输入后的换行符
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                    break;
                case 1:
                    cout << uLink.CurData() << endl; break;
                default:
                    cout << "无效选项，请重新选择。" << endl;
                    break;
            }
        }
    }
    cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}