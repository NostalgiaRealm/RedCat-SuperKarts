/*
 * FUN_00409c00 at 00409c00
 * undefined __fastcall FUN_00409c00(undefined4 param_1, int * param_2)
 * Address ranges: 00409c00-00409c84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00409c00(undefined4 param_1,int *param_2)

{
  uint *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint unaff_EBP;
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  
  DAT_0040e9c0 = DAT_0040e9c0 + -1;
  if (DAT_0040e9c0 == '\0') {
    unaff_EBP = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    DAT_0040e9c0 = ' ';
  }
  uVar1 = unaff_EBP >> 1;
  if ((unaff_EBP & 1) == 0) {
    *param_2 = 0;
    param_2[1] = (int)in_EAX;
    param_2[2] = (int)in_EAX;
    param_2[3] = (int)in_EAX;
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 + -1;
    if (DAT_0040e9c0 == '\0') {
      uVar1 = *unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
      DAT_0040e9c0 = ' ';
    }
    uVar2 = uVar1 >> 1;
    if ((uVar1 & 1) != 0) {
      FUN_00409800();
      param_1 = extraout_ECX;
    }
    DAT_0040e9c0 = DAT_0040e9c0 + -1;
    if (DAT_0040e9c0 == '\0') {
      uVar2 = *unaff_ESI;
      DAT_0040e9c0 = ' ';
    }
    if ((uVar2 & 1) != 0) {
      FUN_00409800();
      param_1 = extraout_ECX_00;
    }
    FUN_004098a0(param_1,param_2);
    FUN_00409b90(extraout_ECX_01,in_EAX);
  }
  return;
}

