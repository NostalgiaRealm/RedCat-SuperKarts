/*
 * FUN_0041cdec at 0041cdec
 * undefined FUN_0041cdec(void)
 * Address ranges: 0041cdec-0041cdf9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041cdec(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x20) + 0x20);
  uVar2 = (int)uVar1 >> 0x1f;
  return (uVar1 ^ uVar2) - uVar2;
}

