

/*
 *   Generated by  UI v2.00 
 *        December 25, 1993
 */


/* Module: MENU\NEW_ZD.C ===================== */

#include <string.h>
#include <stdlib.h>

#include <tcxlcur.h>
#include <tcxlnls.h>
#include <tcxlwin.h>
#include <tcxlent.h>
#include <tcxlmnu.h>
#include <tcxlcod.h>
#include <tcxlinp.h>
#include <tcxlsel.h>
#include <tcxlstr.h>
#include <tcxlvid.h>
#include <tcxlhlp.h>

#define HLP_NONE 1


#ifndef __Struct_WDEF_
#define __Struct_WDEF_

       struct _WDEF
         {
         IntT BegC,BegR,EndC,EndR;   /* положение окна    */
         IntT MniC,MniR,MaxC,MaxR;   /* возможные размеры */
         BytT FrmT;                  /* тип бордюра       */
         AtrT FrmA;                  /* атрибуты бордюра  */
         AtrT Dat;                   /* атрибуты текста   */
         BytT Shadow;                /* тень              */
         AtrT Sat;                   /* цвет тени         */
         };
#endif

#ifdef __cplusplus
  extern "C" {
#endif
VOID CTYP MnuDsp(MbldP mnu);
KeyT CTYP EntSelect(NOARG);
GBL  IntT EntSelAct;
LCL  IntT EntResult;
#ifdef __cplusplus
   }
#endif
#include "menu.h"
#include "dsys.h"

extern ParamT ParBuf;


VOID CTYP _main_2STR(NOARG);
VOID CTYP _main_MSG(NOARG);


LCL VOID CTYP _opt1_ACT(NOARG)
{
ParBuf.U.DifZveno.Group=0;
ZVENO_D();
return;
}

LCL VOID CTYP _opt2_ACT(NOARG)
{
ParBuf.U.DifZveno.Group=-2;
return;
}

LCL IbldT _main_Itm[]={
{" Брать схему из файла ",'',ITM_NOR|ITM_AFT,0,0,  1,HLP_NONE,
   0,2,NULL,_opt1_ACT,NULL,
   "",NULL},
{" Создать новую группу ",'',ITM_NOR|ITM_AFT,1,0,  3,HLP_NONE,
   0,4,NULL,_opt2_ACT,NULL,
   "",NULL},
};


LCL VOID CTYP _main_MSG(NOARG);
LCL MbldT _main_Mnu={
   _main_Itm,2,14,28,17,51,  MNU_OMN|MNU_SAV|MNU_DSP|MNU_NQS,BOX_DBL,
   _BLUE|LGREY,_BLUE|INTENSE|LGREY,_BLUE|INTENSE|LGREY,
   _BLUE|BLACK,_BLUE|BLACK,_LGREY|BLACK,
   0,_main_MSG,5, 10,0,0, 0xff,0xff,0xff};

LCL VOID CTYP _main_MSG(NOARG)
{

 Wshadow(_BLACK|DGREY);
 CurHide();
  Wmessage("╡Сложное звено╞",BRD_TOP,4,_BLUE|LGREY);
  {
  MnuDsp(&_main_Mnu);
  }
  return;
}
VOID CTYP NEW_ZD(NOARG)
{
{
 KbndP tcxl_old_kb,tcxl_kb=NULL;

 MbldTag(&_main_Mnu)=IbldTag(&_main_Itm[0]);
 tcxl_old_kb=KbndChg(tcxl_kb);

 MnuBuild(&_main_Mnu);
 MnuGet();
 KbndChg(tcxl_old_kb);
}
  return;
}

/*** END OF FILE ***/
