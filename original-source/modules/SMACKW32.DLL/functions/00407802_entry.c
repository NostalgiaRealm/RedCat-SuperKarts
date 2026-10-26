/*
 * entry at 00407802
 * int __fastcall entry(undefined4 param_1, uint param_2, undefined4 param_3, int param_4, undefined4 param_5)
 * Address ranges: 00407802-00407806
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00407d43
 */

int __fastcall
entry(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  int unaff_EBX;
  longlong lVar3;
  undefined8 uVar4;
  
  switch(param_4) {
  case 0:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408c11(extraout_ECX_04,0xff);
    uVar2 = extraout_ECX_05;
    if (DAT_0040f058 != (code *)0x0) {
      (*DAT_0040f058)(param_3,param_4,param_5);
      uVar2 = extraout_ECX_06;
    }
    FUN_00408c11(uVar2,0xf);
    FUN_00408984();
    DAT_004104ec = DAT_004104ec + -1;
    break;
  case 1:
    DAT_004104ec = DAT_004104ec + 1;
    if ((DAT_004104ec < 2) || (uVar4 = FUN_00408d3e(param_1,DAT_004104ec), (int)uVar4 == 0)) {
      FUN_00408bc6();
      iVar1 = FUN_00407892(extraout_ECX,0);
      if (iVar1 != 0) {
        uVar4 = FUN_004088eb(extraout_ECX_00,extraout_EDX);
        if (((int)uVar4 != 0) &&
           (lVar3 = FUN_00408937(extraout_ECX_01,(uint)((ulonglong)uVar4 >> 0x20)), (int)lVar3 != 0)
           ) {
          FUN_00408bc6();
          FUN_004089fb();
          if ((DAT_0040f058 == (code *)0x0) ||
             (iVar1 = (*DAT_0040f058)(param_3,param_4,param_5), iVar1 != 0)) {
            FUN_00408bc6();
            FUN_00408e0e();
            iVar1 = FUN_00408d25(param_3,param_4);
            if (iVar1 != 0) {
              return iVar1;
            }
            FUN_00408c11(extraout_ECX_03,0xff);
            return 0;
          }
          FUN_00408c11(extraout_ECX_02,0xf);
        }
      }
    }
    unaff_EBX = 0;
    break;
  case 2:
    lVar3 = FUN_00408937(param_1,param_2);
    unaff_EBX = 0;
    if ((int)lVar3 != 0) {
      unaff_EBX = FUN_00408d25(param_3,param_4);
    }
    break;
  case 3:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408984();
  }
  return unaff_EBX;
}

