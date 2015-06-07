main:
	# Disable ASLR
	echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
	gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -z execstack main.c
