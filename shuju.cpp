#include"��ͷ.h"
#define N 10


/*-----------�����������������������ַ���------------------*/
char* randtxt() {
	static char ch[N + 1] = { NULL };
	//ʹ�þֲ���̬������֤ջ�˳���������Ȼ����
	int k = 0;
	for(int i=0;i<=rand()%N;i++){
		int flag = rand() % 2;
		if (flag)
			ch[k++] = 'A' + rand() % 26;
		else
			ch[k++] = 'a' + rand() % 26;
		//�������a-z֮����ַ�����ѭ������0-10��
		}
	ch[k] = '\0';
	return ch;
}


void RandInformation() {
	FILE* fp;
	fp = fopen(F_PATH, "w+");
	for (int i = 1; i <=128; i++) {
		//fprintf(fp,NODE "%d""#NAME"%s"#SEX"%d"#MATH"%d"#CHINESE"%d"##ENGLISH %d\n",i,randtxt(),i%2+1,rand()%100,rand()%100,rand()%100);     ��
		//����ĳ��ԣ��뽫�����ؼ��ַ��ú���棬ʹ����ά��������

		fprintf(fp,"node:%d name:%s sex:%d math:%d chinese:%d english:%d \n", i, randtxt(), i % 2 + 1, rand() % 100, rand() % 100, rand() % 100);

	//%s�õ�ʱ����Ҫ����һ����ַ
	//ע��Ҫ��д�ְ�򿪣���txt�򿪻ἷ��һ��
}
		fclose(fp);
}


