/*
 * buffer_output.h
 *
 *  Created on: Aug 19, 2016
 *      Author: jimmy
 */

#ifndef INCLUDE_BUFFER_OUTPUT_H_
#define INCLUDE_BUFFER_OUTPUT_H_

#ifdef ENABLE_IOT_BUFDUMP
#define SHOW_BUFFER(ptr,size) \
    {   \
        int i, j;   \
        unsigned char * buf = ptr;   \
        int bufLen = size;    \
        char * codes[] = {"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL"," BS",    \
                        " HT"," LF"," VT"," FF"," CR"," SO"," SI","DLE","DC1",      \
                        "DC2","DC3","DC4","NAK","SYN","ETB","CAN"," EM","SUB",      \
                        "ESC"," FS"," GS"," RS"," US","DEL"};   \
        printf("\n\n ***************START (%d) (%p)****************\n\n", bufLen, buf); \
        if (buf != NULL) { \
            for (i = 0; i < bufLen; i++) { \
                for (j = 0; j < bufLen && j < 10 && i < bufLen; j++, i++) { \
                    if (buf[i] < 32 || buf[i] == 127) { \
                        printf("%s (0x%02x) ", codes[buf[i]], buf[i]); \
                    } else { \
                        printf("%3c (0x%02x) ", buf[i], buf[i]); \
                    }   \
                }   \
                printf("\n");   \
            }   \
        } else {    \
            printf("NULL BUFFER PTR GIVEN\n");  \
        }   \
        printf("\n *******************END********************\n\n");    \
    }   \

#else
#define SHOW_BUFFER(ptr,size)
#endif

#endif /* INCLUDE_BUFFER_OUTPUT_H_ */

