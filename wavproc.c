#include <stdio.h>

/* Function that converts bytes from little endian to big endian */
unsigned int convertToBigEndian(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4 ) { 
    
    unsigned int int_char1 = (unsigned int) c4 << 24;
    unsigned int int_char2 = (unsigned int) c3 << 16;
    unsigned int int_char3 = (unsigned int) c2 << 8;
    unsigned int int_char4 = (unsigned int) c1;
    unsigned int bigendian = int_char1 + int_char2 + int_char3 + int_char4;

    return bigendian;
}

int main(){
    unsigned int byte = 0, format, format1, format2, format3, format4, 
        sizeOfFile, monoStereo, sr1, sr2, sr3, sr4, samplerate, 
        bps1, bps2, bps3, bps4, bytespersec, ba1, ba2, 
        blockalign, bpsam1, bpsam2, bitspersample, sizeofdata, waveformat;
    char char1_sof, char2_sof, char3_sof, char4_sof, char1, char2, char3, char4;
    float blockalignmenttest;
    int inerror = 0; 
    int ch = getchar();

    while ((ch != EOF) && (!inerror)) {
        byte++;

        switch (byte) {
                case 1: 
                        if (ch != 'R') {
                                inerror = 1;
                                fprintf(stderr, "Error! \"RIFF\" not found\n");
                        }
                        break;

                case 2: 
                        if (ch != 'I'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"RIFF\" not found\n");
                        }
                        break;

                case 3: 
                        if (ch != 'F'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"RIFF\" not found\n");
                        }
                        break;

                case 4: 
                        if (ch != 'F'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"RIFF\" not found\n");
                        }
                        break;  
                        
                case 5: char1_sof = ch;
                        break;

                case 6: char2_sof = ch;
                        break;

                case 7: char3_sof = ch;
                        break;

                case 8: 
                        char4_sof = ch;
                        sizeOfFile = convertToBigEndian(char1_sof, char2_sof, char3_sof, char4_sof);
                        fprintf(stderr, "size of file: %u\n", sizeOfFile);
                        break;

                case 9: 
                        if (ch != 'W') {
                                inerror = 1;
                                fprintf(stderr, "Error! \"WAVE\" not found\n");
                        }
                        break;

                case 10: 
                        if ( ch != 'A'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"WAVE\" not found\n");
                        }
                        break;

                case 11: 
                        if ( ch != 'V') {
                                inerror = 1;
                                fprintf(stderr, "Error! \"WAVE\" not found\n");
                        }
                        break;

                case 12: 
                        if ( ch != 'E'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"WAVE\" not found\n");
                        }
                        break;

                case 13: 
                        if ( ch != 'f'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"fmt\" not found\n");
                        }
                        break;

                case 14: 
                        if ( ch != 'm') {
                                inerror = 1;
                                fprintf(stderr, "Error! \"fmt\" not found\n");
                        }
                        break;

                case 15: 
                        if ( ch != 't'){
                                inerror = 1; 
                                fprintf(stderr, "Error! \"fmt\" not found\n");
                        }
                        break;

                case 16: 
                        if ( ch != ' '){
                                inerror = 1;
                                fprintf(stderr, "Error! \"fmt\" not found\n");
                        }
                        break;

                case 17: 
                        format1 = ch;
                        break;
                
                case 18: 
                        format2 = ch;
                        break;

                case 19: 
                        format3 = ch;
                        break;

                case 20: 
                        format4 = ch;
                        format = convertToBigEndian(format1, format2, format3, format4);
                        fprintf(stderr, "size of format chunk: %d\n", format);
                        if (format != 0x10) {
                                fprintf(stderr, "Error! size of format chunk should be 16\n");
                                inerror = 1;
                        }
                        break;

                case 21:  
                        char1 = ch;
                        break;

                case 22: 
                        waveformat = convertToBigEndian(char1, (unsigned int) ch, 0, 0);
                        fprintf(stderr, "WAVE type format: %u\n", waveformat);
                        if (waveformat != 0x01) {
                                fprintf(stderr, "Error! WAVE type format should be 1\n");
                                inerror = 1;
                        }
                                        
                        break;

                case 23: 
                        char1 = ch;
                        break;

                case 24: 
                        char2 = ch;
                        monoStereo = convertToBigEndian(char1, char2, 0x00, 0x00);
                        fprintf(stderr, "mono/stereo: %u\n", monoStereo);
                        if (monoStereo > 2) {
                                fprintf(stderr,"Error! mono/stereo should be 1 or 2\n");
                                inerror = 1;
                        }
                        break;

                case 25: 
                        sr1 = ch;
                        break;

                case 26: 
                        sr2 = ch;
                        break;
                
                case 27: 
                        sr3 = ch;
                        break;
                        
                case 28: 
                        sr4 = ch;
                        samplerate = convertToBigEndian(sr1, sr2, sr3, sr4);
                        fprintf(stderr, "sample rate: %d\n", samplerate);
                        break;

                case 29: 
                        bps1 = ch;
                        break;
                
                case 30: 
                        bps2 = ch;
                        break;

                case 31: 
                        bps3 = ch;
                        break;

                case 32: 
                        bps4 = ch;
                        bytespersec = convertToBigEndian(bps1, bps2, bps3, bps4);
                        fprintf(stderr, "bytes/sec: %d\n", bytespersec);
                        break;

                case 33: 
                        ba1 = ch;
                        break;

                case 34: 
                        ba2 = ch;
                        blockalign = convertToBigEndian(ba1, ba2, 0x00, 0x00);
                        fprintf(stderr, "block alignment: %d\n", blockalign); 
                        
                        if (bytespersec != samplerate * blockalign){
                                inerror = 1;
                                fprintf( stderr, "Error! bytes/second should be sample rate x block alignment\n");
                        }        
                        break;

                case 35: 
                        bpsam1 = ch;
                        break;
                
                case 36: 
                        bpsam2 = ch;
                        bitspersample = convertToBigEndian(bpsam1, bpsam2, 0x00, 0x00);
                        fprintf(stderr, "bits/sample: %d\n", bitspersample);
                        
                        if (!((bitspersample == 8) || (bitspersample == 16))) {
                                fprintf(stderr, "Error! bits/sample should be 8 or 16\n");
                                inerror = 1;
                                break;
                        }      

                        blockalignmenttest = bitspersample/8 * monoStereo;  

                        if ((float)blockalign != blockalignmenttest) {
                                fprintf(stderr,"Error! block alignment should be bits per sample / 8 x mono/stereo\n");
                                inerror = 1;
                        }

                        break;

                case 37: 
                        if (ch != 'd'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"data\" not found \n");
                        }
                        break; 

                case 38: 
                        if (ch != 'a'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"data\" not found \n");
                        }
                        break; 
                
                case 39: 
                        if (ch != 't'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"data\" not found \n");
                        }
                        break; 
                case 40: 
                        if (ch != 'a'){
                                inerror = 1;
                                fprintf(stderr, "Error! \"data\" not found \n");
                        }
                        break; 

                case 41: 
                        char1 = ch;
                        break;

                case 42: 
                        char2 = ch;
                        break;

                case 43: 
                        char3 = ch;
                        break;

                case 44: 
                        char4 = ch;
                        sizeofdata = convertToBigEndian(char1, char2, char3, char4);
                        fprintf(stderr,"size of data chunk: %u\n", sizeofdata);
                        break;
        }  

        ch = getchar();       
    }

    if (byte-44 < sizeofdata) {
            fprintf(stderr, "Error! Insufficient data. bytes read=%u, expected=%u\n", byte-44, sizeofdata);
    } 
    else {
        if (!inerror){
            if (sizeOfFile != (byte - 8)) {
                    fprintf(stderr, "Error! bad file size. expected number of bytes=%u Number of bytes read=%u \n", sizeOfFile, byte-8);
            }

        }
    }
    return 0;

}