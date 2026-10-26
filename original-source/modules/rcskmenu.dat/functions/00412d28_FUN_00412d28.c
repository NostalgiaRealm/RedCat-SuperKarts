/*
 * FUN_00412d28 at 00412d28
 * undefined __register FUN_00412d28(undefined4 param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00412d28-00412da2;00412dc6-00412dca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412d28(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_00412da3;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar1 = FUN_00414580(*(int *)(param_4 + -0xc),*(char **)(param_4 + -0x14),param_3);
  uVar2 = (**(code **)(**(int **)(param_4 + -0xc) + 0x14))
                    (*(int **)(param_4 + -0xc),*(undefined4 *)(param_4 + -0x18),iVar1);
  *(undefined4 *)(param_4 + -0x10) = uVar2;
  iVar1 = FUN_00403088(*(int **)(param_4 + -0x10),param_4,extraout_ECX);
  *(int *)(*(int *)(param_4 + -0xc) + 0x2c) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(*(int *)(param_4 + -0xc) + 0x2c) =
         *(undefined4 *)(*(int *)(param_4 + -0xc) + 0x18);
  }
  *in_FS_OFFSET = uStack_1c;
  return;
}

