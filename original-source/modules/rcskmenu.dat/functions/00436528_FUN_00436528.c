/*
 * FUN_00436528 at 00436528
 * undefined __register FUN_00436528(int param_1)
 * Address ranges: 00436528-00436596
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436528(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int **)(param_1 + 100) != (int *)0x0) &&
     (uVar1 = FUN_00403024(*(int **)(param_1 + 100),(int)&PTR_FUN_00435264), (char)uVar1 != '\0')) {
    FUN_00438ba0(param_1,'\0');
    FUN_00439070(param_1,'\0');
  }
  if (*(int *)(param_1 + 100) != 0) {
    FUN_00439ae8(*(int *)(param_1 + 100));
  }
  FUN_00435d50(FUN_0043650c,*(int *)(param_1 + 0x5c),param_1);
  return;
}

