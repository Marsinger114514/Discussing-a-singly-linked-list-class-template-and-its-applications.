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
    char schoolname[80],name[80],admission[80],id[80],str[80];
    char gender;                  //学校名，姓名，准考证号，身份证号，性别
    int choice;
    while(true)
    {
        cout << "\n请输入学校(请输入四位汉字，直接回车则退出)：";
        cin.getline(schoolname, 80);
        if (schoolname[0] == '\0') {
            cout << "退出录入程序。" << endl;
            break;
        }
        else{
            x_school.Set(schoolname);
            cout << "设置学校名称为: "<< schoolname << endl;
            uLink.Append(x_school);
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
            cout << "1 -- 录入准考证数据" << endl;
            cout << "2 -- 查询" << endl;
            cout << "0-- 返回" << endl;
            cout << "请选择：";
            choice = getche() - '0';
            cout << endl;
            if(choice <= 0) break;
            switch (choice)
            {
                case 1:
                    cout << "请输入（学生姓名 学生性别 学生准考证号（8位） 学生身份证号（8位））: ";
                    cin >> name >> gender >> admission >> id;
                    cin.getline(str, 80);
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                    break;
                case 2:
                    cout << uLink.CurData() << endl; break;
            }
        }
    }
    wcout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}