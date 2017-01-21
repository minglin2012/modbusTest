SOURCES:=$(wildcard *.c)
TARGETLIST:=$(patsubst %.c,%.out,$(SOURCES))
OBJECTLIST:=$(patsubst %.c,%.o,$(SOURCES))
LDFLAGS=`pkg-config --libs libmodbus`
CFLAGS=`pkg-config --cflags libmodbus`
CC=gcc

test:
	@echo $(SOURCES)
	@echo $(TARGETLIST)
all : $(TARGETLIST)

.SECONDARY: $(OBJECTLIST)
.SUFFIX:
.SUFFIX: .out .o .c
.c.o:	
	${CC} -c $< ${LDFLAGS} ${CFLAGS}
.o.out :
	$(CC) -o $@ $< $(LDFLAGS) $(CFLAGS)



.PHONY : clean 
clean :
	-rm $(TARGETLIST) $(OBJECTLIST) 
