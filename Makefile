all: libfreebindfree.so

lib%.so: %.c
	gcc -shared -o $@ -ldl $< -fPIC
