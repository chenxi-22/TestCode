all:server client

client:client.c
	gcc -o $@ $^ -lpthread
server:server.c 
	gcc -o $@ $^ -lpthread

.PHONY:clean
	
clean:
	rm -f server client
