/*
 * FUN_004042bc at 004042bc
 * undefined __register FUN_004042bc(int * param_1, UINT param_2)
 * Address ranges: 004042bc-004042fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004042bc(int *param_1,UINT param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (0 < (int)param_2) {
    puVar2 = (undefined4 *)FUN_004042a4(param_2);
    uVar1 = FUN_00404298(*param_1);
    if (0 < (int)uVar1) {
      if ((int)param_2 < (int)uVar1) {
        uVar1 = param_2;
      }
      FUN_0040282c((undefined4 *)*param_1,puVar2,uVar1 * 2);
    }
  }
  FUN_00404170(param_1,puVar2);
  return;
}

