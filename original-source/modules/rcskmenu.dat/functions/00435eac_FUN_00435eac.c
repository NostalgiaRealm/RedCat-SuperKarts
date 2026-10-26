/*
 * FUN_00435eac at 00435eac
 * undefined FUN_00435eac(void)
 * Address ranges: 00435eac-00435eda
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435eac(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426818(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(char *)(iVar2 + 0x58) == *(char *)(*(int *)(param_1 + 0x18) + 0x2c)) {
      return 1;
    }
  }
  return 0;
}

