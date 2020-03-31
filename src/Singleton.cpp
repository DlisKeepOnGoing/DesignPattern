#include<Singleton.h>
#include<process.h>
#include<windows.h>
#define TOTAL_THREAD_NUM 10


unsigned int __stdcall CallSingleton(void* pPM)
{
    Singleton* s = Singleton::GetInstance();
    int thread_num = *(int *)pPM;
    //Sleep(1000);
    printf("线程编号为：%d\n", thread_num);
    return 0;
}



int main()
{
    //Singleton* s1 = Singleton::GetInstance();
    //Singleton* s2 = Singleton::GetInstance();
    HANDLE  handle[TOTAL_THREAD_NUM];
 
	//线程编号
	int threadNum = 0;
	while (threadNum < TOTAL_THREAD_NUM)
	{
		handle[threadNum] = (HANDLE)_beginthreadex(NULL, 0, CallSingleton, &threadNum, 0, NULL);
		//等子线程接收到参数时主线程可能改变了这个i的值
		threadNum++;
	}
	//保证子线程已全部运行结束
	WaitForMultipleObjects(TOTAL_THREAD_NUM, handle, TRUE, INFINITE);
	system("pause");
	return 0;
}



