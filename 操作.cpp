#include"��ͷ.h"
//��������
void swap_struct(Student* student_1, Student* student_2) {
		Student temp;
		temp = *student_1;
		*student_1 = *student_2;
		*student_2 = temp;
}
//��ʱ��֪����ʲô
void insert_mid(Student* student_mid,int nodecode) {
	Student temp;
	temp = *student_mid;
	

}

//1.�������
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

//2.��ʼ��
void intilalise(Post* student_p) {
	//���ṹ���ʼ����ֵ
	//printf("please selet your data from  doucument(.txt)");                                   ��
	//����һ���������Ĺ��ܣ�����ʵ�ֵ���һ���Ի���Ȼ���û��Լ�ѡ����Ҫ�򿪵��ļ�
	FILE* fp;
	char a[100] = { NULL };
	fp = fopen(F_PATH, "r");
	while (EOF != fscanf(fp, "%s", a)) {
		checkcapacity(student_p);
		//����:��ȡ�ı��е���Ч��Ϣ
		/*˼·���ٽ���һ��������������ȡ������Ч��Ϣ�洢��ȥ���������ĳ����Ǳ仯�ģ����Ƕ�����
					�ڽ�����������Ϣת��������
					�۽����ִ���ṹ��                                                        */
					//���������Ľ��汾��ͨ�� ð �ţ�:�� �Զ������ı���Ϣ������ȡ��Ч��Ϣ                                                ��
		if (!strncmp(NODE, a, strlen(NODE))) {
			int sz = strlen(a) - strspn(a, NODE);
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz+1) * sizeof(char));
			//���붯̬�������ռ�
			if (NULL == buf) {
				printf("malloc failed!");

			}for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, NODE) + k];
			buf[sz] = '\0';
			//����Ч��Ϣ���뻺����
			student_p->_post[student_p->_size]._node = atoi(buf);
			//����������ת�������ִ���ṹ��
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._node);

		}

		if (!strncmp(NAME, a, strlen(NAME))) {
			int sz = strlen(a) - strspn(a, NAME)-1;
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			//���һ�٣��˴�����Ҫ����ռ�             ��
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//���붯̬�������ռ�
			for (int k = 0; k < sz; k++)
				student_p->_post[student_p->_size]._name[k] = a[strspn(a, NAME) + k+1];
			//����Ч��Ϣ���뻺����
			student_p->_post[student_p->_size]._name[sz] = '\0';

			free(buf);
			buf = NULL;
			//printf("%s \n", &post[i]._name);

		}

		if (!strncmp(SEX, a, strlen(SEX))) {
			int sz = strlen(a) - strspn(a, SEX);
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz + 1) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//���붯̬�������ռ�
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, SEX) + k];
			buf[sz] = '\0';
			//����Ч��Ϣ���뻺����
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
			//����������ת�������ִ���ṹ��
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._sex);

		}

		if (!strncmp(MATH, a, strlen(MATH))) {
			int sz = strlen(a) - strspn(a, MATH);
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");
				exit(0);
			}
			//���붯̬�������ռ�
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, MATH) + k];
			buf[sz] = '\0';
			//����Ч��Ϣ���뻺����
			student_p->_post[student_p->_size]._score.math = atoi(buf);
			//����������ת�������ִ���ṹ��
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._score.math);

		}

		if (!strncmp(CHINESE, a, strlen(CHINESE))) {
			int sz = strlen(a) - strspn(a, CHINESE);
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz+2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");

			}
			//���붯̬�������ռ�
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, CHINESE) + k];
			buf[sz] = '\0';
			//����Ч��Ϣ���뻺����
			student_p->_post[student_p->_size]._score.chinese = atoi(buf);
			//����������ת�������ִ���ṹ��
			free(buf);
			buf = NULL;
			//printf("%d \n", post[i]._score.chinese);
		}

		if (!strncmp(ENGLISH, a, strlen(ENGLISH))) {
			int sz = strlen(a) - strspn(a, ENGLISH);
			//sz����Ч��Ϣ����
			char* buf = (char*)malloc((sz + 2) * sizeof(char));
			if (NULL == buf) {
				printf("malloc failed!");
			}
			//���붯̬�������ռ�
			for (int k = 0; k < sz; k++)
				buf[k] = a[strspn(a, ENGLISH) + k];
			buf[sz] = '\0';
			//����Ч��Ϣ���뻺����
			student_p->_post[student_p->_size]._score.english = atoi(buf);
			//����������ת�������ִ���ṹ��
			free(buf);
			buf = NULL;
			//printf("%d \n \n", post[i]._score.english);
			student_p->_size++;
		}
		//	printf("%s \n", a);

	}
	fclose(fp);
}


//3.�������
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

//4.ɾ������
void delete_(Post* student_p) {
	student_p->_size--;
}

//5.��������
//�ٱ�������
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

//6.����
//��ð������
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

		case 3:   //�Զ��������,������                                          ��
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
//��ѡ������
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
//�۲�������
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

//��.�ݹ�ʵ�ֿ�������
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

//��ϣ������
void shell_sort(Post* student_p) 
{
	int times = 2;
	//int length = student_p->_size/times;
	Student temp = { NULL };
	int b = 0;

	//(log(student_p->_size) / log(2))
	for (int k = 0; k <20 ; k++)
	{
		//��ѭ����ȷ��ѭ������
		int length = student_p->_size / times;
		if(length <=1){
		length = 1; }
	
	for (int i = 0; i < length; i++)
	  {
		int index_1 = i;
		int index_2 = index_1;

	
		for (int a = 0; a<times; a++)
		{
			//��ѭ�����ƶ�����
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

//�޹鲢����
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

	/*����ıȽ��߼��ǣ�
	��������ָ�룬�ֱ�ָ�����������ͷ����Ȼ����бȽϣ����ϴ�/С��һ�����ݴ�����ʱ���飬������һ��ָ���ߵ�ͷʱ��
	����һ������ʣ�µ�����ȫ��������ʱ���飨�����ٽ��бȽϣ�
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
	//��ע�⣬����Ҳ��һ���ص㣬�����ָ���ʱ�����ָ��ָ��
	while(head<=tail)
	{
		student_p->_post[head++] = tmp[i++];
		//��ע������Ǵ�head��ʼ��ֵ
	}
	free(tmp);
	tmp = NULL;
}

//�߶�����
void heap_array_up(Post* student_p) 
{
	/*����˼·��
	������ȷ�����ǿյģ��ѵĲ������ƶ��У�β��ͷɾ��
	��ÿ����һ�����ݣ���ǰ����������++
	�۳�������ÿ�δ�β������һ��������Ҫ���� ���ϵ���
	��ϸ�ڣ�
	ÿ�β�������ǰȷ����ǰ�����Ѿ���һ����
	*/

	/*���ϵ�����
	�ٴ����һ���ڵ㿪ʼ���Ա��ӽڵ�͸��ڵ�
	��ȡ���нϴ�/С��ֵ���н���
	�۶Աȷ�Χ�� ���һ���ڵ� -> ͷ�ڵ㣨0��
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
	/*���µ�����
	�ٴ�ͷ�ڵ㿪ʼ���Աȸ��ڵ���� �� �� �ӽڵ�
	�ڽ��� ���ڵ� �� �����ӽڵ� �еĽϴ�/��С�� ����һ���ڵ�
	�۶Աȷ�Χ��ͷ�ڵ�->���һ����Ҷ�ӽڵ㣨���ڵ㣩
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

  