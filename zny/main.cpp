#include"head.h"
int main()
{ p:cout<<"〓〓〓〓〓〓〓〓  ☆  欢迎进入员工个人及工资信息管理系统   ☆  〓〓〓〓〓〓〓〓\n\n"//通信录系统主界面
       <<"〓〓〓〓〓〓〓〓               请选择您的用户类型              〓〓〓〓〓〓〓〓\n\n"
       <<"******************                1.普通员工                 ******************\n\n"
	   <<"******************                2.管理人员                 ******************\n\n"
	   <<"******************                Q.退出                     ******************\n\n"
	   <<"〓〓〓〓〓〓〓★★★            ★★★★★★★             ★★★〓〓〓〓〓〓〓\n\n";
	char choice;
	cin>>choice;
switch(choice)
{ case'1':
  system("cls");
  {m: cout<<"*************               请输入操作选择                       **************\n\n" 
		  <<"       ★  ☆         1：按姓名查询员工信息                      ☆  ★        \n\n"
		  <<"       ★  ☆         2：按工号查询员工信息                      ☆  ★        \n\n"
		  <<"       ★  ☆         3：浏览员工信息（基本信息和工资情况）      ☆  ★        \n\n"
		  <<"       ★  ☆         4：员工平均工资                            ☆  ★        \n\n"
		  <<"       ★  ☆         Q：退出                                    ☆  ★        \n\n";
    char choiceA;
    cin>>choiceA;
	system("cls");
	switch(choiceA) //进行功能选择
	{ case'1':inquire_name();goto m;
	  case'2':inquire_number();goto m;
	  case'3':browse();goto m;
	  case'4':average();goto m;
	  case'q':
	  case'Q':goto p;
	  default:cout<<"输入错误，请再输入\n\n";
	}
  };system("pause");system("cls");
  case'2':
  { system("cls");
    q:cout<<"◆◇请输入密码：";
    char *a="111111";char *s=new char[30];
	cin>>s;
	if(strcmp(s,a)==0)
	{system("cls");
     n:cout<<"*************              请输入操作选择：                      **************\n\n" 
           <<"       ★  ☆         1：录入员工信息                            ☆  ★        \n\n"
		   <<"       ★  ☆         2：修改员工信息                            ☆  ★        \n\n"
		   <<"       ★  ☆         3：删除员工信息                            ☆  ★        \n\n"
		   <<"       ★  ☆         4：按姓名查询员工信息                      ☆  ★        \n\n"
		   <<"       ★  ☆         5：按工号查询员工信息                      ☆  ★        \n\n"
		   <<"       ★  ☆         6：浏览员工信息（基本信息和工资情况）      ☆  ★        \n\n"
		   <<"       ★  ☆         7：员工平均工资                            ☆  ★        \n\n"
		   <<"       ★  ☆         0：初始化                                  ☆  ★        \n\n"
		   <<"       ★  ☆         Q：退出                                    ☆  ★        \n\n";
     char choiceA;
     cin>>choiceA;
	 system("cls");
	 switch(choiceA) //进行功能选择
	 { case'1':append();goto n;
   	   case'2':modify();goto n;
	   case'3':deleted();goto n;
	   case'4':inquire_name();goto n;
	   case'5':inquire_number();goto n;
	   case'6':browse();goto n;
	   case'7':average();goto n;
	   case'0':initial();goto n;
	   case'q':
	   case'Q':goto p;
	   default:cout<<"输入错误请再输入\n\n";
	 }
	}
	else {cout<<"密码错误！请重新选择："<<endl;
	      char m;
	      cout<<"1.重新输入密码"<<endl<<"2.返回首界面"<<endl;
	      cin>>m;
		  switch(m)
			  {case'1':system("cls");goto q;
   	           case'2':system("cls");goto p;};
	     };
  };system("pause");system("cls");
  case'q':
  case'Q': system("cls");
	       cout<<"△■※※※※※※※※※※※※※※■△\n\n"
			   <<"                                    \n\n"
			   <<"    已成功退出系统。欢迎再次使用！  \n\n"
	           <<"                                    \n\n"   
		       <<"▲□※※※※※※※※※※※※※※□▲\n\n";
		   system("pause");return 0;
};
}