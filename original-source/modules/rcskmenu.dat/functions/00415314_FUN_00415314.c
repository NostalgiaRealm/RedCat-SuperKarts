/*
 * FUN_00415314 at 00415314
 * undefined FUN_00415314(void)
 * Address ranges: 00415314-00415372;00415382-0041538a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00415314(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  undefined4 in_stack_00000008;
  int in_stack_00000010;
  int *in_stack_00000014;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_00415373;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if ((in_stack_00000010 < 0) || (2 < in_stack_00000010)) {
    uVar2 = 0x80030001;
    *in_FS_OFFSET = uStack_1c;
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_stack_00000004 + 0xc) + 0xc))
                      (*(int **)(in_stack_00000004 + 0xc),in_stack_00000008);
    if (in_stack_00000014 != (int *)0x0) {
      *in_stack_00000014 = iVar1;
      in_stack_00000014[1] = iVar1 >> 0x1f;
    }
    uVar2 = 0;
    *in_FS_OFFSET = uStack_1c;
  }
  return uVar2;
}

