#include "xrunqueue.h"
#include <sys/time.h>

int main(){
	int i;
	XRunqueue queueInstance;

	XRunqueue_Initialize(&queueInstance, "runqueue");

	for(i=1; i<10000; i*=2){
	
		int counter = 0;
	
		struct timeval start, stop;

		XRunqueue_SetIterations(&queueInstance, i);
		
		u32 queueReturn = XRunqueue_GetReturn(&queueInstance);
	
		printf("Starting return value: %u\n", queueReturn);
		
		XRunqueue_Start(&queueInstance);

		gettimeofday(&start, NULL);
	
		XRunqueue_SetIterationsVld(&queueInstance);
	
		//wait for finish
		while(XRunqueue_IsDone(&queueInstance) == 0){
	//		u32 currentPriority = XRunqueue_GetCurrentpriority_v(&queueInstance);
	//		printf("Current priority: %u\n", currentPriority);
	//		u32 currentFull = XRunqueue_GetFullout(&queueInstance);
	//		printf("Current full: %u\n", currentFull);
			counter++;
		}
	
		gettimeofday(&stop, NULL);
	
		printf("Value of counter: %i\n", counter);
	
		printf("It took %lu microseconds for %i iterations\n", stop.tv_usec - start.tv_usec, i);
		
		queueReturn = XRunqueue_GetReturn(&queueInstance);
	
		printf("Ending return value: %u\n", queueReturn);
	}

	XRunqueue_Release(&queueInstance);
}
