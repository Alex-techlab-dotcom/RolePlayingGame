EXEC = main

# Αχεια .ο
OBJS= main.o living.o shop.o grid.o items.o spells.o debuff.o

#Ο μεταγλωτιστης
CC = g++

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)
