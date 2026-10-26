/*
 * FUN_00412c88 at 00412c88
 * undefined __register FUN_00412c88(undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00412c88-00412cfd;00412d21-00412d25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412c88(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_00412cfe;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00403088(*(int **)(param_4 + -0x10),*(undefined4 *)(*(int *)(param_4 + -0xc) + 0x2c),param_3);
  (**(code **)(**(int **)(param_4 + -0xc) + 0x1c))
            (*(int **)(param_4 + -0xc),*(undefined4 *)(param_4 + -0x10),param_4 + -0x18);
  if (DAT_0047d61c != (code *)0x0) {
    iVar2 = (*DAT_0047d61c)(*(undefined4 *)(param_4 + -0x18));
    if (iVar2 == *(int *)(param_4 + -0x10)) {
      puVar1 = (ushort *)(*(int *)(param_4 + -0x10) + 0x20);
      *puVar1 = *puVar1 | 0x200;
    }
  }
  *in_FS_OFFSET = uStack_1c;
  return;
}

