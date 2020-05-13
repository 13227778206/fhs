#include"标头.h"
#define N 10


/*-----------下面这个函数用来生成随机字符串------------------*/
char* randtxt() {
	static char ch[N + 1] = { NULL };
	//使用局部静态变量保证栈退出后数据依然存在
	int k = 0;
	for(int i=0;i<=rand()%N;i++){
		int flag = rand() % 2;
		if (flag)
			ch[k++] = 'A' + rand() % 26;
		else
			ch[k++] = 'a' + rand() % 26;
		//随机产生a-z之间的字符串，循环产生0-10次
		}
	ch[k] = '\0';
	return ch;
}


void RandInformation() {
	FILE* fp;
	fp = fopen(F_PATH, "w+");
	for (int i = 1; i <=128; i++) {
		//fprintf(fp,NODE "%d""#NAME"%s"#SEX"%d"#MATH"%d"#CHINESE"%d"##ENGLISH %d\n",i,randtxt(),i%2+1,rand()%100,rand()%100,rand()%100);     △
		//错误的尝试，想将几个关键字符用宏代替，使代码维护更方便

		fprintf(fp,"node:%d name:%s sex:%d math:%d chinese:%d english:%d \n", i, randtxt(), i % 2 + 1, rand() % 100, rand() % 100, rand() % 100);

	//%s用的时候需要传入一个地址
	//注意要用写字板打开，用txt打开会挤在一行
}
		fclose(fp);
}


