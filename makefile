OBJFILES = main.o vm.o
TARGET = vm
CFLAGS = -I./include

.PHONY : All
All : $(OBJFILES)
	$(CC) $(CXXFLAGS) $(OBJFILES) -o $(TARGET)
