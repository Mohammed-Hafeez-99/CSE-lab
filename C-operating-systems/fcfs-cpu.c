#include <stdio.h>

int main()
{
	int bt[20], wt[20], tat[20], i, n;
	float wtavg, tatavg;
	printf("\nEnter the number of processes--");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("enter the burst time for the process %d--", i);
		scanf("%d", &bt[i]);
	}
	wt[0] = wtavg = 0;
	tat[0] = tatavg = bt[0];
	for (i = 1; i < n; i++) {
		wt[i] = wt[i - 1] + bt[i - 1];
		tat[1] = tat[i - 1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nProcess\tburst-time\t waiting-time\t turnaround-time");
	for (i = 0; i < n; i++) {
		printf("\n\tP%d\t\t\t%d\t\t\t%d\t\t\t%d", i, bt[i], wt[i],
		       tat[i]);
		printf("\nAverage Waiting Time -- %f", wtavg / n);
		printf("\nAverage Turnaround Time -- %f", tatavg / n);
		printf("\n");
	}
}