#include"head.h"

template<typename T>//����ģ�棬ʵ�ָ����û�ѡ��ֱ������������Ա����Ϣ�Ĺ���

void average1(const char *filetxt)
{ 
	employee *Employee[1000];//�������ָ������ͻ���ָ��
    int i=0,k,g,e,f;
	double total=0;
    char a[30],b[30],c[30];
	long d;
    ifstream instuf(filetxt,ios::in);//�Զ��ķ�ʽ���ļ�
	if(!instuf) {cerr<<"���ļ�ʧ�ܣ����Ƚ��г�ʼ����"<<endl; abort();}
    while(instuf>>a>>b>>c>>d>>g>>e>>f)//��ȡһ������
    {
		Employee[i]=new T(a,b,c,d,g,e,f);
	    i++;//�ۼƸ���Ա��������
	}
    for(k=0;k<i;k++) 
		{
			((T *)Employee[k])->earnings();//���Ա��������Ϣ
			total+=((T *)Employee[k])->earnings();
	    }
	cout<<"����Ա��ƽ������Ϊ��"<<total/i<<endl;
}

void average2(const char *filetxt1,const char *filetxt2,const char *filetxt3)//ʵ�����ȫ��Ա��������Ϣ�Ĺ���
{ 
	employee *Employee[1000];//�������ָ�����飬����ָ��
    int i=0,k,g,e,f;
	double total=0;
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
	for(k=0;k<i;k++) 
		{
			Employee[k]->earnings();//���Ա��������Ϣ
			total+=Employee[k]->earnings();
	    }
	cout<<"ȫ��Ա��ƽ������Ϊ��"<<total/i<<endl;
}
void average()
{
	cout<<"��ѡ��Ҫ����ƽ�����ʵ�Ա�����ͣ�\n\n"//���й���ѡ��
	  <<"1��Сʱ��\n\n"
	  <<"2���Ƽ���\n\n"
	  <<"3����нԱ��\n\n"
	  <<"4��ȫ��Ա��\n\n"
	  <<"Q���˳�\n\n";
  char m;
  cin>>m;
  system("cls"); 
  if(m=='1') {average1<hourlyworker>("d:\\hourlyworkerbook.txt");system("pause");system("cls");}//ʵ��������ģ��
  if(m=='2') {average1<pieceworker>("d:\\pieceworkerbook.txt");system("pause");system("cls");}
  if(m=='3') {average1<monthlyworker>("d:\\monthlyworkerbook.txt");system("pause");system("cls");}
  if(m=='4') {average2("d:\\hourlyworkerbook.txt","d:\\pieceworkerbook.txt","d:\\monthlyworkerbook.txt");system("pause");system("cls");}
  else return;
  cout<<"��Աƽ�����������ϣ�"<<endl<<endl;
}
