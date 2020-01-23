#include"head.h"

template<typename T>//模版函数，提供修改各种通信录个人信息的功能

void modify1(const char*filetxt)
{
	char s[200],a[30],b[30],c[30];
	long d=0;
	int g,e,f,t=0;
	ifstream stuf(filetxt,ios::in);//以读的方式打开文件
	if(!stuf)
	{
		cout<<"文件不存在，请先进行初始化！"<<endl<<endl;
		return;
	}
	char k[30];
	cout<<"请输入要修改人的姓名：";
	cin>>k;
	ofstream temp("d:\\temp.txt",ios::out);//定义中间文本文件，暂时存放员工信息
	while(!stuf.eof())
	{
		stuf.getline(s,200);
		temp<<s<<endl;//向中间文件中存入信息
	}
	temp.close();
	stuf.close();
	ofstream stuf2(filetxt,ios::out);//以写的方式打开文件
	ifstream temp1("d:\\temp.txt",ios::in);//以读的方式打开中间文件
	while(!temp1.eof())
	{
		while(temp1>>a>>b>>c>>d>>g>>e>>f)//读入一组数据
			if(strcmp(a,k)==0)//判断是否是需要修改信息的人员
			{
				t++;
				T A(a,b,c,d,g,e,f);
				A.print();
				char m;
				cout<<"确认要修改上述个人信息？（Y/N)\n";
				cin>>m;
				if(m=='y'||m=='Y')
				{
					char p[30],q[30];
					long r;
					int h,s,t;
					cout<<"请按提示输入相关信息：\n";
					cout<<"\n年龄：";
					cin>>h;
					cout<<"\n电话：";
					cin>>p;
					cout<<"\n工号：";
					cin>>r;
					cout<<"\n所属部门：";
					cin>>q;
					cout<<"\n每小时薪金/单件薪金/月基本工资：";
					cin>>s;
					cout<<"\n月工时/月工件数/该月奖金:";
					cin>>t;
					T B(a,p,q,r,h,s,t);
					stuf2<<B;
					cout<<endl;
					cout<<a<<"的个人信息修改成功！"<<endl<<endl;
				}
				else stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//向文件中写入一组数据
			}
			else stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//向文件中写入一组数据
	}
	if(t==0)
	{
		cout<<"该类型员工中不存在此人！\n\n";
	}
}

void modify()
{
	char choice;
	cout<<"请选择要修改哪类员工信息：\n\n"
	    <<"1：小时工\n\n"
        <<"2：计件工\n\n"
	    <<"3：月薪员工\n\n"
	    <<"Q：退出\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//功能选择，实例化函数模版，修改不同类型员工的信息
    { 
	case '1':modify1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':modify1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
    case '3':modify1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
    case 'q':
    case 'Q':return ;
	default:cout<<"输入错误，请再输入\n\n";
  }
}