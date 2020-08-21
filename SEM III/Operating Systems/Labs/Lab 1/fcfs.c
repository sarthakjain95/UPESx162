
#include<stdio.h>
#include<stdlib.h>

struct process{
	int process_id;
	int burst_time;
	int waiting_time;
};

void calc_waiting_time(struct process p[], int n){

	// First process executes at it arrives
	p[0].waiting_time= 0;

	int elapsed_time= p[0].burst_time;
	//
	for(int i=1; i<n; i++){
		p[i].waiting_time= elapsed_time;
		elapsed_time+= p[i].burst_time;
	}

}

void display_process(struct process p[], int n){
	
	for(int i=0; i<n; i++){
		printf("ProcessID:%d \t Burst Time:%dms \t Waiting Time:%dms\n",
			p[i].process_id, p[i].burst_time, p[i].waiting_time);
	}

}

int main(){

	int n= 0;
	printf("Enter number of process: ");
	scanf("%d", &n);
	//
	struct process * p= malloc(sizeof(struct process) * n);
	for(int i=0; i<n; i++){
		printf("Enter Process %d ProcessId: ", i+1);
		scanf("%d", &p[i].process_id);
		printf("Enter Process %d Burst Time: ", i+1);
		scanf("%d", &p[i].burst_time);
	}
	//
	calc_waiting_time(p, n);
	display_process(p, n);

	return 0;
}
