CC = mips-linux-gnu-gcc
TARGETS= i2c_test

all:$(TARGETS)

camera_test: i2c_test.o
	$(CC) -o $@ $^ 

#%.o:%.c
#	$(CC) -c $< -o $@

clean:
	rm -f $(TARGETS) *.o
