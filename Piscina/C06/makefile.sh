echo ; echo norminette:;  norminette ex??/*.c; echo;
gcc -Wall -Wextra -Werror -o test0 ex00/*.c; echo test0:; ./test0; echo
gcc -Wall -Wextra -Werror -o test1 ex01/*.c; echo test1:; ./test1 hola que tal; echo
gcc -Wall -Wextra -Werror -o test2 ex02/*.c; echo test2:; ./test2 estas tal que hola; echo;
gcc -Wall -Wextra -Werror -o test3 ex03/*.c; echo test3:; ./test3 test3 test1 test2; echo
