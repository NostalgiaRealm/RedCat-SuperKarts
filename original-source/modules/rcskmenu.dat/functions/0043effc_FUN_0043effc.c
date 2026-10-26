/*
 * FUN_0043effc at 0043effc
 * undefined __register FUN_0043effc(int * param_1, int param_2, int * param_3)
 * Address ranges: 0043effc-0043f050
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043effc(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00403024(param_1,(int)&PTR_FUN_0043be00);
  if ((char)uVar1 == '\0') {
    FUN_0043fa78((int)param_1,*(char *)((int)param_1 + 0x47),'\0');
  }
  if (param_2 == param_1[9]) {
    FUN_0043f074(param_1,param_3);
  }
  else {
    FUN_00440694((int)param_1,param_3);
  }
  if ((param_2 == 0) || (param_2 == -1)) {
    (**(code **)(*param_1 + 0x60))(param_1,0);
  }
  return;
}

