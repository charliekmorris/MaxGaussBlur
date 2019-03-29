NAME		= GaussBlur
EXEC		= $(NAME)

CC		= gcc
CFLAGS		= -std=gnu99 -Wall
LDFLAGS		= -lm

OBJ		= GaussBlurControl.o GaussBlurData.o

all:		run

$(EXEC):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

run:		$(EXEC)
.INTERMEDIATE: 	$(OBJ)

clean:
		rm $(EXEC)	
