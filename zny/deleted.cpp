#include"head.h"

void deleted1(const char*filetxt)//ģ�溯�����ṩɾ����������Ա����Ϣ�Ĺ���
{
	char s[200],a[30],b[30],c[30];
	long d=0;
	int g,e,f,t=0;
    ifstream stuf(filetxt,ios::in);//�Զ��ķ�ʽ���ļ�
    if(!stuf)
    { 
		cout<<"�ļ������ڣ����Ƚ��г�ʼ����"<<endl;
		return;
	}
    char k[30];
    cout<<"������Ҫɾ���˵�������";
    cin>>k;
    ofstream temp("d:\\temp.txt",ios::out);//��Ϊ�м��ı��ļ�����ʱ���Ա����Ϣ
    while(!stuf.eof())
    { 
		stuf.getline(s,200);
        temp<<s<<endl;//��ȡһ�����ݣ������м����
    }
    temp.close();
    stuf.close();
    ofstream stuf2(filetxt,ios::out);//��д�ķ�ʽ��ͨѶ¼�ļ�
    ifstream temp1("d:\\temp.txt",ios::in);//�Զ��ķ�ʽ���м��ļ�
    while(temp1>>a>>b>>c>>d>>g>>e>>f)
		//��ȡһ������
       if(strcmp(a,k)==0)//�ж��Ƿ���Ҫɾ������
	   { 
		   t++;
	       char m;
           cout<<endl<<"ȷ��Ҫɾ��"<<a<<"�ĸ�����Ϣ����Y/N)\n";
	       cin>>m;
	       if(m=='y'||m=='Y') 
			   cout<<endl<<a<<"�ĸ�����Ϣɾ���ɹ���"<<endl<<endl;
	       else 
			   stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//���ļ���д��һ������
       }
       else 
		   stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//���ļ���д��һ������
    if(t==0)
	{ 
		cout<<endl;
		cout<<"������Ա���в����ڴ��ˣ�\n\n";
	}
}

void deleted()
{ 
	char choice;
    cout<<"��ѡ��Ҫɾ������Ա����Ϣ��\n\n"
	    <<"1��Сʱ��\n\n"
        <<"2���Ƽ���\n\n"
	    <<"3����нԱ��\n\n"
	    <<"Q���˳�\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//����ѡ��ʵ��������ģ�棬ɾ����ͬ����Ա����Ϣ
    { 
	case '1':deleted1("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':deleted1("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
	case '3':deleted1("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
	case 'q':
	case 'Q':return ;
	default:cout<<"���������������\n\n";
    }
}