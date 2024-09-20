#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
#include <string>
using namespace std;

void AdmissionTest()
{
    LinkList<School> uLink;          //定义链表和结点
    School x_school;
    Node<School> *pU;
    Card x_card;
    int p;
    string schoolname, name, admission, id, str;
    int i;
    string gender;                  // 学校名，姓名，准考证号，身份证号，性别
    int choice;                     //用于选择行为
    bool continueMainLoop = true;  //定义一个变量用于控制循环
                 //定义一个变量用于控制节点增加

    while (continueMainLoop)
    {

        cout << "\n请输入学校(请输入汉字，直接回车则退出)：";
        getline(cin, schoolname);

        if (schoolname.empty()) { // 改成检查字符串是否为空
            continueMainLoop = false; // 设置为 false 表示退出循环
            break;
        }
        else {
            x_school.Set(schoolname);
            cout << "学校名称为: " << schoolname << endl;
            bool addOrNot = true;
            for (pU = uLink.GoTop(),i=1; pU != nullptr; pU = uLink.Skip(),i++) {
                if(schoolname==pU->data.schoolname) {
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

         pU = uLink.Locate(string(x_school), true);//找到结点的位置

        if (pU == nullptr)
        {
            cout << "学校名称输入错误！" << endl;
            continue;
        }

        bool continueSubLoop = true;

        while (continueSubLoop)
        {
            cout << endl;
            uLink.CurData().Show(cout);
            cout << "1 -- 录入准考证数据" << endl;
            cout << "2 -- 查询该校考生信息" << endl;
            cout << "3 -- 查询所有考生信息" << endl;
            cout << "4 -- 排序该校考生信息" << endl;
            cout << "0 -- 返回" << endl;
            cout << "请选择：";
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
                    cout << "请输入（学生姓名 学生性别 学生准考证号（8位） 学生身份证号（8位））: ";
                    cin >> name >> gender >> admission >> id;
                    cin.ignore(); 
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                }
                break;
            case 2:
                cout << uLink.CurData() << endl; //输出
                break;
            case 3:
                {
                    cout << "所有考生信息：" << endl;
                    p = uLink.CurPos();
                    for (pU = uLink.GoTop(),i=1; ; pU = uLink.Skip(),i++)   //循环遍历输出
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
                    {     //排序操作
                   cout << "请选择排序方式（“1”：升序，“2”：降序）"<< endl;
                   int ascending_num = getche() - '0';
                   bool ascending = (ascending_num == 1);
                   uLink.CurData().SortCards(x_card,ascending);
                    cout << uLink.CurData() << endl;
               }
                break;
            default:
                cout << "无效的选择，请重新输入！" << endl;
                break;
            }
        }
    }

    cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}

