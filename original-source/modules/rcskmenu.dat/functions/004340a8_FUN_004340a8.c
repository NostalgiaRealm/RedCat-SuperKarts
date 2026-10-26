/*
 * FUN_004340a8 at 004340a8
 * undefined FUN_004340a8(void)
 * Address ranges: 004340a8-00434164
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004340a8(int *param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  HIMAGELIST p_Var3;
  COLORREF CVar4;
  uint uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int cx;
  int cy;
  
  if (param_2 == (int *)0x0) {
    FUN_00433a14(param_1);
    return;
  }
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_00433640);
  if ((char)uVar2 == '\0') {
    FUN_0040fca8(param_1,param_2);
  }
  else {
    FUN_00433c60(param_1);
    *(undefined1 *)((int)param_1 + 0x35) = *(undefined1 *)((int)param_2 + 0x35);
    *(undefined1 *)((int)param_1 + 0x37) = *(undefined1 *)((int)param_2 + 0x37);
    FUN_00434290(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),(char)param_2[0xd]),extraout_ECX);
    *(undefined1 *)((int)param_1 + 0x36) = *(undefined1 *)((int)param_2 + 0x36);
    p_Var3 = (HIMAGELIST)FUN_004339b0(param_2);
    FUN_0043394c((int)param_1,p_Var3);
    bVar1 = FUN_00433874((int)param_1);
    if (bVar1) {
      cy = param_1[9];
      cx = param_1[10];
      p_Var3 = (HIMAGELIST)FUN_004339b0(param_1);
      ImageList_SetIconSize(p_Var3,cx,cy);
    }
    else {
      FUN_0043387c(param_1);
    }
    p_Var3 = (HIMAGELIST)FUN_004339b0(param_2);
    CVar4 = ImageList_GetBkColor(p_Var3);
    uVar5 = FUN_004336e4(CVar4);
    FUN_00433c6c(param_1,uVar5);
    param_1[0xf] = param_2[0xf];
    FUN_00434088(param_1,param_2);
  }
  return;
}

