/*
 * FUN_0044087c at 0044087c
 * undefined4 __register FUN_0044087c(void)
 * Address ranges: 0044087c-004408aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044087c(void)

{
  int iVar1;
  int in_stack_00000004;
  
  iVar1 = *(int *)(*(int *)(in_stack_00000004 + -4) + 0x20);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)iVar1 >> 8),
                    *(char *)(iVar1 + 0x4e) != *(char *)(*(int *)(in_stack_00000004 + -8) + 0x4e));
  }
  return CONCAT31((int3)((uint)*(int *)(in_stack_00000004 + -8) >> 8),
                  *(undefined1 *)(*(int *)(in_stack_00000004 + -8) + 0x4e));
}

