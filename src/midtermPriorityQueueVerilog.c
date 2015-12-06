#include "xrunqueue.h"
#include <sys/time.h>

int main(int argc, char** argv){
	int i = argc > 1 ? atoi(argv[1]) : 1;
	XRunqueue queueInstance;

	XRunqueue_Initialize(&queueInstance, "runqueue");

		int counter = 0;
	
		struct timeval start, stop;
		
		u32 queueReturn = XRunqueue_GetReturn(&queueInstance);
	
		printf("Starting return value: %u\n", queueReturn);
		
		XRunqueue_Start(&queueInstance);
		
		XRunqueue_SetIterations(&queueInstance, i);

		gettimeofday(&start, NULL);
	
		XRunqueue_SetIterationsVld(&queueInstance);
	
		//wait for finish
		while(XRunqueue_GetFinishedVld(&queueInstance) == 0){
	//		u32 currentPriority = XRunqueue_GetCurrentpriority_v(&queueInstance);
	//		printf("Current priority: %u\n", currentPriority);
	//		u32 currentFull = XRunqueue_GetFullout(&queueInstance);
	//		printf("Current full: %u\n", currentFull);
//			u32 currentIteration = XRunqueue_GetCurrentiteration(&queueInstance);
//			printf("Current iteration: %u\n", currentIteration);
			counter++;
		}
	
		gettimeofday(&stop, NULL);
	
		printf("Value of counter: %i\n", counter);
	
		printf("It took %lu microseconds for %i iterations\n", stop.tv_usec - start.tv_usec, i);

		printf("It took %lu seconds for %i iterations\n", stop.tv_sec - start.tv_sec, i);

		u32 total = XRunqueue_GetTotal(&queueInstance);

		printf("Number of recorded enqueues: %u\n", total);

		u32 queueFinished = XRunqueue_GetFinished(&queueInstance);

		printf("Queue finished value: %u\n", queueFinished);
		
		queueReturn = XRunqueue_GetReturn(&queueInstance);
	
		printf("Ending return value: %u\n", queueReturn);

	XRunqueue_Release(&queueInstance);
}
