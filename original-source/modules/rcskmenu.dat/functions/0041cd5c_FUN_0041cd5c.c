/*
 * FUN_0041cd5c at 0041cd5c
 * int __register FUN_0041cd5c(int * param_1)
 * Address ranges: 0041cd5c-0041cd9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041cd5c(int *param_1)

{
  int *piVar1;
  
  if (param_1[9] == 0) {
    FUN_0041cf14((int)param_1);
    piVar1 = FUN_0041bb5c((int *)&PTR_FUN_0041b9e4,'\x01',(int)param_1);
    param_1[9] = (int)piVar1;
    piVar1[0xb] = (int)param_1;
    piVar1[10] = *(int *)(*param_1 + 0x10);
    piVar1[0xd] = (int)param_1;
    piVar1[0xc] = (int)FUN_0041ca44;
  }
  return param_1[9];
}

