#include"head.h"

template <typename T>//定义函数模版，提供各种类型员工的录入信息功能

void append1(const char *filetxt)
{ 
	ofstream outstuf(filetxt,ios::app);//以追加的方式打开文件
    if(!outstuf)
    {
		cout<<"文件不存在，请先进行初始化！"<<endl;
		return;
	}
    T A;
    A.set();
    outstuf<<A;//向文件中写入数据
	cout<<endl;
    cout<<A.getname()<<"的信息录入成功！"<<endl<<endl;
    outstuf.close();//关闭文件
}

void append()
{
	while(1)
    {
		char choice;
        cout<<"请选择要录入哪类员工信息：\n\n"
            <<"1：小时工\n\n"
		    <<"2：计件工\n\n"
	        <<"3：月薪员工\n\n"
		    <<"Q：退出\n\n";
        cin>>choice;
		system("cls");
	    switch(choice)//功能选择，实例化函数模版，录入不同人员类型的个人信息
        {
		  case '1':append1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
		  case '2':append1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
		  case '3':append1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
		  case 'q':
		  case 'Q':return ;
		  default:cout<<"输入错误，请再输入\n\n";
		}
	}
}