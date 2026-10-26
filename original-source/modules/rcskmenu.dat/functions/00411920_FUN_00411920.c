/*
 * FUN_00411920 at 00411920
 * undefined __register FUN_00411920(int * param_1, undefined4 param_2, int param_3)
 * Address ranges: 00411920-00411956
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411920(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != 0) {
    iVar1 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3);
    if (param_3 != iVar1) {
      piVar2 = FUN_0040ad20((int *)&DAT_0040db34,'\x01',(undefined4 *)PTR_PTR_0047c7ec);
      FUN_00403604(piVar2);
    }
  }
  return;
}

