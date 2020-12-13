
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// Setting section to create input
void setInput(int numberOfElement, int *inputPins, char port);
// Selected port entirely output
void allOfThemOut(char port);
// 0-9 count
void countToNine(char port);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


