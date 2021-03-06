

/*
 *   Generated by  UI v2.00 
 *        May 4, 1993
 */


/* Module: MOD_PROC.C ===================== */

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


VOID CTYP MnuDsp(MbldP mnu);

VOID CTYP _MAIN_2STR(NOARG);

LCL ChrT  ModName[31]="?????????????";

LCL ChrT MAIN_var1[31];
LCL FbldT _MAIN_Fld[]={
 {"",0,0, MAIN_var1,1,11,
  "******************************",NULL,NULL,NULL,
  0,1,HLP_NONE,
  FLD_NUL|FLD_TRM,0,FLD_CHG},
};

LCL EbldT _MAIN_Frm={
 _MAIN_Fld,1,NULL,NULL,2,0,
 0,_BLUE|INTENSE|LGREY,_LGREY|BLACK,_BLACK|DGREY
};
LCL VOID CTYP _MAIN_2STR(NOARG)
{
  strcpy(MAIN_var1,ModName); strsetsz(MAIN_var1,30);
 return;
}
VOID CTYP MOD_PROC(NOARG)
{
 Wopen(9,18,17,61,BOX_DBL,
       _BLUE|INTENSE|LGREY,_BLUE|INTENSE|LGREY);
 Wshadow(_BLACK|DGREY);
 CurHide();
  Wmessage("╡Моделирование╞",BRD_TOP,14,_BLUE|INTENSE|LGREY);
  Wprts(1,1,_BLUE|INTENSE|LGREY,"Сценарий:");
  Wprts(1,11,_BLUE|INTENSE|LGREY,"12345678901234567890123456789");
  Wprts(3,4,_BLUE|INTENSE|LGREY,"Сборка");
  Wprts(3,11,_BLUE|INTENSE|LGREY,"д.системы");
  Wprts(3,21,_BLUE|INTENSE|LGREY,"...");
  Wprts(3,25,_BLUE|INTENSE|LGREY,"Норма");
  Wprts(4,4,_BLUE|INTENSE|LGREY,"Вычисления");
  Wprts(4,15,_BLUE|INTENSE|LGREY,".........");
  Wprts(4,25,_BLUE|INTENSE|LGREY,"10%");
  Wprts(6,0,_LGREY|BLACK,"        <ESC> прервать вычисления         ");

  _MAIN_2STR();
  EntPush();
  EntBuild(&_MAIN_Frm);
  EntDsp();
  EntFree();
  EntPop();

 MouPush(MOU_FULL);
 CurHide();
 KeyWait();
 CurShow();
 MouPop();
 Wclose();
  return;
}

/*** END OF FILE ***/
