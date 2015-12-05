#include "xrunqueue.h"
#include <sys/time.h>

int main(){
	XRunqueue queueInstance;

	XRunqueue_Initialize(&queueInstance, "runqueue");

	int i = 0;

	struct timeval start, stop;

	gettimeofday(&start, NULL);

	XRunqueue_Start(&queueInstance);

	//wait for finish
	while(!XRunqueue_IsDone(&queueInstance)){
		i++;
	}

	gettimeofday(&stop, NULL);

	printf("Value of i: %i\n", i);

	printf("It took %lu microseconds\n", stop.tv_usec - start.tv_usec);

	XRunqueue_Release(&queueInstance);
}
