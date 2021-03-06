# This program is free software. It comes without any warranty, to
# the extent permitted by applicable law. You can redistribute it
# and/or modify it under the terms of the Do What The Fuck You Want
# To Public License, Version 2, as published by Sam Hocevar. See
# http://sam.zoy.org/wtfpl/COPYING for more details.
LDLIBS = -lGL -lglut -lGLU
OBJ = main.o geom.o
EXE = raytracer

${EXE}: ${OBJ}
	g++ ${OBJ} ${LDLIBS} -o ${EXE}

clean:
	rm *~ ${OBJ} ${EXE}

main.o: geom.h

sphere.o: geom.h
