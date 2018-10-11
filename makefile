all:
	gcc LinkedList.c -o execute
	@./execute
	@rm execute