/*
 * FUN_00436004 at 00436004
 * undefined4 __register FUN_00436004(int param_1)
 * Address ranges: 00436004-0043602a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00436004(int param_1)

{
  int iVar1;
  char cVar2;
  
  cVar2 = FUN_00415024();
  if ((cVar2 != '\0') &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x80),
     iVar1 == *(int *)(*(int *)(param_1 + 0x10) + 0x30))) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

