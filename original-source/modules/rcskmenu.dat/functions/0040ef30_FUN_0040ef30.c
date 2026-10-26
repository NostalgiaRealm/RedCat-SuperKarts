/*
 * FUN_0040ef30 at 0040ef30
 * undefined __register FUN_0040ef30(undefined4 param_1, int param_2)
 * Address ranges: 0040ef30-0040ef63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ef30(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  for (iVar1 = param_2; -1 < iVar1; iVar1 = iVar1 + -1) {
  }
  puVar2 = (undefined4 *)&stack0xfffffff4;
  if (-1 < param_2) {
    iVar1 = param_2 + 1;
    do {
      FUN_0040ee34((undefined **)*puVar2);
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

