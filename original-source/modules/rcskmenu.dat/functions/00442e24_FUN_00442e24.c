/*
 * FUN_00442e24 at 00442e24
 * undefined __register FUN_00442e24(int * param_1)
 * Address ranges: 00442e24-00442e61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442e24(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = param_1;
  while (piVar1 = (int *)piVar3[9], piVar1 != (int *)0x0) {
    piVar3 = piVar1;
    if ((char)piVar1[0x5a] == '\0') {
      return;
    }
  }
  uVar2 = FUN_00403024(piVar3,(int)&PTR_FUN_00427e2c);
  if (((char)uVar2 == '\0') && (piVar3[0x59] == 0)) {
    return;
  }
  FUN_00442d28(param_1);
  return;
}

