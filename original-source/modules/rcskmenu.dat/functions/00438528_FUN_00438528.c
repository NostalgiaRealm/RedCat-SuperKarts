/*
 * FUN_00438528 at 00438528
 * undefined FUN_00438528(void)
 * Address ranges: 00438528-00438558
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438528(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  if (param_1[0x10] == 0) {
    piVar1 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
    param_1[0x10] = (int)piVar1;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))((int *)param_1[0x10],param_2);
  (**(code **)(*param_1 + 0x38))(param_1,1);
  return;
}

