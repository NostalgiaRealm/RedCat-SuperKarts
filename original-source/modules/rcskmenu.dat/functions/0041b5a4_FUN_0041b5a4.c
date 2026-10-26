/*
 * FUN_0041b5a4 at 0041b5a4
 * undefined4 __register FUN_0041b5a4(undefined4 param_1, int * param_2)
 * Address ranges: 0041b5a4-0041b602
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041b5a4(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  int local_70 [10];
  int local_48;
  
  iVar1 = FUN_004118b0(param_2);
  iVar2 = FUN_00411894(param_2);
  if (100 < iVar1 - iVar2) {
    (**(code **)(*param_2 + 4))(param_2,local_70,100);
    uVar3 = (**(code **)(*param_2 + 0xc))(param_2,0xffffff9c,CONCAT22(extraout_var,1));
    if ((local_70[0] == 1) && (local_48 == 0x464d4520)) {
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
  }
  return 0;
}

