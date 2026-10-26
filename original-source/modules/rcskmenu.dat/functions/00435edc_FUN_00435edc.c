/*
 * FUN_00435edc at 00435edc
 * undefined4 __register FUN_00435edc(int param_1)
 * Address ranges: 00435edc-00435f0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435edc(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_0042682c(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(char *)(iVar2 + 0x59) == *(char *)(*(int *)(param_1 + 0x18) + 0x2d)) {
      return CONCAT31((int3)((uint)iVar2 >> 8),1);
    }
  }
  return 0;
}

