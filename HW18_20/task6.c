MakeFile#1:
CC=gcc - навсякъде, където трябва да има gcc за компилиране на програми се пише CC
src = $(wildcard*.c) - прави списъл от всички с файлове
obj = $(Scr:.c=.o) - променлива, която прави субституция и замества ".с" с ".о"
LDFLAGS = -lGL -lglut -lpng -lz -lm  - променлива с флагове
myprog: $(obj) - имаме таргет "myprog" и реклаерментс всички с файлове
	$(CC) -o $@$^$(LDFLAGS)  - извикваме компилатора, изходният файл е myprog, тъй като след -о имаме $@, след това на всички файлове от променливата obj  им се добавят флаговете от променливата LDFLAGS
%.o:%.c
	$(CC) -o $@ -c $<   -компилира всички с файлове в .о
.PHONY: clean - уточнява, че clean не е файл, а команда
clean:
	rm -f $(obj) myprog - премахва всички .о файлове създадени от myprog
  
  
  Makefile 3:
#my makefile
CC = clang - инициализираме променлива с компилатора, който ще използваме
CFLAGS = -lm -pthread -> правим променлива с флаговете, които ще използваме 
OBJS = main.o sum.o mult.o div.o sub.o - променлива съдържаща всичко обджект файлове
.PHONY: all -> уточняваме, че all не е файл, а команда
all:program -> извиквайки командата all изпълняваме таргета program
program: $(OBJS)
  	$(CC)$^ -o $@$(CFLAGS) - > компилираме всички файлове от OBJS като program, заедно с всички флагове от CFLAGS
%.o:%.c
$(CC) -o $@ -c $<   -компилира всички с файлове в .о
.PHONY: clean - уточнява, че clean не е файл, а команда
clean:
	rm -rf*.o program - премахва всички .о файлове създадени от program
