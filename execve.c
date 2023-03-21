#include<unistd.h>

// https://www.youtube.com/watch?v=9q1VL8UU8h0

// spawns a shell
int main(int argc, char** argv) {
		char* args[2];
		args[0] = "/bin/sh";
		args[1] = NULL;
		execve(args[0], args, NULL);

		return 0;
}

//For shellcoding, you might want to remove the return so that you can continue execution...????
//If I use: execve(arg[0], 0, 0), it compiles with a warning but still works, (args[0], Null, Null), is same.

