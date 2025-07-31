#include <stdio.h>
int main()
{
	int n, i, time = 0, remain, time_quantum;
	int at[10], bt[10], rt[10];
	int wt = 0, tat = 0;
	float avg_wt, avg_tat;
	printf("Enter total number of processes: ");
	scanf("%d", &n);
	remain = n;
	for (i = 0; i < n; i++) {
		printf("Enter arrival time for process %d: ", i + 1);
		scanf("%d", &at[i]);
		printf("Enter burst time for process %d: ", i + 1);
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
	}
	printf("Enter the time quantum for the process: ");
	scanf("%d", &time_quantum);
	int complete[n], ct[n];
	for (i = 0; i < n; i++)
		complete[i] = 0;
	while (remain != 0) {
		int done = 1;
		for (i = 0; i < n; i++) {
			if (at[i] <= time && rt[i] > 0) {
				done = 0;
				if (rt[i] <= time_quantum) {
					time += rt[i];
					rt[i] = 0;
					ct[i] = time;
					complete[i] = 1;
					remain--;
				} else {
					rt[i] -= time_quantum;
					time += time_quantum;
				}
			}
		}
		if (done)
			time++;
	}
	printf("\nProcess No \t Burst Time \t\t Arrival Time \t\t Turnaround Time \t Waiting Time\n");
	for (i = 0; i < n; i++) {
		int turnaround = ct[i] - at[i];
		int waiting = turnaround - bt[i];
		printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i],
		       at[i], turnaround, waiting);
		wt += waiting;
		tat += turnaround;
	}
	avg_wt = (float)wt / n;
	avg_tat = (float)tat / n;
	printf("\nAverage Waiting Time: %.2f", avg_wt);
	printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
	return 0;
}