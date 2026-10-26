/*
 * FUN_00407f92 at 00407f92
 * undefined8 __fastcall FUN_00407f92(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407f92-00407fca;00408099-004080f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00407f92(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  uint uVar3;
  undefined4 extraout_EDX_00;
  ulonglong uVar4;
  code *pcVar5;
  
  uVar4 = (*(code *)PTR_FUN_0040ef44)();
  uVar3 = (uint)(uVar4 >> 0x20);
  pcVar5 = *(code **)((int)uVar4 + 0x58 + in_EAX * 8);
  if (uVar4 < 0x200000000) {
    if (uVar3 == 1) {
      if (pcVar5 == (code *)0x2) {
        FUN_00408e57(extraout_ECX);
        uVar3 = extraout_EDX;
      }
LAB_004080b9:
      if (((pcVar5 != (code *)0x1) && (pcVar5 != (code *)0x2)) && (pcVar5 != (code *)0x3)) {
        iVar2 = (*(code *)PTR_FUN_0040ef44)(pcVar5,param_2,param_1);
        *(undefined4 *)(iVar2 + 0x58 + uVar3 * 8) = 2;
        (*pcVar5)();
      }
      iVar2 = FUN_00407eeb();
      if (iVar2 == 0) {
        FUN_00407f56(extraout_ECX_00,extraout_EDX_00);
      }
      goto LAB_004080ee;
    }
  }
  else {
    if (uVar4 < 0x300000000) {
      FUN_00407fcb(extraout_ECX,uVar3);
LAB_004080ee:
      uVar1 = 0;
      goto LAB_004080f0;
    }
    if (uVar4 < 0xd00000000) goto LAB_004080b9;
  }
  uVar1 = 0xffffffff;
LAB_004080f0:
  return CONCAT44(param_2,uVar1);
}

