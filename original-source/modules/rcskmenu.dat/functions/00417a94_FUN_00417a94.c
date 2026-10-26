/*
 * FUN_00417a94 at 00417a94
 * undefined FUN_00417a94(void)
 * Address ranges: 00417a94-00417b15;00417b3a-00417b49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417a94(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x417aaf;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00416158);
  if ((char)uVar1 != '\0') {
    puStack_14 = (undefined1 *)0x417abf;
    FUN_00417254((int)param_1);
    puStack_18 = &LAB_00417b33;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    puStack_20 = (undefined1 *)0x417ad7;
    puStack_14 = &stack0xfffffffc;
    FUN_00417254((int)param_2);
    puStack_24 = &LAB_00417b16;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    FUN_00416d34(DAT_0047d6cc,param_1,(undefined4 *)param_2[4]);
    FUN_00417c7c(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),(char)param_2[6]),extraout_ECX);
    *in_FS_OFFSET = uStack_28;
    puStack_20 = &LAB_00417b1d;
    puStack_24 = (undefined1 *)0x417b15;
    FUN_00417264((int)param_2);
    return;
  }
  puStack_14 = (undefined1 *)0x417b45;
  FUN_0040fca8(param_1,param_2);
  return;
}

