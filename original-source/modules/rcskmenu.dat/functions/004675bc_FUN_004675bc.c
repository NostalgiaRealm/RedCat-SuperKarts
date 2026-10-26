/*
 * FUN_004675bc at 004675bc
 * undefined __register FUN_004675bc(int * param_1, int * param_2)
 * Address ranges: 004675bc-0046760a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004675bc(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00467318((int)param_1,(int)param_2,'\x01',(*(byte *)(param_1 + 8) & 0x10) == 0
                              );
  if (param_2 == piVar1) {
    piVar1 = (int *)0x0;
  }
  FUN_00466e44((int)param_2,'\0');
  param_2[0x7d] = 0;
  FUN_0040f848((int *)param_1[0x90],(int)param_2);
  FUN_00467660(param_1,piVar1);
  return;
}

