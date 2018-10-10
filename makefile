all:
	gcc myLinkedList.c -o execute
	./execute
drop:
	rm execute