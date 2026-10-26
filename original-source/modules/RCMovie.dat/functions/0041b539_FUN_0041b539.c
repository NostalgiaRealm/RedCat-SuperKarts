/*
 * FUN_0041b539 at 0041b539
 * undefined __cdecl FUN_0041b539(int param_1, int param_2, DWORD param_3, int param_4)
 * Address ranges: 0041b539-0041b6e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041b539(int param_1,int param_2,DWORD param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_c;
  
  iVar1 = FUN_00412b70(param_2);
  iVar8 = *(int *)(DAT_0043d858 + param_1 * 0xc);
  iVar2 = *(int *)(iVar1 + 0x10) / 2;
  iVar3 = *(int *)(iVar1 + 0x14) / 2;
  if (param_4 == 2) {
    while (local_c = iVar8 + -1, -1 < local_c) {
      iVar8 = FUN_00412687(param_1,local_c);
      uVar9 = 1;
      iVar4 = FUN_00412a49(param_2);
      iVar4 = iVar4 + iVar3;
      iVar5 = FUN_004129f6(param_2);
      iVar5 = iVar5 + iVar2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar8,iVar5,iVar4,uVar9);
      if (*(int *)(iVar1 + 0x20) != 0) {
        FUN_0041258a(param_2,*(int *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28),*(int *)(iVar1 + 0x28),
                     *(int *)(iVar1 + 0x2c));
      }
      Sleep(param_3);
      iVar8 = local_c;
    }
  }
  else {
    for (local_c = 0; local_c < iVar8; local_c = local_c + 1) {
      iVar4 = FUN_00412687(param_1,local_c);
      uVar9 = 1;
      iVar5 = FUN_00412a49(param_2);
      iVar5 = iVar5 + iVar3;
      iVar6 = FUN_004129f6(param_2);
      iVar6 = iVar6 + iVar2;
      iVar7 = FUN_00412061();
      FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar9);
      if (*(int *)(iVar1 + 0x20) != 0) {
        FUN_0041258a(param_2,*(int *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28),*(int *)(iVar1 + 0x28),
                     *(int *)(iVar1 + 0x2c));
      }
      Sleep(param_3);
    }
  }
  return;
}

