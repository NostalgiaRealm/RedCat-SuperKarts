/*
 * FUN_0041e12c at 0041e12c
 * undefined FUN_0041e12c(void)
 * Address ranges: 0041e12c-0041e167
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e12c(int param_1,int *param_2,int *param_3)

{
  HICON hIcon;
  int cxWidth;
  int cyWidth;
  UINT istepIfAniCur;
  HBRUSH hbrFlickerFreeDraw;
  UINT diFlags;
  
  FUN_00418a68(param_2,1);
  diFlags = 3;
  hbrFlickerFreeDraw = (HBRUSH)0x0;
  istepIfAniCur = 0;
  cyWidth = 0;
  cxWidth = 0;
  hIcon = (HICON)FUN_0041e184(param_1);
  DrawIconEx((HDC)param_2[1],*param_3,param_3[1],hIcon,cxWidth,cyWidth,istepIfAniCur,
             hbrFlickerFreeDraw,diFlags);
  return;
}

