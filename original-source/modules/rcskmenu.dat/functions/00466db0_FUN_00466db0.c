/*
 * FUN_00466db0 at 00466db0
 * undefined __register FUN_00466db0(int param_1, int param_2)
 * Address ranges: 00466db0-00466e42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466db0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  undefined1 local_18;
  int local_14;
  undefined1 local_10;
  
  if (*(int *)(param_1 + 500) != 0) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 500) + 0x240) + 8) + -1;
    if (iVar3 < param_2) {
      local_18 = 0;
      local_10 = 0;
      local_1c = param_2;
      local_14 = iVar3;
      uVar1 = FUN_0040ad5c((int)&DAT_0040dc44,'\x01',(undefined4 *)PTR_PTR_0047c66c,1,&local_1c);
      FUN_00403604(uVar1);
    }
    iVar3 = FUN_00466cc0(param_1);
    iVar2 = FUN_00466ca4(param_1);
    FUN_0040f7a4(*(int **)(*(int *)(param_1 + 500) + 0x240),iVar2,param_2);
    if (-1 < iVar3) {
      FUN_00466cc0(param_1);
      FUN_004675a4(*(int *)(param_1 + 500),iVar3);
    }
  }
  return;
}

