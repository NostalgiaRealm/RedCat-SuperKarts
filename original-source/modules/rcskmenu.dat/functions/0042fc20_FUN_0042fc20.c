/*
 * FUN_0042fc20 at 0042fc20
 * undefined4 __register FUN_0042fc20(void)
 * Address ranges: 0042fc20-0042fc51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042fc20(void)

{
  int iVar1;
  int in_stack_00000004;
  
  if (*(int *)(in_stack_00000004 + -4) != 0) {
    iVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x2c);
    return CONCAT31((int3)((uint)iVar1 >> 8),
                    iVar1 != *(int *)(*(int *)(in_stack_00000004 + -4) + 0x2c));
  }
  return CONCAT31((int3)((uint)*(int *)(in_stack_00000004 + -8) >> 8),
                  *(int *)(*(int *)(in_stack_00000004 + -8) + 0x2c) != 0);
}

