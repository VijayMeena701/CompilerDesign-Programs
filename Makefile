all:
	gcc -Wall -Wextra -Werror -g3 first.c -o first
	gcc -Wall -Wextra -Werror -g3 follow.c -o follow
	gcc -Wall -Wextra -Werror -g3 checkGrammer.c -o checkGrammer
	gcc -Wall -Wextra -Werror -g3 convert.c -o convert