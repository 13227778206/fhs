#include"标头.h"
//交换数据
void swap_struct(Student* student_1, Student* student_2) {
		Student temp;
		temp = *student_1;
		*student_1 = *student_2;
		*student_2 = temp;
}
//暂时不知道是什么
void insert_mid(Student* student_mid,int nodecode) {
	Student temp;
	temp = *student_mid;
	

}

//1.检查容量
void checkcapacity(Post*S_Post) {
	assert(S_Post!=NULL);
	if (S_Post->_size == S_Post->_capacity)
	{
		Student* tmp = (Student*)malloc(sizeof(Student) * (2*(S_Post->_capacity)+1));
		assert(S_Post!=NULL);
		for(int i=0;i<S_Post->_size;i++)
		{
			
			tmp[i] = S_Post->_post[i];
		}
		free(S_Post->_post);
		S_Post->_post = tmp;
		tmp = NULL;
		S_Post->_capacity = (S_Post->_capacity) * 2 + 1;
	}





}

//2.初始化
void intilalise(Post* student_p) {
	//将结构体初始化赋值
	//printf("please selet your data from  doucument(.txt)");                                   △
	//这是一条待开发的功能，可以实现弹出一个对话框，然后用户自己选择需要打开的文件
	FILE* fp;
	char a[100] = { NULL };
	fp = fopen(F_PATH, "r");
	while (EOF != fscanf(fp, "%s", a)) {
		checkcapacity(student_p);
		//功能:提取文本中的有效信息
		/*思路：①建立一个缓冲区，将提取出的有效信息存储进去（缓冲区的长度是变化的，不是定长）
					②将缓冲区的信息转化成数字
					③将数字存入结构体                                                        */
					//待开发，改进版本：通过 冒 号（:） 自动解析文本信息，并提取有效信息                                                △
		if (!strncmp(NODE, a, strlen(NODE))) {
			int sz = strlen(a) - strspn(a, NODE);
			//sz是有效信息长度
			char* buf = (char*)malloc((sz+1) * sizeof(char));
			//申请动态缓冲区空间
			if (NULL == buf) {
				printf("malloc failed!");

			}for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, NODE) + k];
			buf[sz] = '\0';
			//将有效信息存入缓冲区
			student_p->_post[student_p->_size]._node = atoi(buf);
			//缓冲区数据转化成数字存入结构体
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._node);

		}

		if (!strncmp(NAME, a, strlen(NAME))) {
			int sz = strlen(a) - strspn(a, NAME)-1;
			//sz是有效信息长度
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			//多此一举，此处不需要申请空间             ×
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//申请动态缓冲区空间
			for (int k = 0; k < sz; k++)
				student_p->_post[student_p->_size]._name[k] = a[strspn(a, NAME) + k+1];
			//将有效信息存入缓冲区
			student_p->_post[student_p->_size]._name[sz] = '\0';

			free(buf);
			buf = NULL;
			//printf("%s \n", &post[i]._name);

		}

		if (!strncmp(SEX, a, strlen(SEX))) {
			int sz = strlen(a) - strspn(a, SEX);
			//sz是有效信息长度
			char* buf = (char*)malloc((sz + 1) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//申请动态缓冲区空间
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, SEX) + k];
			buf[sz] = '\0';
			//将有效信息存入缓冲区
			switch (atoi(buf)) {
			case 1:
				student_p->_post[student_p->_size]._sex = student_p->_post[student_p->_size].MALE;
				break;
			case 2:
				student_p->_post[student_p->_size]._sex = student_p->_post[student_p->_size].FEMALE;
				break;
			default:
				break;
			}
			//缓冲区数据转化成数字存入结构体
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._sex);

		}

		if (!strncmp(MATH, a, strlen(MATH))) {
			int sz = strlen(a) - strspn(a, MATH);
			//sz是有效信息长度
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");
				exit(0);
			}
			//申请动态缓冲区空间
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, MATH) + k];
			buf[sz] = '\0';
			//将有效信息存入缓冲区
			student_p->_post[student_p->_size]._score.math = atoi(buf);
			//缓冲区数据转化成数字存入结构体
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._score.math);

		}

		if (!strncmp(CHINESE, a, strlen(CHINESE))) {
			int sz = strlen(a) - strspn(a, CHINESE);
			//sz是有效信息长度
			char* buf = (char*)malloc((sz+2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//申请动态缓冲区空间
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, CHINESE) + k];
			buf[sz] = '\0';
			//将有效信息存入缓冲区
			student_p->_post[student_p->_size]._score.chinese = atoi(buf);
			//缓冲区数据转化成数字存入结构体
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._score.chinese);
		}

		if (!strncmp(ENGLISH, a, strlen(ENGLISH))) {
			int sz = strlen(a) - strspn(a, ENGLISH);
			//sz是有效信息长度
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");
			}
			//申请动态缓冲区空间
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, ENGLISH) + k];
			buf[sz] = '\0';
			//将有效信息存入缓冲区
			student_p->_post[student_p->_size]._score.english = atoi(buf);
			//缓冲区数据转化成数字存入结构体
			free(buf);
			buf = NULL;
			//printf("%d \n \n", post[i]._score.english);
			student_p->_size++;
		}
		//	printf("%s \n", a);

	}
	fclose(fp);
}


//3.添加数据
void insert(Post* student_p) {
	checkcapacity(student_p);
	printf("please insert node:");
	scanf("%d", &(student_p->_post[student_p->_size]._node));

	printf("please insert name:");
	scanf("%s", &(student_p->_post[student_p->_size]._name));

	printf("please insert sex:");
	scanf("%d", &(student_p->_post[student_p->_size]._sex));

	printf("please insert math:");
	scanf("%d", &(student_p->_post[student_p->_size]._score.math));

	printf("please insert chinese:");
	scanf("%d", &(student_p->_post[student_p->_size]._score.chinese));

	printf("please insert english:");
	scanf("%d", &(student_p->_post[student_p->_size]._score.english));
	student_p->_size++;
}

//4.删除数据
void delete_(Post* student_p) {
	student_p->_size--;
}

//5.搜素数据
//①遍历搜索
void search_ergodic(Post student_post) {
	int da = 0;
	scanf("%d",&da);
	for(int ac=0;ac< student_post._size;ac++){
	if (student_post._post[ac]._score.math==da) 
	{
		printf("|  %6d  ||  %10s  ||  %3d  ||  %4d  ||  %4d  ||  %4d  |\n", student_post._post[ac]._node, student_post._post[ac]._name, student_post._post[ac]._sex, student_post._post[ac]._score.math, student_post._post[ac]._score.chinese, student_post._post[ac]._score.english);
	}}
}
void search_

//6.排序
//①冒泡排序
void bubble_sort(Post* student_p,int i) {
	printf("please enter your socre");
	scanf("%d", &i);
	switch (i) {
	case 0:
		for (int a = 0; a < student_p->_size; a++) {
			for (int b =0; b< student_p->_size-1-a; b++){
				if (student_p->_post[b]._score.math > student_p->_post[b + 1]._score.math) {
						swap_struct(&(student_p->_post[b]), &(student_p->_post[b + 1]));
				}
		}
	}
			break;

		case 1:
			for (int a = 0; a < student_p->_size; a++) {
				for (int b = 0; b < student_p->_size - 1; b++) {
					if (student_p->_post[b]._score.chinese > student_p->_post[b + 1]._score.chinese) {
						swap_struct(&(student_p->_post[b]), &(student_p->_post[b + 1]));
					}
				}
			}
			break;

		case 2:
			for (int a = 0; a < student_p->_size; a++) {
				for (int b = 0; b < student_p->_size - 1; b++) {
					if (student_p->_post[b]._score.english > student_p->_post[b + 1]._score.english) {
						swap_struct(&(student_p->_post[b]), &(student_p->_post[b + 1]));
					}
				}
			}
			break;

		case 3:   //自定义输出项,待开发                                          △
			for (int a = 0; a < student_p->_size; a++) {
				for (int b = 0; b < student_p->_size - 1; b++) {
					int total_a = student_p->_post[b]._score.english+ student_p->_post[b]._score.math+ student_p->_post[b]._score.chinese;
					int total_b = student_p->_post[b+1]._score.english + student_p->_post[b+1]._score.math + student_p->_post[b+1]._score.chinese;
					if (total_a > total_b) {
						swap_struct(&(student_p->_post[b]), &(student_p->_post[b + 1]));
					}
				}
			}
			break;
		}
	

}
//②选择排序
void select_sort(Post* student_p, int i) {
	int max_id = 0;
	//printf("please enter your socre");
	//scanf("%d", &i);
	switch (i) {
	case 0:
		for (int a = 0; a < student_p->_size; a++) {
			max_id = a;
			for (int b = a; b < student_p->_size ; b++) {
				if (student_p->_post[max_id]._score.math > student_p->_post[b]._score.math) {
					max_id = b;
				}
			}
			swap_struct(&(student_p->_post[a]), &(student_p->_post[max_id]));
		}
		break;
	}
}
//③插入排序
void insert_sort(Post* student_p, int i) {
	int b = 0;
	Student temp = { NULL };
	switch (i)
	{
	case 0:
		for (int a = 0; a < student_p->_size; a++) 
		{
			temp = student_p->_post[a];
			for ( b = a; b >0; b--) 
			{
				if (temp._score.math < student_p->_post[b-1]._score.math)
					student_p->_post[b] = student_p->_post[b-1];
				else break;
			}
			student_p->_post[b ] = temp;
		}
		break;
	}
}

//④.递归实现快速排序
void quick_sort(Post* student_p, int left, int right) {
	if (left < right) 
	{
	int i = left;
	int j = right;
	Student num = student_p->_post[left];
	while (i < j)
	{
		while (i < j&&student_p->_post[j]._score.math >= num._score.math) {
			j--;
		}
		if (i < j)
			student_p->_post[i++] = student_p->_post[j];


		while (i < j&&student_p->_post[i]._score.math <=num._score.math) {
		i++;
	}
		if(i<j)
			student_p->_post[j--] = student_p->_post[i];
		
	}
		student_p->_post[i] = num;
		quick_sort(student_p, left, i - 1);
		quick_sort(student_p, i + 1, right);
	}
	
}

//⑤希尔排序
void shell_sort(Post* student_p) 
{
	int times = 2;
	//int length = student_p->_size/times;
	Student temp = { NULL };
	int b = 0;

	//(log(student_p->_size) / log(2))
	for (int k = 0; k <20 ; k++)
	{
		//外循环：确定循环次数
		int length = student_p->_size / times;
		if(length <=1){
		length = 1; }
	
	for (int i = 0; i < length; i++)
	  {
		int index_1 = i;
		int index_2 = index_1;

	
		for (int a = 0; a<times; a++)
		{
			//内循环：移动数据
			if(a< student_p->_size)
			{
			temp = student_p->_post[index_1];
			index_2 = index_1;
			for (b=a;b>0;b--)
			{
				 
				if (temp._score.math < student_p->_post[index_2-length]._score.math)
				{
					student_p->_post[index_2] = student_p->_post[index_2-length];	
					index_2 -= length;
				}
				else 
				{
					break;
					index_2 -= length;
				}
				
			
			}
			student_p->_post[index_2] = temp;
			index_1 += length;
			   
			}
		}




		
	  }
	   times = times * 2;
	}
}

//⑥归并排序
void merg_sort(Post* student_p, int first, int last)
{
		if (first < last)
		{int mid = (first + last) / 2;
	    merg_sort(student_p, first, mid);
		merg_sort(student_p, mid+1, last);
		merg_array(student_p,first,mid,last);
		}
}
void merg_array(Post* student_p, int head,int mid,int tail)
{
	int head_p = head;
	int tail_p = mid+1;
	int i = 0;
	Student* tmp = (Student*)malloc((tail - head+1) * sizeof(Student));

	/*这里的比较逻辑是：
	设置两个指针，分别指向两个数组的头部，然后进行比较，将较大/小的一个数据存入临时数组，当其中一个指针走到头时，
	将另一个数组剩下的数据全部存入临时数组（不用再进行比较）
	*/
	while (head_p<=mid && tail_p<=tail )
	{
		if (    (student_p->_post[head_p]._score.math) <  (student_p->_post[tail_p]._score.math)   )
		{ 
			tmp[i++]= student_p->_post[head_p++];
		}
		else{
			tmp[i++] = student_p->_post[tail_p++];
		}
	}
	while (head_p <= mid )
	{
		tmp[i++] = student_p->_post[head_p++];
	}
	while (tail_p <= tail)
	{
		tmp[i++] = student_p->_post[tail_p++];
	}
	i = 0;
	//△注意，这里也是一个重点，用来恢复临时数组的指针指向
	while(head<=tail)
	{
		student_p->_post[head++] = tmp[i++];
		//△注意这里，是从head开始赋值
	}
	free(tmp);
	tmp = NULL;
}

//⑦堆排序
void heap_array_up(Post* student_p) 
{
	/*建堆思路：
	①首先确定堆是空的（堆的操作类似队列，尾插头删）
	②每插入一个数据，当前堆数据容量++
	③除此自外每次从尾部插入一个数据需要进行 向上调整
	★细节：
	每次插入数据前确保当前数据已经是一个堆
	*/

	/*向上调整：
	①从最后一个节点开始：对比子节点和父节点
	②取其中较大/小的值进行交换
	③对比范围， 最后一个节点 -> 头节点（0）
	*/
	int cap = 0;
	int sz= student_p->_size;
	for(cap=0;cap< sz;cap++)
	{
		int i = cap;
	while (i!=0)
	{
		if (student_p->_post[i]._score.math > student_p->_post[(i - 1) / 2]._score.math)
			swap_struct(&(student_p->_post[i]), &(student_p->_post[(i - 1) / 2]));
		i--;
    }}
}
void heap_array_down(Post* student_p)
{
	/*向下调整：
	①从头节点开始：对比父节点和其 两 个 子节点
	②交换 父节点 和 两个子节点 中的较大/较小的 其中一个节点
	③对比范围：头节点->最后一个非叶子节点（父节点）
	*/

	int i = 0;
	int capacity = student_p->_size;
	while (capacity >=2)
	{
		i = 0;
		swap_struct(&(student_p->_post[i]), &(student_p->_post[capacity-1]));
		capacity--;
		if (capacity == 1)
			break;
		while(1)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int max = 0;
			
			if (right == capacity - 1) {
				student_p->_post[left]._score.math >= student_p->_post[right]._score.math ? max = left : max = right;
				if (student_p->_post[i]._score.math < student_p->_post[max]._score.math)
					swap_struct(&(student_p->_post[i]), &(student_p->_post[max]));
				break;
			}
			if (left == capacity - 1) {
				max = left;
				if (student_p->_post[i]._score.math < student_p->_post[max]._score.math)
					swap_struct(&(student_p->_post[i]), &(student_p->_post[max]));
				break;
			}
			student_p->_post[left]._score.math >= student_p->_post[right]._score.math ? max = left : max = right;
		if (student_p->_post[i]._score.math < student_p->_post[max]._score.math)
			swap_struct(&(student_p->_post[i]), &(student_p->_post[max]));



		i++;
		}
	}

}
void heap_sort(Post* student_p) 
{
	heap_array_up(student_p);   
	heap_array_down(student_p);
}

  