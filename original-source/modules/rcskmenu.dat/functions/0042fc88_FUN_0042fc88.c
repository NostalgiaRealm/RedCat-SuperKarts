/*
 * FUN_0042fc88 at 0042fc88
 * bool __register FUN_0042fc88(void)
 * Address ranges: 0042fc88-0042fcac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0042fc88(void)

{
  bool bVar1;
  int in_stack_00000004;
  
  bVar1 = true;
  if (*(int *)(in_stack_00000004 + -4) != 0) {
    bVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x28) !=
            *(int *)(*(int *)(in_stack_00000004 + -4) + 0x28);
  }
  return bVar1;
}

