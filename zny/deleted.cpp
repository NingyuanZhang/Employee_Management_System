#include"head.h"

void deleted1(const char*filetxt)//模版函数，提供删除各种类型员工信息的功能
{
	char s[200],a[30],b[30],c[30];
	long d=0;
	int g,e,f,t=0;
    ifstream stuf(filetxt,ios::in);//以读的方式打开文件
    if(!stuf)
    { 
		cout<<"文件不存在，请先进行初始化！"<<endl;
		return;
	}
    char k[30];
    cout<<"请输入要删除人的姓名：";
    cin>>k;
    ofstream temp("d:\\temp.txt",ios::out);//作为中间文本文件，暂时存放员工信息
    while(!stuf.eof())
    { 
		stuf.getline(s,200);
        temp<<s<<endl;//读取一组数据，存入中间变量
    }
    temp.close();
    stuf.close();
    ofstream stuf2(filetxt,ios::out);//以写的方式打开通讯录文件
    ifstream temp1("d:\\temp.txt",ios::in);//以读的方式打开中间文件
    while(temp1>>a>>b>>c>>d>>g>>e>>f)
		//读取一组数据
       if(strcmp(a,k)==0)//判断是否是要删除的人
	   { 
		   t++;
	       char m;
           cout<<endl<<"确认要删除"<<a<<"的个人信息？（Y/N)\n";
	       cin>>m;
	       if(m=='y'||m=='Y') 
			   cout<<endl<<a<<"的个人信息删除成功！"<<endl<<endl;
	       else 
			   stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//向文件中写入一组数据
       }
       else 
		   stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//向文件中写入一组数据
    if(t==0)
	{ 
		cout<<endl;
		cout<<"该类型员工中不存在此人！\n\n";
	}
}

void deleted()
{ 
	char choice;
    cout<<"请选择要删除哪类员工信息：\n\n"
	    <<"1：小时工\n\n"
        <<"2：计件工\n\n"
	    <<"3：月薪员工\n\n"
	    <<"Q：退出\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//功能选择，实例化函数模版，删除不同类型员工信息
    { 
	case '1':deleted1("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':deleted1("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
	case '3':deleted1("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
	case 'q':
	case 'Q':return ;
	default:cout<<"输入错误，请再输入\n\n";
    }
}