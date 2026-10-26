/*
 * FUN_00435e74 at 00435e74
 * undefined FUN_00435e74(void)
 * Address ranges: 00435e74-00435ea9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435e74(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426804(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    cVar1 = FUN_0043aa14(*(undefined4 **)(*(int *)(param_1 + 0x18) + 0x24),
                         *(undefined4 **)(iVar2 + 0x54));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

