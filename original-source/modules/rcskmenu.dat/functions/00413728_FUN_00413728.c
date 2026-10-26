/*
 * FUN_00413728 at 00413728
 * undefined __register FUN_00413728(int param_1, int param_2, undefined4 * param_3, int param_4)
 * Address ranges: 00413728-00413764
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413728(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = FUN_00411fd4((int *)&DAT_00411fac,'\x01',param_1,param_3,(undefined4 *)0x0,param_2,
                        *(int *)(*(int *)(param_4 + -4) + 0x18));
  FUN_0040f504(*(int **)(*(int *)(param_4 + -4) + 0x30),(int)piVar1);
  return;
}

