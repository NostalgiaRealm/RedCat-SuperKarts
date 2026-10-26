/*
 * FUN_00405538 at 00405538
 * LONG __register FUN_00405538(void)
 * Address ranges: 00405538-0040555f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LONG FUN_00405538(void)

{
  LONG LVar1;
  int *in_stack_00000004;
  
  LVar1 = InterlockedDecrement(in_stack_00000004 + 1);
  if (LVar1 == 0) {
    (**(code **)(*in_stack_00000004 + -4))(in_stack_00000004,1);
  }
  return LVar1;
}

