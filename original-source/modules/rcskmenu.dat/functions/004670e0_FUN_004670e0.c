/*
 * FUN_004670e0 at 004670e0
 * undefined __register FUN_004670e0(int * param_1)
 * Address ranges: 004670e0-0046711a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004670e0(int *param_1)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 0xc0))();
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    piVar1 = FUN_004298bc(param_1);
    if ((piVar1 != (int *)0x0) && (piVar1[0x8e] != 0)) {
      (**(code **)(*(int *)piVar1[0x8e] + 0xc))();
    }
  }
  FUN_00465ff8((int)param_1);
  return;
}

