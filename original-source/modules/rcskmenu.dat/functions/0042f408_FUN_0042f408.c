/*
 * FUN_0042f408 at 0042f408
 * undefined4 __register FUN_0042f408(void)
 * Address ranges: 0042f408-0042f458
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042f408(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_stack_00000004;
  int *in_stack_0000000c;
  
  cVar1 = IsEqualGUID();
  if ((cVar1 == '\0') && (cVar1 = IsEqualGUID(), cVar1 == '\0')) {
    uVar2 = FUN_00414f14();
    return uVar2;
  }
  FUN_004054a8(in_stack_0000000c,*(int **)(in_stack_00000004 + 0x238));
  return 0;
}

