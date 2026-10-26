/*
 * FUN_0042fbf8 at 0042fbf8
 * bool __register FUN_0042fbf8(void)
 * Address ranges: 0042fbf8-0042fc1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0042fbf8(void)

{
  bool bVar1;
  int in_stack_00000004;
  
  bVar1 = true;
  if (*(int *)(in_stack_00000004 + -4) != 0) {
    bVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x24) !=
            *(int *)(*(int *)(in_stack_00000004 + -4) + 0x24);
  }
  return bVar1;
}

