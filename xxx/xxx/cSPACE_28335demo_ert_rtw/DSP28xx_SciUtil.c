/*
 * File: DSP28xx_SciUtil.c
 *
 * Code generated for Simulink model 'cSPACE_28335demo'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Feb 16 06:26:32 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DSP28xx_SciUtil.h"

/* Transmit character(s) from the SCIa*/
void scia_xmit(char* pmsg, int msglen, int typeLen)
{
  int i,j,k;
  if (typeLen==1) {
    for (i = 0; i < msglen; i++) {
      while (SciaRegs.SCIFFTX.bit.TXFFST == 16) {
      }                                /* The buffer is full;*/

      SciaRegs.SCITXBUF= pmsg[i];
    }

    //while(SciaRegs.SCIFFTX.bit.TXFFST != 0){}
  } else {
    for (i = 0; i < (msglen/2); i++) {
      for (j = 0; j<=1; j++) {
        while (SciaRegs.SCIFFTX.bit.TXFFST == 16) {
        }                              /* The buffer is full;*/

        SciaRegs.SCITXBUF= pmsg[i]>>(8*j);
      }
    }

    //while(SciaRegs.SCIFFTX.bit.TXFFST != 0){}
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
