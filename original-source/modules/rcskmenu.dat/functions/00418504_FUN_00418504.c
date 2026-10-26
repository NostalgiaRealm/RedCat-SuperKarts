/*
 * FUN_00418504 at 00418504
 * undefined __register FUN_00418504(int * param_1, RECT * param_2)
 * Address ranges: 00418504-00418531
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418504(int *param_1,RECT *param_2)

{
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,9);
  DrawFocusRect((HDC)param_1[1],param_2);
  (**(code **)(*param_1 + 0xc))();
  return;
}

