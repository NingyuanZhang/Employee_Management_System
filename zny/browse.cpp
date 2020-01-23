#include"head.h"

template<typename T>//函数模版，实现根据用户选择分别浏览各种类型员工信息的功能

void browse1(const char *filetxt,int m)
{ 
	employee *Employee[1000],*temp;//定义基类指针数组和基类指针
    int i=0,k,work,g,e,f;
    char a[30],b[30],c[30];
	long d;
    ifstream instuf(filetxt,ios::in);//以读的方式打开文件
	if(!instuf) {cerr<<"打开文件失败，请先进行初始化！"<<endl; abort();}
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//读取一组数据
    {
		Employee[i]=new T(a,b,c,d,g,e,f);
	    i++;//累计该类员工人数
	}
    switch(m)
    { 
	case 1://按姓名排序
    { 
		for(int pass=1;pass<i;pass++)
        {  
			work=1;
            for(k=0;k<i-pass;k++)
	        if(strcmp(Employee[k]->getname(),Employee[k+1]->getname())>0)
	        { 
				temp=Employee[k];
				Employee[k]=Employee[k+1];
				Employee[k+1]=temp;
				work=0;
			}
	        if(work) break;
		}
	}break;

    case 2://按工号排序
    { 
		for(int pass=1;pass<i;pass++)
        { 
			work=1;
            for(k=0;k<i-pass;k++)
	        if(Employee[k]->getnumber()>Employee[k+1]->getnumber())
	        {
				temp=Employee[k];
				Employee[k]=Employee[k+1];
				Employee[k+1]=temp;
				work=0;
			}
			if(work) break;
		}
	}break;

    case 3:break;//不排序
	}
    for(k=0;k<i;k++) 
		{
			((T *)Employee[k])->print();//浏览员工信息
			cout<<endl;
	}
}

void browse2(int m)//实现浏览全体员工个人信息的功能
{ 
	employee *Employee[1000],*temp;//定义基类指针数组，基类指针
    int i=0,k,work,g,e,f;
    char a[30],b[30],c[40];
	long d;
    ifstream instuf1("d:\\hourlyworkerbook.txt",ios::in);//以读的方式打开文件
    ifstream instuf2("d:\\pieceworkerbook.txt",ios::in);
    ifstream instuf3("d:\\monthlyworkerbook.txt",ios::in);
    if(!instuf1||!instuf2||!instuf3) 
	   cout<<"打开文件失败，请先进行初始化！"<<endl;
    while(instuf1>>a>>b>>c>>d>>g>>e>>f)//读一组数据
    {
		Employee[i]=new hourlyworker(a,b,c,d,g,e,f);
        i++;//统计全体员工人数
    }
    while(instuf2>>a>>b>>c>>d>>g>>e>>f)
    {
		Employee[i]=new pieceworker(a,b,c,d,g,e,f);
	    i++;
    }
    while(instuf3>>a>>b>>c>>d>>g>>e>>f)
    { 
		Employee[i]=new monthlyworker(a,b,c,d,g,e,f);
	    i++;
    }
    switch(m)
    { 
	case 1://按姓名排序
    { 
		for(int pass=1;pass<i;pass++)
        { 
			work=1;
            for(k=0;k<i-pass;k++)
	        if(strcmp(Employee[k]->getname(),Employee[k+1]->getname())>0)
	        { 
				temp=Employee[k];
				Employee[k]=Employee[k+1];
				Employee[k+1]=temp;
				work=0;
			}
	        if(work) break;
        }
    }break;

    case 2://按工号排序
    { 
		for(int pass=1;pass<i;pass++)
		{ 
			work=1;
            for(k=0;k<i-pass;k++)
	        if(Employee[k]->getnumber()>Employee[k+1]->getnumber())
	        { 
				temp=Employee[k];
				Employee[k]=Employee[k+1];
				Employee[k+1]=temp;
				work=0;
			}

	  if(work) break;
      }
    }break;

    case 3:break;//不排序
  }
  for(k=0;k<i;k++) 
  { 
	  Employee[k]->print();cout<<"\n\n";
  }//浏览全体员工信息
}

void browse()
{   
  cout<<"请选择要浏览的员工类型，以及浏览的方式（用空格隔开）：\n\n"//进行功能选择
	  <<"1：小时工\n\n"
	  <<"2：计件工\n\n"
	  <<"3：月薪员工\n\n"
	  <<"4：全体人员\n\n"
	  <<"Q：退出\n\n"
	  <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
	  <<"A：按照姓名排序输出\n\n"
	  <<"B：按照工号排序输出\n\n"
	  <<"C：无格式输出\n\n"
	  <<"Q：退出\n\n";
  char m,n;
  while(1)
  {
	  cin>>m;
	  if(m>='1'&&m<='4'||m=='Q'||m=='q')
		  break;
	  else 
		  cout<<"输入错误！请重新输入！"<<endl;
  }
  while(1)
  {
	  cin>>n;
	  if(n>='A'&&n<='C'||n>='a'&&n<='c'||n=='Q'||n=='q')
		  break;
	  else
		  cout<<"输入错误！请重新输入！"<<endl;
  }
  system("cls"); 
  if((m=='1'||m=='2'||m=='3')&&(n=='A'||n=='a'||n=='B'||n=='b'||n=='C'||n=='c'))
  if(m=='1'&&(n=='A'||n=='a')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",1);system("pause");system("cls");}//实例化函数模版
  if(m=='1'&&(n=='B'||n=='b')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",2);system("pause");system("cls");}
  if(m=='1'&&(n=='C'||n=='c')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",3);system("pause");system("cls");}
  if(m=='2'&&(n=='A'||n=='a')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",1);system("pause");system("cls");}
  if(m=='2'&&(n=='B'||n=='b')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",2);system("pause");system("cls");}
  if(m=='2'&&(n=='C'||n=='c')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",3);system("pause");system("cls");}
  if(m=='3'&&(n=='A'||n=='a')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",1);system("pause");system("cls");}
  if(m=='3'&&(n=='B'||n=='b')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",2);system("pause");system("cls");}
  if(m=='3'&&(n=='C'||n=='c')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",3);system("pause");system("cls");}
  if(m=='4'&&(n=='A'||n=='a')) {browse2(1);system("pause");system("cls");}//调用函数
  if(m=='4'&&(n=='B'||n=='b')) {browse2(2);system("pause");system("cls");}
  if(m=='4'&&(n=='C'||n=='c')) {browse2(3);system("pause");system("cls");}
}
