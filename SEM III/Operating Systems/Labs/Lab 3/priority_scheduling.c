
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int pid;
	int priority;
	int burst_time;
	int is_completed;
} process;

void execute(process * processes, int size){

	int system_clock= 0;
	int selected_process= -1;
	int remaining_process= size;

	while(remaining_process>0){

		selected_process= -1;
		for(int i=0; i<size; i++){
			if(processes[i].is_completed == 0){
				if(selected_process == -1){
					selected_process= i;
				}else if(processes[i].priority < processes[selected_process].priority) {
					selected_process= i;
				}
			}
		}

		printf("(time:%d) Executing process | pid:%d \t priority:%d\n", system_clock, processes[selected_process].pid, processes[selected_process].priority);
		system_clock+= processes[selected_process].burst_time;
		processes[selected_process].is_completed= 1;

		remaining_process--;
	}

}

int main(){

	int n_processes= 0;
	printf("Enter number of processes:");
	scanf("%d", &n_processes);

	process * processes = (process*)malloc(n_processes*sizeof(process));

	for(int i=0; i<n_processes; i++){
		processes[i].pid= i;
		printf("Enter priority for process %d: ", i);
		scanf("%d", &processes[i].priority);
		printf("Enter burst time for process %d: ", i);
		scanf("%d", &processes[i].burst_time);
		processes[i].is_completed= 0;
	}

	execute(processes, n_processes);

	return 0;
}

