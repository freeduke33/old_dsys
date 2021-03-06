

/*
 *   Generated by  UI v2.00 
 *        December 25, 1993
 */


/* Module: MENU\EDT_LOAD.C ===================== */

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
#include <string.h>
#include "dsys.h"
#include "menu.h"

static char  filename[100],pic[74];
static CfgP cfg;

VOID CTYP _set_EXEC(NOARG);
VOID CTYP _act_EXEC(NOARG);
VOID CTYP _MAIN_2STR(NOARG);
VOID CTYP _MAIN_MSG(NOARG);

LCL VOID CTYP _MAIN_MSG(NOARG)
{

 Wshadow(_BLACK|DGREY);
 CurHide();
  Wbprintc(BRD_BOT,3,_BLUE|LGREY,'╡');
  Wmessage("\030" "\031" "\032" "\033" "",BRD_BOT,4,_BLUE|INTENSE|RED);
  Wmessage(" перемещение ",BRD_BOT,8,_BLUE|INTENSE|LGREY);
  Wmessage("Enter",BRD_BOT,21,_BLUE|INTENSE|RED);
  Wmessage(" выбрать ",BRD_BOT,26,_BLUE|INTENSE|LGREY);
  Wmessage("ESC ",BRD_BOT,35,_BLUE|INTENSE|RED);
  Wmessage("отказ",BRD_BOT,39,_BLUE|INTENSE|LGREY);
  Wbprintc(BRD_BOT,44,_BLUE|LGREY,'╞');
  Wbprintc(BRD_RGT,1,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,2,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,3,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,4,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,5,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,6,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,7,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,8,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,9,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,10,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,11,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,12,_BLUE|LGREY,'▒');
  Wbprintc(BRD_RGT,13,_BLUE|LGREY,'▒');
  return;
}
LCL VOID CTYP _set_EXEC(NOARG)
{
cfg=EdtGetCfg();             
strcpy(pic,cfg->dir_work);   
filename[0]=0;               
strcat(pic,"*.DSF");         
  return;
}
LCL VOID CTYP _act_EXEC(NOARG)
{
                            
 if(filename[0])            
    EdtLoad(filename);      
                            
  return;
}
VOID CTYP EDT_LOAD(NOARG)
{
{
 ChrP MAIN_file;
 KbndP tcxl_old_kb,tcxl_kb=NULL;

  _set_EXEC();
 tcxl_old_kb=KbndChg(tcxl_kb);
  EntResult=0;
  MAIN_file=SelFile(3,18,17,64,BOX_DBL,_BLUE|LGREY,_BLUE|INTENSE|LGREY,_LGREY|BLACK,
          1,pic,_MAIN_MSG);
   if(MAIN_file!=NULL)
     {
     strcpy(filename,MAIN_file);
     SelFree();
     EntResult=1;
     }

 KbndChg(tcxl_old_kb);
  _act_EXEC();
}
  return;
}

/*** END OF FILE ***/
