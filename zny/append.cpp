#include"head.h"

template <typename T>//���庯��ģ�棬�ṩ��������Ա����¼����Ϣ����

void append1(const char *filetxt)
{ 
	ofstream outstuf(filetxt,ios::app);//��׷�ӵķ�ʽ���ļ�
    if(!outstuf)
    {
		cout<<"�ļ������ڣ����Ƚ��г�ʼ����"<<endl;
		return;
	}
    T A;
    A.set();
    outstuf<<A;//���ļ���д������
	cout<<endl;
    cout<<A.getname()<<"����Ϣ¼��ɹ���"<<endl<<endl;
    outstuf.close();//�ر��ļ�
}

void append()
{
	while(1)
    {
		char choice;
        cout<<"��ѡ��Ҫ¼������Ա����Ϣ��\n\n"
            <<"1��Сʱ��\n\n"
		    <<"2���Ƽ���\n\n"
	        <<"3����нԱ��\n\n"
		    <<"Q���˳�\n\n";
        cin>>choice;
		system("cls");
	    switch(choice)//����ѡ��ʵ��������ģ�棬¼�벻ͬ��Ա���͵ĸ�����Ϣ
        {
		  case '1':append1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
		  case '2':append1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
		  case '3':append1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
		  case 'q':
		  case 'Q':return ;
		  default:cout<<"���������������\n\n";
		}
	}
}