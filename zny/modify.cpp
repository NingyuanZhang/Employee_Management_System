#include"head.h"

template<typename T>//ģ�溯�����ṩ�޸ĸ���ͨ��¼������Ϣ�Ĺ���

void modify1(const char*filetxt)
{
	char s[200],a[30],b[30],c[30];
	long d=0;
	int g,e,f,t=0;
	ifstream stuf(filetxt,ios::in);//�Զ��ķ�ʽ���ļ�
	if(!stuf)
	{
		cout<<"�ļ������ڣ����Ƚ��г�ʼ����"<<endl<<endl;
		return;
	}
	char k[30];
	cout<<"������Ҫ�޸��˵�������";
	cin>>k;
	ofstream temp("d:\\temp.txt",ios::out);//�����м��ı��ļ�����ʱ���Ա����Ϣ
	while(!stuf.eof())
	{
		stuf.getline(s,200);
		temp<<s<<endl;//���м��ļ��д�����Ϣ
	}
	temp.close();
	stuf.close();
	ofstream stuf2(filetxt,ios::out);//��д�ķ�ʽ���ļ�
	ifstream temp1("d:\\temp.txt",ios::in);//�Զ��ķ�ʽ���м��ļ�
	while(!temp1.eof())
	{
		while(temp1>>a>>b>>c>>d>>g>>e>>f)//����һ������
			if(strcmp(a,k)==0)//�ж��Ƿ�����Ҫ�޸���Ϣ����Ա
			{
				t++;
				T A(a,b,c,d,g,e,f);
				A.print();
				char m;
				cout<<"ȷ��Ҫ�޸�����������Ϣ����Y/N)\n";
				cin>>m;
				if(m=='y'||m=='Y')
				{
					char p[30],q[30];
					long r;
					int h,s,t;
					cout<<"�밴��ʾ���������Ϣ��\n";
					cout<<"\n���䣺";
					cin>>h;
					cout<<"\n�绰��";
					cin>>p;
					cout<<"\n���ţ�";
					cin>>r;
					cout<<"\n�������ţ�";
					cin>>q;
					cout<<"\nÿСʱн��/����н��/�»������ʣ�";
					cin>>s;
					cout<<"\n�¹�ʱ/�¹�����/���½���:";
					cin>>t;
					T B(a,p,q,r,h,s,t);
					stuf2<<B;
					cout<<endl;
					cout<<a<<"�ĸ�����Ϣ�޸ĳɹ���"<<endl<<endl;
				}
				else stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//���ļ���д��һ������
			}
			else stuf2<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<" "<<e<<" "<<f<<endl;//���ļ���д��һ������
	}
	if(t==0)
	{
		cout<<"������Ա���в����ڴ��ˣ�\n\n";
	}
}

void modify()
{
	char choice;
	cout<<"��ѡ��Ҫ�޸�����Ա����Ϣ��\n\n"
	    <<"1��Сʱ��\n\n"
        <<"2���Ƽ���\n\n"
	    <<"3����нԱ��\n\n"
	    <<"Q���˳�\n\n";
    cin>>choice;
	system("cls");
    switch(choice)//����ѡ��ʵ��������ģ�棬�޸Ĳ�ͬ����Ա������Ϣ
    { 
	case '1':modify1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");break;
    case '2':modify1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");break;
    case '3':modify1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");break;
    case 'q':
    case 'Q':return ;
	default:cout<<"���������������\n\n";
  }
}