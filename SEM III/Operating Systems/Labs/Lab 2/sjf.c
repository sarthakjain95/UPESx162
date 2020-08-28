
// Shortest Job First (Non-Preemptive)

#include<stdio.h>
#include<stdlib.h>

struct process{
	int pid;
	int burst_time;
	int waiting_time;
	int is_completed;
};

void execute_jobs(struct process * process_list, int p_count){

	// System clock emulator
	int system_time= 0;

	for(int i=0; i<p_count; i++){
		// Choose the shortest job from given list
		int sji= -1; // Shortest Job Index
		for(int j=0; j<p_count; j++){
			if(process_list[j].is_completed) continue;
			//
			if( sji==-1 || process_list[j].burst_time <  process_list[sji].burst_time) 
				sji= j;
		}
		//
		// Execute job
		process_list[sji].waiting_time= system_time;
		system_time+= process_list[sji].burst_time;
		process_list[sji].is_completed= 1;
		//
		printf("ProcessID:%d \t BurstTime:%d \t WaitingTime:%d\n", process_list[sji].pid, 
			process_list[sji].burst_time, process_list[sji].waiting_time);
	}

	return;
}

int main(){

	int p_count;
	printf("Enter number of processes:");
	scanf("%d", &p_count);
	//
	struct process * process_list= malloc( sizeof(struct process) * p_count );
	for(int i=0; i<p_count; i++){
		printf("Enter process %d burst time: ", i+1);
		scanf("%d", &process_list[i].burst_time);
		//
		process_list[i].pid= i+1;
		process_list[i].is_completed= 0;
	}
	//
	execute_jobs(process_list, p_count);

	return 0;
}
