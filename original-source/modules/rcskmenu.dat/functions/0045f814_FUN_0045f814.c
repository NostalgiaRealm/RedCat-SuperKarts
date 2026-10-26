/*
 * FUN_0045f814 at 0045f814
 * undefined __register FUN_0045f814(int * param_1, byte param_2, int param_3, int param_4)
 * Address ranges: 0045f814-0045f91a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045f814(int *param_1,byte param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_00440c00((int)param_1,param_2,param_3,param_4);
  if ((param_2 & 8) != 0) {
    iVar4 = param_3 + param_1[0xc];
    iVar3 = param_1[0xd];
    if (iVar4 != param_1[0x91]) {
      iVar2 = FUN_0043f0b0((int *)param_1[0x90]);
      if (iVar2 - param_1[0xe] != *(int *)(param_1[0x90] + 0x218) * 2) {
        iVar5 = (iVar4 - param_1[0x91]) + param_1[0xc];
        iVar2 = ((int *)param_1[0x90])[0x86];
        if (iVar5 < iVar2) {
          iVar5 = iVar2;
        }
        iVar2 = FUN_0043f0b0((int *)param_1[0x90]);
        if ((iVar2 - param_1[0xe]) - *(int *)(param_1[0x90] + 0x218) < iVar5) {
          iVar2 = FUN_0043f0b0((int *)param_1[0x90]);
          iVar5 = (iVar2 - param_1[0xe]) - *(int *)(param_1[0x90] + 0x218);
        }
        if (iVar5 != param_1[0xc]) {
          param_1[0x91] = iVar4;
          param_1[0x92] = param_4 + iVar3;
          FUN_0043ee6c(param_1,iVar5);
          iVar3 = FUN_0045fa58((int *)param_1[0x90],param_1[0xc]);
          piVar1 = (int *)param_1[0x90];
          piVar1[0x81] = iVar3;
          (**(code **)(*piVar1 + 0xb8))();
        }
      }
    }
  }
  return;
}

