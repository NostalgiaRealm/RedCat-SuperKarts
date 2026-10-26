/*
 * FUN_0041cb46 at 0041cb46
 * undefined __cdecl FUN_0041cb46(int param_1)
 * Address ranges: 0041cb46-0041cc1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041cb46(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0x20) != -1) {
    iVar3 = FUN_00412a9d(*(int *)(param_1 + 0x18));
    iVar2 = *(int *)(DAT_0043d858 + *(int *)(iVar1 + 0x20) * 0xc);
    iVar7 = *(int *)(iVar1 + 4);
    iVar6 = *(int *)(iVar1 + 8);
    iVar4 = FUN_00412687(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24));
    uVar8 = 1;
    iVar5 = FUN_00412a49(iVar3);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_004129f6(iVar3);
    iVar6 = iVar6 + iVar7 / 2;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar8);
    if (*(int *)(iVar1 + 0x24) < iVar2 + -1) {
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
    }
    else {
      *(undefined4 *)(iVar1 + 0x24) = 0;
    }
  }
  return;
}

