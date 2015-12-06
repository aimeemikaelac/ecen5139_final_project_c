#include "xrunqueue.h"
#include <sys/time.h>

int main(){
	XRunqueue queueInstance;

	XRunqueue_Initialize(&queueInstance, "runqueue");

	int i = 0;

	struct timeval start, stop;

	gettimeofday(&start, NULL);

	u32 queueReturn = XRunqueue_GetReturn(&queueInstance);

	printf("Starting return value: %u\n", queueReturn);

	XRunqueue_Start(&queueInstance);

	//wait for finish
	while(XRunqueue_IsDone(&queueInstance) == 0){
		u32 currentPriority = XRunqueue_GetCurrentpriority_v(&queueInstance);
		printf("Current priority: %u\n", currentPriority);
		u32 currentFull = XRunqueue_GetFullout(&queueInstance);
		printf("Current full: %u\n", currentFull);
		i++;
	}

	gettimeofday(&stop, NULL);

	printf("Value of i: %i\n", i);

	printf("It took %lu microseconds\n", stop.tv_usec - start.tv_usec);
	
	queueReturn = XRunqueue_GetReturn(&queueInstance);

	printf("Ending return value: %u\n", queueReturn);

	XRunqueue_Release(&queueInstance);
}
