#include"head.h"
void initial()
{ cout<<"若文件存在，将删除原有数据，要进行文件初始化吗？（Y/N）\n";
  char answer;
  cin>>answer;
  if(answer=='y'||answer=='Y')//初始化文件
  { 
	  ofstream outstuf1("d:\\hourlyworkerbook.txt",ios::trunc);
      ofstream outstuf2("d:\\pieceworkerbook.txt",ios::trunc);
      ofstream outstuf3("d:\\monthlyworkerbook.txt",ios::trunc);
	  cout<<"文件已经初始化。\n\n";
	  outstuf1.close();
	  outstuf2.close();
	  outstuf3.close();
  }
  else  
	  cout<<"取消操作。\n\n";
  system("pause");system("cls");
  return;
}