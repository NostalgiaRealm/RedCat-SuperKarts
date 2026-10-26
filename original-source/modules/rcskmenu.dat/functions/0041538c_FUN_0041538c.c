/*
 * FUN_0041538c at 0041538c
 * undefined FUN_0041538c(void)
 * Address ranges: 0041538c-004153d4;004153e4-004153ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041538c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_004153d5;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  (**(code **)**(undefined4 **)(in_stack_00000004 + 0xc))
            (*(undefined4 **)(in_stack_00000004 + 0xc),in_stack_00000008);
  iVar1 = FUN_004118b0(*(int **)(in_stack_00000004 + 0xc));
  if (iVar1 >> 0x1f == in_stack_0000000c && iVar1 == in_stack_00000008) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  *in_FS_OFFSET = uStack_1c;
  return uVar2;
}

