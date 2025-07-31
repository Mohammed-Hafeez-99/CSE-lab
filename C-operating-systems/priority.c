#include <stdio.h>
struct pds {
	int bt,at,pid,ct,tt,wt,prio;
};
void sort_by_prio(struct pds processes[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (processes[j].prio > processes[j + 1].prio) {
				struct pds temp = processes[j];
				processes[j] = processes[j + 1];
				processes[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int n;
	float total_wt = 0, total_tt = 0;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	struct pds processes[n];
	printf("Enter process ID, arrival time, burst time, and prio:\n");
	for (int i = 0; i < n; i++) {
		printf("Process %d:\n", i + 1);
		printf("PID: ");
		scanf("%d", &processes[i].pid);
		printf("Arrival time: ");
		scanf("%d", &processes[i].at);
		printf("Burst time: ");
		scanf("%d", &processes[i].bt);
		printf("prio (lower number = higher prio): ");
		scanf("%d", &processes[i].prio);
	}
	sort_by_prio(processes, n);
	int current_time = 0;
	for (int i = 0; i < n; i++) {
		if (current_time < processes[i].at)
			current_time = processes[i].at;
		processes[i].ct = current_time + processes[i].bt;
		processes[i].tt = processes[i].ct - processes[i].at;
		processes[i].wt = processes[i].tt - processes[i].bt;
		total_tt += processes[i].tt;
		total_wt += processes[i].wt;
		current_time = processes[i].ct;
	}
	float avg_tt = total_tt / n;
	float avg_wt = total_wt / n;
	printf("\nPID\tAT\tBT\tprio\tCT\tTT\tWT\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", processes[i].pid,
		       processes[i].at, processes[i].bt, processes[i].prio,
		       processes[i].ct, processes[i].tt, processes[i].wt);
	}
	printf("\nAverage Waiting Time: %.2f\n", avg_wt);
	printf("Average Turnaround Time: %.2f\n", avg_tt);
	return 0;
}