all: libfreebindfree.so

lib%.so: %.c
	gcc -shared -Wl,--no-as-needed -o $@ -ldl $< -fPIC
