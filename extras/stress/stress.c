#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void stress(int child_id) {
	printf("Running stress child %d.\n", child_id);
	while (1);
}

int main(int argc, char **argv) {
	int n_children, i;

	sscanf(argv[1], "%d", &n_children);
	printf("Running stress test with %d children.\n", n_children);

	for (i = 0; i < n_children; ++i) {
		if (fork() == 0) {
			stress(i);
			break;
		}
	}

	waitpid(-1, NULL, 0);

	return 0;
}
