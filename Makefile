# APOSTLE makefile

# directories (change as desired)
dirsrc	= src/
dirobj	= obj/
dirbin	= bin/

# required objects (append as needed)
deps	= main world
objs	= $(addprefix $(dirobj), $(addsuffix .o, $(deps)))

# build variables:
##	build options
opts	= -march=native -Wall -O2

# executable variables:
##	name of the executable
exe	= apostle
##	target location of the executable
target	= $(dirbin)$(exe)

all:		$(target)

$(target):	$(objs)
	g++ -o $@ $(objs)

$(dirobj)%.o:	$(dirsrc)%.cpp
	g++ -o $@ $(opts) -c $<

clean:
	rm -f $(target) $(dirobj)*.o
