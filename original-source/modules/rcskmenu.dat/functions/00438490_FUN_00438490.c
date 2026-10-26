/*
 * FUN_00438490 at 00438490
 * undefined4 __register FUN_00438490(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00438490-004384b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00438490(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    piVar1 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
    *(int **)(param_1 + 0x40) = piVar1;
  }
  (**(code **)(**(int **)(param_1 + 0x40) + 0x3c))(*(int **)(param_1 + 0x40),1);
  return *(undefined4 *)(param_1 + 0x40);
}

