#include"head.h"

template<typename T>//����ģ�棬ʵ�ָ����û�ѡ��ֱ������������Ա����Ϣ�Ĺ���

void browse1(const char *filetxt,int m)
{ 
	employee *Employee[1000],*temp;//�������ָ������ͻ���ָ��
    int i=0,k,work,g,e,f;
    char a[30],b[30],c[30];
	long d;
    ifstream instuf(filetxt,ios::in);//�Զ��ķ�ʽ���ļ�
	if(!instuf) {cerr<<"���ļ�ʧ�ܣ����Ƚ��г�ʼ����"<<endl; abort();}
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//��ȡһ������
    {
		Employee[i]=new T(a,b,c,d,g,e,f);
	    i++;//�ۼƸ���Ա������
	}
    switch(m)
    { 
	case 1://����������
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

    case 2://����������
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

    case 3:break;//������
	}
    for(k=0;k<i;k++) 
		{
			((T *)Employee[k])->print();//���Ա����Ϣ
			cout<<endl;
	}
}

void browse2(int m)//ʵ�����ȫ��Ա��������Ϣ�Ĺ���
{ 
	employee *Employee[1000],*temp;//�������ָ�����飬����ָ��
    int i=0,k,work,g,e,f;
    char a[30],b[30],c[40];
	long d;
    ifstream instuf1("d:\\hourlyworkerbook.txt",ios::in);//�Զ��ķ�ʽ���ļ�
    ifstream instuf2("d:\\pieceworkerbook.txt",ios::in);
    ifstream instuf3("d:\\monthlyworkerbook.txt",ios::in);
    if(!instuf1||!instuf2||!instuf3) 
	   cout<<"���ļ�ʧ�ܣ����Ƚ��г�ʼ����"<<endl;
    while(instuf1>>a>>b>>c>>d>>g>>e>>f)//��һ������
    {
		Employee[i]=new hourlyworker(a,b,c,d,g,e,f);
        i++;//ͳ��ȫ��Ա������
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
	case 1://����������
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

    case 2://����������
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

    case 3:break;//������
  }
  for(k=0;k<i;k++) 
  { 
	  Employee[k]->print();cout<<"\n\n";
  }//���ȫ��Ա����Ϣ
}

void browse()
{   
  cout<<"��ѡ��Ҫ�����Ա�����ͣ��Լ�����ķ�ʽ���ÿո��������\n\n"//���й���ѡ��
	  <<"1��Сʱ��\n\n"
	  <<"2���Ƽ���\n\n"
	  <<"3����нԱ��\n\n"
	  <<"4��ȫ����Ա\n\n"
	  <<"Q���˳�\n\n"
	  <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
	  <<"A�����������������\n\n"
	  <<"B�����չ����������\n\n"
	  <<"C���޸�ʽ���\n\n"
	  <<"Q���˳�\n\n";
  char m,n;
  while(1)
  {
	  cin>>m;
	  if(m>='1'&&m<='4'||m=='Q'||m=='q')
		  break;
	  else 
		  cout<<"����������������룡"<<endl;
  }
  while(1)
  {
	  cin>>n;
	  if(n>='A'&&n<='C'||n>='a'&&n<='c'||n=='Q'||n=='q')
		  break;
	  else
		  cout<<"����������������룡"<<endl;
  }
  system("cls"); 
  if((m=='1'||m=='2'||m=='3')&&(n=='A'||n=='a'||n=='B'||n=='b'||n=='C'||n=='c'))
  if(m=='1'&&(n=='A'||n=='a')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",1);system("pause");system("cls");}//ʵ��������ģ��
  if(m=='1'&&(n=='B'||n=='b')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",2);system("pause");system("cls");}
  if(m=='1'&&(n=='C'||n=='c')) {browse1<hourlyworker>("d:\\hourlyworkerbook.txt",3);system("pause");system("cls");}
  if(m=='2'&&(n=='A'||n=='a')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",1);system("pause");system("cls");}
  if(m=='2'&&(n=='B'||n=='b')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",2);system("pause");system("cls");}
  if(m=='2'&&(n=='C'||n=='c')) {browse1<pieceworker>("d:\\pieceworkerbook.txt",3);system("pause");system("cls");}
  if(m=='3'&&(n=='A'||n=='a')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",1);system("pause");system("cls");}
  if(m=='3'&&(n=='B'||n=='b')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",2);system("pause");system("cls");}
  if(m=='3'&&(n=='C'||n=='c')) {browse1<monthlyworker>("d:\\monthlyworkerbook.txt",3);system("pause");system("cls");}
  if(m=='4'&&(n=='A'||n=='a')) {browse2(1);system("pause");system("cls");}//���ú���
  if(m=='4'&&(n=='B'||n=='b')) {browse2(2);system("pause");system("cls");}
  if(m=='4'&&(n=='C'||n=='c')) {browse2(3);system("pause");system("cls");}
}
