/*
 * FUN_0044a070 at 0044a070
 * undefined FUN_0044a070(void)
 * Address ranges: 0044a070-0044a0b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0044a070(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      cVar1 = FUN_00449a70(param_2);
      if (cVar1 != '\0') {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 4));
  }
  return -1;
}

