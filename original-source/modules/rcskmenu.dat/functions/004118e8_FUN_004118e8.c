/*
 * FUN_004118e8 at 004118e8
 * undefined __register FUN_004118e8(int * param_1, undefined4 param_2, int param_3)
 * Address ranges: 004118e8-0041191e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004118e8(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != 0) {
    iVar1 = (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
    if (param_3 != iVar1) {
      piVar2 = FUN_0040ad20((int *)&DAT_0040dadc,'\x01',(undefined4 *)PTR_PTR_0047c960);
      FUN_00403604(piVar2);
    }
  }
  return;
}

