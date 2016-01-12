# APOSTLE makefile

# directories (change as desired)
dirsrc	= src
dirobj	= obj
dirbin	= bin

# required objects (append as needed)
deps	= main world objects
objs	= $(addprefix $(dirobj)/, $(addsuffix .o, $(deps)))

# build variables:
##	build options
opts	= -march=native -Wall -O2

# executable variables:
##	name of the executable
exe	= apostle
##	target location of the executable
target	= $(dirbin)/$(exe)

all:		$(target)

$(target):	$(dirsrc) $(dirobj) $(dirbin) $(objs)
	g++ -o $@ $(objs)

$(dirobj)/%.o:	$(dirsrc)/%.cpp
	g++ -o $@ $(opts) -c $<

$(dirsrc):
	echo "error: src directory can not be created"

$(dirobj):
	mkdir $(dirobj)

$(dirbin):
	mkdir $(dirbin)

clean:
	rm $(target) $(dirobj)*.o
