/*
 * FUN_0044cc10 at 0044cc10
 * undefined __register FUN_0044cc10(int param_1)
 * Address ranges: 0044cc10-0044cc35
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044cc10(int param_1)

{
  while (*(int *)(param_1 + 0xc) != 0) {
    FUN_0044cf50(param_1);
  }
  if (*(HGLOBAL *)(param_1 + 8) != (HGLOBAL)0x0) {
    FreeResource(*(HGLOBAL *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

