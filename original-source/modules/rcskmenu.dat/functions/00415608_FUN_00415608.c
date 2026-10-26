/*
 * FUN_00415608 at 00415608
 * undefined FUN_00415608(void)
 * Address ranges: 00415608-0041566c;0041567c-00415684
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00415608(void)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  int in_stack_00000008;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_0041566d;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if (in_stack_00000008 != 0) {
    *(undefined4 *)(in_stack_00000008 + 4) = 2;
    iVar1 = FUN_004118b0(*(int **)(in_stack_00000004 + 0xc));
    *(int *)(in_stack_00000008 + 8) = iVar1;
    *(int *)(in_stack_00000008 + 0xc) = iVar1 >> 0x1f;
    *(undefined4 *)(in_stack_00000008 + 0x10) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x14) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x18) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x1c) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x20) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x24) = 0;
    *(undefined4 *)(in_stack_00000008 + 0x2c) = 1;
  }
  *in_FS_OFFSET = uStack_1c;
  return 0;
}

