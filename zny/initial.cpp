#include"head.h"
void initial()
{ cout<<"���ļ����ڣ���ɾ��ԭ�����ݣ�Ҫ�����ļ���ʼ���𣿣�Y/N��\n";
  char answer;
  cin>>answer;
  if(answer=='y'||answer=='Y')//��ʼ���ļ�
  { 
	  ofstream outstuf1("d:\\hourlyworkerbook.txt",ios::trunc);
      ofstream outstuf2("d:\\pieceworkerbook.txt",ios::trunc);
      ofstream outstuf3("d:\\monthlyworkerbook.txt",ios::trunc);
	  cout<<"�ļ��Ѿ���ʼ����\n\n";
	  outstuf1.close();
	  outstuf2.close();
	  outstuf3.close();
  }
  else  
	  cout<<"ȡ��������\n\n";
  system("pause");system("cls");
  return;
}