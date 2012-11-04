CFLAGS += -Werror 
all: remoteExecute.c clean
	$(CC) $(CFLAGS) remoteExecute.c -o remoteExecute

debug: clean
	$(CC) $(CFLAGS) -D DEBUG_ON remoteExecute.c -o remoteExecute

clean: remoteExecute
	rm remoteExecute
