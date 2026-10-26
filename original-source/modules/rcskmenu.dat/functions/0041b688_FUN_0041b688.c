/*
 * FUN_0041b688 at 0041b688
 * undefined __register FUN_0041b688(int param_1, int * param_2)
 * Address ranges: 0041b688-0041b708
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b688(int param_1,int *param_2)

{
  int iVar1;
  undefined2 extraout_var;
  int local_10;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    local_10 = 0;
    (**(code **)(*param_2 + 8))(param_2,&local_10,4);
    local_10 = FUN_00411894(param_2);
    local_10 = local_10 + -4;
    if (*(char *)(param_1 + 0x24) == '\0') {
      FUN_0041b798(param_1,param_2);
    }
    else {
      FUN_0041b70c(param_1,param_2);
    }
    (**(code **)(*param_2 + 0xc))(param_2,local_10,0);
    iVar1 = FUN_004118b0(param_2);
    local_10 = iVar1 - local_10;
    (**(code **)(*param_2 + 8))(param_2,&local_10,4);
    (**(code **)(*param_2 + 0xc))(param_2,0,CONCAT22(extraout_var,2));
  }
  return;
}

