CFLAGS += -Werror 
all: remoteExecute.c clean
	$(CC) $(CFLAGS) remoteExecute.c -o remoteExecute

debug: clean
	$(CC) $(CFLAGS) -D DEBUG_ON remoteExecute.c -o remoteExecute

install: all
	chmod a+x remoteExecute
	sudo cp remoteExecute /usr/bin/.
clean: remoteExecute
	rm remoteExecute
