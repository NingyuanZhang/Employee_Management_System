#include"head.h"

template<typename T>//����ģ�棬ʵ�ֲ�ѯ��ͬ����Ա����Ϣ�Ĺ���

void inquire_name1(const char *filetxt)
{ 
	char a[30],b[30],c[30];
    long d=0;
	int g,e,f,t=0;
    ifstream instuf(filetxt,ios::in);//�Զ��ķ�ʽ���ļ�
    if(!instuf)
    {
		cout<<"�ļ������ڣ����Ƚ��г�ʼ����"<<endl;
		return;
	}
    char s[30];
    cout<<"�����뱻��ѯ�˵�������";
    cin>>s;
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//��ȡһ������
    {   if(strcmp(s,a)==0)//�ж��Ƿ��Ǳ���ѯ��
       {
		   t++;
           cout<<endl<<"��ѯ��Ϣ���£�"<<endl<<endl;
           T A(a,b,c,d,g,e,f);
	       A.print();
		   cout<<endl;
       }
    }
	if(t==0) 
	{ 
		cout<<endl<<"������Ա���в����ڴ��ˣ�"<<endl<<endl;
		return;
	}
}

void inquire_name( )
{
	char choice;
    cout<<"��ѡ��Ҫ��ѯ������Ա��Ϣ��\n\n"
	    <<"1��Сʱ��\n\n"
	    <<"2���Ƽ���\n\n"
	    <<"3����нԱ��\n\n"
	    <<"Q���˳�\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//����ѡ��ʵ��������ģ�棬��ѯ��ͬ����Ա��������Ϣ
    { 
	case '1':inquire_name1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':inquire_name1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
	case '3':inquire_name1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
	case 'q':
	case 'Q':return ;
	default:cout<<"���������������\n\n";
    }
}