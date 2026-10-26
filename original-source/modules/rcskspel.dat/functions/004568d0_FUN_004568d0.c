/*
 * FUN_004568d0 at 004568d0
 * undefined FUN_004568d0(void)
 * Address ranges: 004568d0-00456917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004568d0(int param_1,int param_2)

{
  undefined4 uVar1;
  float *pfVar2;
  int iVar3;
  
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f21a8,0x32e);
  FUN_00430dd0(param_2,100,uVar1);
  iVar3 = 3;
  pfVar2 = (float *)(&DAT_00543d70 + param_1 * 0x60);
  do {
    *pfVar2 = (float)param_2;
    pfVar2 = pfVar2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

