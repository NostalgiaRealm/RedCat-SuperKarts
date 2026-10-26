/*
 * FUN_004298bc at 004298bc
 * int * __register FUN_004298bc(int * param_1)
 * Address ranges: 004298bc-004298e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004298bc(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  do {
    piVar2 = param_1;
    param_1 = (int *)piVar2[9];
  } while ((int *)piVar2[9] != (int *)0x0);
  uVar1 = FUN_00403024(piVar2,(int)&PTR_FUN_00427e2c);
  if ((char)uVar1 == '\0') {
    return (int *)0x0;
  }
  return piVar2;
}

