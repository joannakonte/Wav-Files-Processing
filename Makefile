# Paths
WAV = ./wav_files

# Object files
OBJ = wavproc.o 

# Executable
EXEC = wavproc

$(EXEC): $(OBJ)
	gcc $(OBJ) -o $(EXEC)

run: $(EXEC)
	  ./$(EXEC) < $(WAV)/bad_wtf.wav

clean:
	rm -f $(OBJ) $(EXEC) 