/*
 * FUN_00439498 at 00439498
 * bool __register FUN_00439498(int param_1)
 * Address ranges: 00439498-004394b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00439498(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004393f8(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x40))();
  }
  return piVar1 != (int *)0x0;
}

