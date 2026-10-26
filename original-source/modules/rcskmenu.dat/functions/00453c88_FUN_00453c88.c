/*
 * FUN_00453c88 at 00453c88
 * undefined __register FUN_00453c88(int * param_1, int * param_2)
 * Address ranges: 00453c88-00453d0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453c88(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((char)param_1[0x4c] == '\0') {
    if ((char)param_1[0x4a] == '\0') {
      FUN_0040ebe8(0,0,*(undefined4 *)(*(int *)(param_1[0x4b] + 0x10) + 0x8c),param_2,
                   *(undefined4 *)(*(int *)(param_1[0x4b] + 0x10) + 0x40));
    }
    else {
      uVar3 = param_1[0xf] - *(int *)(*(int *)(param_1[0x4b] + 0x10) + 0x40);
      iVar4 = (int)uVar3 >> 1;
      if (iVar4 < 0) {
        iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
      }
      iVar1 = *(int *)(*(int *)(param_1[0x4b] + 0x10) + 0x8c);
      uVar3 = param_1[0xe] - iVar1;
      iVar2 = (int)uVar3 >> 1;
      if (iVar2 < 0) {
        iVar2 = iVar2 + (uint)((uVar3 & 1) != 0);
      }
      FUN_0040ec04(iVar2,iVar4,iVar1,param_2,*(int *)(*(int *)(param_1[0x4b] + 0x10) + 0x40));
    }
  }
  else {
    (**(code **)(*param_1 + 0x40))(param_1,param_2);
  }
  return;
}

