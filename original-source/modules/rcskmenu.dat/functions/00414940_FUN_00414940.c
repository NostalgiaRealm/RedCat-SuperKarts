/*
 * FUN_00414940 at 00414940
 * undefined __register FUN_00414940(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 00414940-00414994
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414940(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_00403088(param_2,param_1,param_3);
  (**(code **)(*param_1 + 0x20))(param_1,param_2,0,param_2[2]);
  FUN_004148ec((int)param_1,(int)param_2,extraout_ECX);
  FUN_00414e5c((int)param_2,'\x01');
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    FUN_00414e0c((int)param_2,CONCAT31((int3)((uint)extraout_EDX >> 8),1),'\x01');
  }
  (**(code **)(*param_1 + 0x10))(param_1,param_2,0);
  return;
}

