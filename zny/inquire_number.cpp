#include"head.h"

template<typename T>//函数模版，实现查询各不同类型员工个人信息的功能

void inquire_number1(const char *filetxt)
{ 
	char a[30],b[30],c[30];
    long d=0;
	int g,e,f,t=0;
    ifstream instuf(filetxt,ios::in);//以读的方式打开文件
    if(!instuf)
    {
		cout<<"文件不存在，请先进行初始化！"<<endl;
		return;
	}
    long s;
    cout<<"请输入被查询人的工号：";
    cin>>s;
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//读取一组数据
    {   if(s==d)//判断是否是被查询人
       {
		   t++;
           cout<<endl<<"查询信息如下："<<endl<<endl;
           T A(a,b,c,d,g,e,f);
	       A.print();
		   cout<<endl;
       }
    }    
	if(t==0) 
	{ 
		cout<<endl<<"该类型员工中不存在此人！"<<endl<<endl;
		return;
	}
}

void inquire_number()
{
	char choice;
    cout<<"请选择要查询哪类人员信息：\n\n"
	    <<"1：小时工\n\n"
	    <<"2：计件工\n\n"
	    <<"3：月薪员工\n\n"
	    <<"Q：退出\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//功能选择，实例化函数模版，查询不同类型员工个人信息
    { 
	case '1':inquire_number1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':inquire_number1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
	case '3':inquire_number1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
	case 'q':
	case 'Q':return ;
	default:cout<<"输入错误，请再输入\n\n";
    }
}