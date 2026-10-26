/*
 * FUN_004339c0 at 004339c0
 * undefined __register FUN_004339c0(int param_1, int * param_2, int * param_3)
 * Address ranges: 004339c0-00433a10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004339c0(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  FUN_00434218(param_1,param_2);
  if (param_2 == (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x44) + 0x60))();
  }
  else {
    uVar1 = FUN_0041cdc0((int)param_2);
    if ((char)uVar1 == '\x01') {
      (**(code **)(*param_2 + 0x60))();
    }
    else {
      (**(code **)(*param_3 + 8))(param_3,param_2);
      (**(code **)(*param_3 + 0x68))(param_3,1);
      (**(code **)(*param_3 + 0x60))();
    }
  }
  return;
}

