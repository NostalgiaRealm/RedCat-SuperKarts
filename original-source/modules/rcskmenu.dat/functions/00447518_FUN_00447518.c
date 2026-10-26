/*
 * FUN_00447518 at 00447518
 * undefined4 __register FUN_00447518(void)
 * Address ranges: 00447518-0044753e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00447518(void)

{
  int iVar1;
  int in_stack_00000004;
  
  iVar1 = *(int *)(*(int *)(in_stack_00000004 + -4) + 0x14);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 0xc) != 0) break;
    iVar1 = *(int *)(iVar1 + 0x14);
  }
  return 1;
}

