/*
 * FUN_00435fd4 at 00435fd4
 * undefined FUN_00435fd4(void)
 * Address ranges: 00435fd4-00436002
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435fd4(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426890(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(char *)(iVar2 + 0x6a) == *(char *)(*(int *)(param_1 + 0x18) + 0x32)) {
      return 1;
    }
  }
  return 0;
}

