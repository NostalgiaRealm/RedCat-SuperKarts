/*
 * FUN_0044173c at 0044173c
 * undefined FUN_0044173c(void)
 * Address ranges: 0044173c-0044176d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044173c(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426840(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(int *)(iVar2 + 0x5c) == *(int *)(*(int *)(param_1 + 0x20) + 0x150)) {
      return CONCAT31((int3)((uint)*(int *)(iVar2 + 0x5c) >> 8),1);
    }
  }
  return 0;
}

