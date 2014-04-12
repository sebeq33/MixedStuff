#include <iostream>
#include "Thread.hh"
#include "Mutex.hh"

int	i = 0;
Mutex	mutex;

# ifdef WIN32
DWORD WINAPI increase(LPVOID lpParam)
# else
void	*increase(void *param)
# endif
{
	while (i < 100)
	{
		mutex.lock();
		std::cout << "i : " << i << std::endl;
		i++;
		mutex.unlock();
	}
}

int	main()
{
	Thread	thread1;
	Thread	thread2;

	std::cout << "Start" << std::endl;
	thread1.start(increase, NULL);
	thread2.start(increase, NULL);
	std::cout << "End" << std::endl;

	# ifdef WIN32
		Sleep(1000);
	# else
		sleep(1);
	# endif
	return (0);
}
