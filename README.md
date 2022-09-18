# PROCESSING WAV ENCODED AUDIO FILES

The program checks if the data given follows the Waveform Audio File Format standard described below and prints the relevant audio information like the size of the file and the bits of the file.

## What is a WAV audio file format?
A WAV file is a lossless audio format that does not compress the original analog audio recording from which it is derived. Microsoft and IBM pioneered the Waveform audio file format, and it is now widely used by digital music companies around the world. As a lossless format, WAV files offer a very high sample rate and bit depth, which permits them to include all the frequencies heard by the human ear.

## WAV File Format
The WAVE file format, being a subset of Microsoft’s RIFF specification, starts with a file header followed by a sequence of data chunks. A WAVE file has a single “WAVE” chunk which consists of two sub-chunks:

a “fmt” chunk - specifies the data format
a “data” chunk - contains the actual sample data

## WAV File Header
The header of a WAV (RIFF) file is 44 bytes long and has the following format:

| Positions | Sample Value | Description |
| ------ | ----------- | ----------- |
| 1 - 4  | "RIFF" | Marks the file as a riff file. Characters are each 1 byte long. |
| 5 - 8  | File size (integer) | Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you’d fill this in after creation. |
| 9 - 12 | “WAVE” | File Type Header. For our purposes, it always equals “WAVE”. | 
| 13 - 16| “fmt " | Format chunk marker. |
| 17 - 20 | 16 | Length of format data as listed above. |
| 21 - 22 | 1 | Type of WAVE format ( for this project this is always equal to 1) - 2 byte integer |
| 23 - 24 | 2 | Number of Channels - 2 byte integer |
| 25 - 28 | 44100 | Sample Rate = Number of Samples per second. |
| 29 - 32 | 88200 | Bytes Per Second. |
| 33 - 32 | 4 | Block Alignment. The number of bytes required to record the audio information at one time, for all channels. BytesPerSec = SampleRate × BlockAlign.
| 33 - 34 | 16 | Bits per sample. |
| 37 - 40 | "data" | “data” chunk header. Marks the beginning of the data section. |
| 41 - 44 | File size (data) | Size of the data section. |

## Makefile

Use the Makefile to compile, run and clean using the following commands:

```bash
$ make 
$ make run
$ make clean
```
**Note:** `make run`, does the following: ``$./wavproc < wav_files/bad_wtf.wav

If you want to try use other wav files included in this repository, you can do so by changing the following in the Makefile:

```bash
run: $(EXEC)
	  ./$(EXEC) < $(WAV)/addfilehere.wav
```

Resources:
https://www.masterclass.com/articles/a-guide-to-audio-file-formats#5UmTBYIj1EAyS6s3CNuhHb 
https://docs.fileformat.com/audio/wav/ 

