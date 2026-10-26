/*
 * FUN_004255b0 at 004255b0
 * undefined FUN_004255b0(void)
 * Address ranges: 004255b0-004255e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004255b0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426818(param_1);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0xb4))();
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (cVar1 == *(char *)(iVar2 + 0x58)) {
      return 1;
    }
  }
  return 0;
}

