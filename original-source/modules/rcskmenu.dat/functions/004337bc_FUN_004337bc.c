/*
 * FUN_004337bc at 004337bc
 * undefined FUN_004337bc(void)
 * Address ranges: 004337bc-00433868
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004337bc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_14 = &LAB_00433869;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
  param_1[0x10] = iVar1;
  if (((param_1[9] < 1) || (0x8000 < param_1[9])) ||
     (uVar3 = extraout_ECX, uVar4 = extraout_EDX, param_1[10] < 1)) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c6e0,(int *)&puStack_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',puStack_8);
    FUN_00403604(piVar2);
    uVar3 = extraout_ECX_00;
    uVar4 = extraout_EDX_00;
  }
  param_1[0xb] = 4;
  *(undefined1 *)((int)param_1 + 0x35) = 1;
  FUN_00434290(param_1,CONCAT31((int3)((uint)uVar4 >> 8),2),uVar3);
  *(undefined1 *)((int)param_1 + 0x37) = 0;
  param_1[0xe] = 0x1fffffff;
  param_1[0xf] = 0x1fffffff;
  piVar2 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_01);
  param_1[0x11] = (int)piVar2;
  FUN_00433888((int)param_1);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00433870;
  puStack_14 = (undefined1 *)0x433868;
  FUN_00403b50((int *)&puStack_8);
  return;
}

