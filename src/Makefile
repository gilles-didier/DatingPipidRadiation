# Executables to build
TCLA = tcla
DRSP = drsp
DSPE = dspe
DSPB = dspb
DEXT = dext
SIST = sist

# Object files required by each executable
OBJ_TCLA = MyR.o Utils.o Tree.o TestClades.o
OBJ_DRSP = MyR.o DrawDensity.o DrawFossilInt.o DrawTreeCairo.o DrawTreePSTricks.o DrawTreeTikz.o DrawTimePosition.o DrawTreeGeneric.o Utils.o Tree.o Fossil.o FossilInt.o Distribution.o DrawFossilTreeSpecial.o
OBJ_DSPE = MyR.o Model.o MCMCImportanceSampling.o Uncertainty.o Utils.o Tree.o Fossil.o FossilInt.o Distribution.o ComputeSpeciationDistribution.o
OBJ_DSPB = MyR.o Model.o MCMCImportanceSampling.o Uncertainty.o Utils.o Tree.o Fossil.o FossilInt.o Distribution.o ComputeSpeciationDistributionBis.o
OBJ_DEXT = MyR.o Model.o MCMCImportanceSampling.o Uncertainty.o Utils.o Tree.o Fossil.o FossilInt.o Distribution.o ComputeExtinctionDistribution.o
OBJ_SIST = MyR.o Utils.o Tree.o GetSisterClade.o

SRC = \
	MyR.c Utils.c Tree.c TestClades.c GetSisterClade.c \
	Model.c MCMCImportanceSampling.c Uncertainty.c \
	Fossil.c FossilInt.c Distribution.c \
	ComputeSpeciationDistribution.c ComputeSpeciationDistributionBis.c ComputeExtinctionDistribution.c \
	DrawDensity.c DrawFossilInt.c DrawTreeCairo.c DrawTreePSTricks.c DrawTreeTikz.c \
	DrawTimePosition.c DrawTreeGeneric.c DrawFossilTreeSpecial.c

EXE = $(TCLA) $(DRSP) $(DSPE) $(DSPB) $(DEXT) $(SIST)

CC = gcc
CFLAGS = -Wall -Wno-char-subscripts -D_POSIX_SOURCE -DBUILD_NATIVE=OFF -std=c99 -pedantic -march=native -I/usr/include/cairo -D_REENTRANT -ffunction-sections -fdata-sections -g
LDFLAGS = -Wl,--gc-sections
LD = $(CC)

.PHONY: all clean distclean

all: Makefile.d $(EXE)

$(TCLA): $(OBJ_TCLA)
	$(LD) $(LDFLAGS) $^ -o $@ -lm -lgsl -lgslcblas -L/usr/lib/ -g

$(DRSP): $(OBJ_DRSP)
	$(LD) $(LDFLAGS) $^ -o $@ -L/usr/local/lib -L/usr/lib/ -lm -lgsl -lgslcblas -lcairo -g

$(DSPE): $(OBJ_DSPE)
	$(LD) $(LDFLAGS) $^ -o $@ -L/usr/local/lib -L/usr/lib/ -lm -lgsl -lgslcblas -D_REENTRANT -lpthread -O3

$(DSPB): $(OBJ_DSPB)
	$(LD) $(LDFLAGS) $^ -o $@ -L/usr/local/lib -L/usr/lib/ -lm -lgsl -lgslcblas -D_REENTRANT -lpthread -O3

$(DEXT): $(OBJ_DEXT)
	$(LD) $(LDFLAGS) $^ -o $@ -L/usr/local/lib -L/usr/lib/ -lm -lgsl -lgslcblas -D_REENTRANT -lpthread -O3

$(SIST): $(OBJ_SIST)
	$(LD) $(LDFLAGS) $^ -o $@ -L/usr/local/lib -L/usr/lib/ -lm -O3

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *~ *.log Makefile.d

distclean: clean
	$(RM) $(EXE)

Makefile.d: $(SRC)
	$(CC) -MM $(CFLAGS) $(SRC) > Makefile.d

-include Makefile.d
