/*
 * FUN_004492a4 at 004492a4
 * undefined __register FUN_004492a4(int * param_1, int param_2, int param_3)
 * Address ranges: 004492a4-0044930c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004492a4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  int local_14 [2];
  
  if ((char)param_3 == '\0') {
    (**(code **)(*param_1 + 0x18))(param_1,param_2);
  }
  else {
    iVar1 = FUN_004478c8((int)param_1,param_2,param_3);
    if (iVar1 == 0) {
      FUN_0040ebd0(*(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x34),local_14);
      iVar1 = FUN_00448070((int)param_1,local_14,&uStack_18);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 4);
      }
      uVar2 = FUN_00449228(param_2,iVar1);
      (**(code **)(*param_1 + 8))(param_1,param_2,uVar2,iVar1);
    }
  }
  return;
}

