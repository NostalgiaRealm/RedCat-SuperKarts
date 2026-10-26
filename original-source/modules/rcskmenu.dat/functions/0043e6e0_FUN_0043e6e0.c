/*
 * FUN_0043e6e0 at 0043e6e0
 * undefined FUN_0043e6e0(void)
 * Address ranges: 0043e6e0-0043e712
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043e6e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_0042682c(param_1);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x4c))();
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (cVar1 == *(char *)(iVar2 + 0x59)) {
      return 1;
    }
  }
  return 0;
}

