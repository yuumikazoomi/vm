OBJFILES = main.o vm.o
TARGET = vm
CFLAGS = -I./include

.PHONY : All
All : $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET)
