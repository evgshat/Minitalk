#include "minitalk.h"
// getpid
// void (*signal (int signal, void (*sigfunc) (int func)))(int);

void		print_pid(int getpid)
{
	printf("%d\n", getpid);
}

void one(int signal)
{
	static int	cnt;
	static int	ch;
	static int	i;

	if (cnt == 0)
		cnt = 128;
	if (signal == SIGUSR1)
	{
		ch += cnt;
		cnt /= 2;
		i++;
	}
	else
	{
		cnt /= 2;
		i++;
	}
	if (i == 8)
	{
		if (ch != 0)
		{
			write(1, &ch, 1);
		}
		else
			write(1, "\n", 1);
		cnt = 128;
		ch = 0;
		i = 0;
	}
}

// void two(int b)
// {
// 	b = b;
// 	write (1, "world\n", 6);
// }

int	main(void)
{
	int pid;

	pid = getpid();
	print_pid(pid);
	signal(SIGUSR1, &one);
	signal(SIGUSR2, &one);
	while (1)
	{
		pause();
	}
}



//int sigemptyset(sigset_t *sig_m); - инициализация сигнала
//sigset_t - тип данных для предоаствления набора сигналов
// void (*signal (int signal, void (*sigfunc) (int func)))(int) - выполнить ф-ию на которую указывает sigfunc
//int sigaddset(sigset_t *sig_m, int signr); добавить сигнал, signr - номер сигнала
// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); - используется для изменения действий процесса при полчении сигнала
//sigaddset(&signal_set, SIGINT); - использование симвалического имени
//int kill(pid_t pid, int sig); - посылает сигнал процессу или группе процесса
//unsigned getpid(void) - посылает цифровой ид процесса
//int pause(void) - ожидает сигнал. процесс останавливается, пока не получит сигнал
//unsigned int sleep (unsigned int sec); - задержка в секундах. Приостанавливает рабботу потока, в котором она была вызвана
//int usleep (useconds_t usec); - то же, что и sleep, но в микросекундах
//exit - немедленное окончание работы программы
// SIGUSR1 and SIGUSR2 - константы. исп для межпроцессной (межпоточной) синхронизации. эти сигналы по умолчанию завершают выполнение процесса