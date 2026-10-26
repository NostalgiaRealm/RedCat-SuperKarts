/*
 * FUN_0041ce10 at 0041ce10
 * undefined4 __register FUN_0041ce10(int param_1)
 * Address ranges: 0041ce10-0041ce29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041ce10(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*(short *)(iVar1 + 0x28) == 1) && (*(short *)(iVar1 + 0x2a) == 1)) {
    return CONCAT31((int3)((uint)(iVar1 + 0x18) >> 8),1);
  }
  return 0;
}

