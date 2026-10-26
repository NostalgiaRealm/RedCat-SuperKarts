/*
 * FUN_0046a0ec at 0046a0ec
 * undefined FUN_0046a0ec(void)
 * Address ranges: 0046a0ec-0046a179
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046a0ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *in_FS_OFFSET;
  int *piVar1;
  undefined4 uStack_38;
  undefined *puStack_34;
  undefined1 *puStack_30;
  undefined1 auStack_28 [2];
  ushort uStack_26;
  ushort auStack_20 [4];
  uint uStack_18;
  undefined1 uStack_14;
  uint uStack_10;
  undefined1 uStack_c;
  int iStack_8;
  
  puStack_30 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_34 = &UNK_0046a17a;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  piVar1 = &iStack_8;
  FUN_00469938(param_1,auStack_20);
  uStack_18 = (uint)auStack_20[0];
  uStack_14 = 0;
  FUN_00469938(param_1,auStack_28);
  uStack_10 = (uint)uStack_26;
  uStack_c = 0;
  FUN_00408a5c(&UNK_0046a190,&uStack_18,1,piVar1);
  piVar1 = *(int **)(*(int *)(*(int *)(param_4 + -4) + 0x304) + 0x1f0);
  (**(code **)(*piVar1 + 0x38))(piVar1,iStack_8,param_1);
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &UNK_0046a181;
  puStack_34 = (undefined *)0x46a179;
  FUN_00403b50(&iStack_8);
  return;
}

