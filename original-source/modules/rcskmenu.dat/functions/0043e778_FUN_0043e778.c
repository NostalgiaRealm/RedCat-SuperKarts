/*
 * FUN_0043e778 at 0043e778
 * undefined4 __register FUN_0043e778(int param_1)
 * Address ranges: 0043e778-0043e79e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043e778(int param_1)

{
  int iVar1;
  char cVar2;
  
  cVar2 = FUN_00415024();
  if ((cVar2 != '\0') &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x108),
     iVar1 == *(int *)(*(int *)(param_1 + 0x10) + 0x30))) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

