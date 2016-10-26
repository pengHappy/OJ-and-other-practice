//读者与写者问题继 读写锁SRWLock
//需要vs2008以上环境。codeblocks不知道为啥不行
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
const int READER_NUM = 5;  //读者个数
//关键段和事件
CRITICAL_SECTION g_cs;
SRWLOCK          g_srwLock;
//读者线程输出函数(变参函数的实现)
void ReaderPrintf(char *pszFormat, ...)
{
	va_list   pArgList;
	va_start(pArgList, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArgList);
	LeaveCriticalSection(&g_cs);
	va_end(pArgList);
}
//读者线程函数
unsigned int __stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("     No.%d reader enters waiting queue...\n", GetCurrentThreadId());
	//读者申请读取文件
	AcquireSRWLockShared(&g_srwLock);

	//读取文件
	ReaderPrintf("     No.%d reader starts reading file...\n", GetCurrentThreadId());
	Sleep(rand() % 100);
	ReaderPrintf("     No.%d reader ends...\n", GetCurrentThreadId());

	//读者结束读取文件
	ReleaseSRWLockShared(&g_srwLock);
	return 0;
}
//写者线程输出函数
void WriterPrintf(char *pszStr)
{
	EnterCriticalSection(&g_cs);
	SetConsoleColor(FOREGROUND_GREEN);
	printf("     %s\n", pszStr);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	LeaveCriticalSection(&g_cs);
}
//写者线程函数
unsigned int __stdcall WriterThreadFun(PVOID pM)
{
	WriterPrintf("writer is waiting...");
	//写者申请写文件
	AcquireSRWLockExclusive(&g_srwLock);

	//写文件
	WriterPrintf("writer starts writing files.....");
	Sleep(rand() % 100);
	WriterPrintf("writer ends");

	//标记写者结束写文件
	ReleaseSRWLockExclusive(&g_srwLock);
	return 0;
}
int main()
{
	printf("  writer and reader problem --- SRWLock\n");
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//初始化读写锁和关键段
	InitializeCriticalSection(&g_cs);
	InitializeSRWLock(&g_srwLock);

	HANDLE hThread[READER_NUM + 1];
	int i;
	//先启动二个读者线程
	for (i = 1; i <= 2; i++)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	//启动写者线程
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);
	//最后启动其它读者结程
	for ( ; i <= READER_NUM; i++)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(READER_NUM + 1, hThread, TRUE, INFINITE);
	for (i = 0; i < READER_NUM + 1; i++)
		CloseHandle(hThread[i]);

	//销毁关键段
	DeleteCriticalSection(&g_cs);
	return 0;
}
//No. 97
