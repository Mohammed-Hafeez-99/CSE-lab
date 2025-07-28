#include <stdio.h>
int main()
{
	int a[10], b[10], x[10], i, j, n, smallest, count = 0, time;
	double avg = 0, tt = 0, end;
	int waiting[10], turnaround[10], completion[10];
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter arrival time:\n");
	for (i = 0; i < n; i++) {
		printf("Process %d: ", i + 1);
		scanf("%d", &a[i]);
	}
	printf("Enter burst time:\n");
	for (i = 0; i < n; i++) {
		printf("Process %d: ", i + 1);
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n; i++) {
		x[i] = b[i];
		avg += waiting[i];
	}
	b[9] = 9999;
	for (time = 0; count != n; time++) {
		smallest = 9;
		for (i = 0; i < n; i++) {
			if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
				smallest = i;
		}
		b[smallest]--;
		if (b[smallest] == 0) {
			count++;
			end = time + 1;
			completion[smallest] = end;
			waiting[smallest] = end - a[smallest] - x[smallest];
			turnaround[smallest] = end - a[smallest];
		}
	}
	printf("\nProcess\tAT\tBT\tWT\tTAT\tCT\n");
	for (i = 0; i < n; i++) {
		printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", i + 1, a[i], x[i],
		       waiting[i], turnaround[i], completion[i]);
		tt += turnaround[i];
	}
	printf("\nAverage waiting time: %.2f", avg / n);
	printf("\nAverage turnaround time: %.2f\n", tt / n);
	return 0;
}