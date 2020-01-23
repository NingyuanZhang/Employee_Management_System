#include"head.h"

template<typename T>//函数模版，实现根据用户选择分别浏览各种类型员工信息的功能

void average1(const char *filetxt)
{ 
	employee *Employee[1000];//定义基类指针数组和基类指针
    int i=0,k,g,e,f;
	double total=0;
    char a[30],b[30],c[30];
	long d;
    ifstream instuf(filetxt,ios::in);//以读的方式打开文件
	if(!instuf) {cerr<<"打开文件失败，请先进行初始化！"<<endl; abort();}
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//读取一组数据
    {
		Employee[i]=new T(a,b,c,d,g,e,f);
	    i++;//累计该类员工的人数
	}
    for(k=0;k<i;k++) 
		{
			((T *)Employee[k])->earnings();//浏览员工工资信息
			total+=((T *)Employee[k])->earnings();
	    }
	cout<<"该类员工平均工资为："<<total/i<<endl;
}

void average2(const char *filetxt1,const char *filetxt2,const char *filetxt3)//实现浏览全体员工个人信息的功能
{ 
	employee *Employee[1000];//定义基类指针数组，基类指针
    int i=0,k,g,e,f;
	double total=0;
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
	for(k=0;k<i;k++) 
		{
			Employee[k]->earnings();//浏览员工工资信息
			total+=Employee[k]->earnings();
	    }
	cout<<"全体员工平均工资为："<<total/i<<endl;
}
void average()
{
	cout<<"请选择要计算平均工资的员工类型：\n\n"//进行功能选择
	  <<"1：小时工\n\n"
	  <<"2：计件工\n\n"
	  <<"3：月薪员工\n\n"
	  <<"4：全体员工\n\n"
	  <<"Q：退出\n\n";
  char m;
  cin>>m;
  system("cls"); 
  if(m=='1') {average1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");}//实例化函数模版
  if(m=='2') {average1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");}
  if(m=='3') {average1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");}
  if(m=='4') {average2("d:\\hourlyworkerbook.txt","d:\\pieceworkerbook.txt","d:\\monthlyworkerbook.txt");system("pause");system("cls");}
  else return;
  cout<<"人员平均工资输出完毕！"<<endl<<endl;
}
