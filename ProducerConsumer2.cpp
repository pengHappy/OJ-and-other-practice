//1生产者 2消费者 4缓冲区
//两个信号量，一加一减
#include <stdio.h>
#include <process.h>
#include <windows.h>
//设置控制台输出颜色
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
const int END_PRODUCE_NUMBER = 8;  //生产产品个数
const int BUFFER_SIZE = 4;          //缓冲区个数
int g_Buffer[BUFFER_SIZE];          //缓冲池
int g_i, g_j;
bool over;
//信号量与关键段
CRITICAL_SECTION g_cs;
HANDLE g_hSemaphoreBufferEmpty, g_hSemaphoreBufferFull;
//生产者线程函数
unsigned int __stdcall ProducerThreadFun(PVOID pM)
{
	for (int i = 1; i <= END_PRODUCE_NUMBER; i++)
	{
		//等待有空的缓冲区出现
		WaitForSingleObject(g_hSemaphoreBufferEmpty, INFINITE);

		//互斥的访问缓冲区
		EnterCriticalSection(&g_cs);
		g_Buffer[g_i] = i;
		printf("producer generates data %d to block %d\n", g_Buffer[g_i], g_i);
		g_i = (g_i + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		//通知消费者有新数据了
		ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);
	}
	printf("producer terminates\n");
	return 0;
}
//消费者线程函数
unsigned int __stdcall ConsumerThreadFun(PVOID pM)
{
	while (true)
	{
	    //没有资源了
	    if(over == true)
            break;

		//等待非空的缓冲区出现
		WaitForSingleObject(g_hSemaphoreBufferFull, INFINITE);

		//互斥的访问缓冲区
		EnterCriticalSection(&g_cs);
		SetConsoleColor(FOREGROUND_GREEN);
		printf("  No%d gets data %d from %dth block\n", GetCurrentThreadId(), g_Buffer[g_j], g_j);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if (g_Buffer[g_j] == END_PRODUCE_NUMBER)//结束标志
		{
			EnterCriticalSection(&g_cs);
			over = true;
			LeaveCriticalSection(&g_cs);
			break;
		}
		g_j = (g_j + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		Sleep(50); //some other work to do

		ReleaseSemaphore(g_hSemaphoreBufferEmpty, 1, NULL);
	}
	SetConsoleColor(FOREGROUND_GREEN);
	printf("  No%d consumer gets informed and terminates\n", GetCurrentThreadId());
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return 0;
}
int main()
{
	printf("  producer and consumer problem\n");
	printf("  One producer, Two consumers, Four blocks\n");

	InitializeCriticalSection(&g_cs);
	//初始化信号量,一个记录有产品的缓冲区个数,另一个记录空缓冲区个数.
	g_hSemaphoreBufferEmpty = CreateSemaphore(NULL, 4, 4, NULL);
	g_hSemaphoreBufferFull  = CreateSemaphore(NULL, 0, 4, NULL);
	g_i = 0;
	g_j = 0;
	over = false;
	memset(g_Buffer, 0, sizeof(g_Buffer));

	const int THREADNUM = 3;
	HANDLE hThread[THREADNUM];
	//生产者线程
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ProducerThreadFun, NULL, 0, NULL);
	//消费者线程
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	hThread[2] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(THREADNUM, hThread, TRUE, INFINITE);
	for (int i = 0; i < THREADNUM; i++)
		CloseHandle(hThread[i]);

	//销毁信号量和关键段
	CloseHandle(g_hSemaphoreBufferEmpty);
	CloseHandle(g_hSemaphoreBufferFull);
	DeleteCriticalSection(&g_cs);
	return 0;
}
//No. 96
