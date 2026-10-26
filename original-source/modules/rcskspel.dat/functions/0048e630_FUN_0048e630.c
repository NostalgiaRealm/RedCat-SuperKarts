/*
 * FUN_0048e630 at 0048e630
 * undefined FUN_0048e630(void)
 * Address ranges: 0048e630-0048e648
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048e630(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 == param_2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 7;
  } while (iVar1 < 0x20);
  return -1;
}

