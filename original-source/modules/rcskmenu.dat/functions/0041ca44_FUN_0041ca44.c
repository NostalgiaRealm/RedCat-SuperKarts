/*
 * FUN_0041ca44 at 0041ca44
 * undefined __register FUN_0041ca44(int param_1)
 * Address ranges: 0041ca44-0041ca64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ca44(int param_1)

{
  int iVar1;
  
  FUN_0041cce0(param_1);
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  FUN_0040bfec((undefined4 *)(iVar1 + 0x6c));
  return;
}

