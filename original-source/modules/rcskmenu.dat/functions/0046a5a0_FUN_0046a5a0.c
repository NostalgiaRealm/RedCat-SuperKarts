/*
 * FUN_0046a5a0 at 0046a5a0
 * undefined FUN_0046a5a0(void)
 * Address ranges: 0046a5a0-0046a7b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046a5a0(int param_1)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  LPCSTR lpOutputString;
  undefined4 *in_FS_OFFSET;
  undefined **ppuVar8;
  undefined4 uStack_5c;
  undefined *puStack_58;
  undefined1 *puStack_54;
  undefined1 auStack_44 [4];
  byte bStack_40;
  undefined1 auStack_3c [2];
  ushort uStack_3a;
  ushort auStack_34 [4];
  undefined4 uStack_2c;
  undefined1 uStack_28;
  uint uStack_24;
  undefined1 uStack_20;
  uint uStack_1c;
  undefined1 uStack_18;
  uint uStack_14;
  undefined1 uStack_10;
  undefined *puStack_c;
  undefined4 *puStack_8;
  
  puStack_54 = &stack0xfffffffc;
  puStack_c = (undefined *)0x0;
  puStack_8 = (undefined4 *)0x0;
  puStack_58 = &UNK_0046a7b5;
  uStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_5c;
  bVar2 = (**(code **)(**(int **)(param_1 + 0x314) + 0xb4))();
  *(byte *)(*(int *)(param_1 + 0x338) + 0x34) = bVar2 ^ 1;
  cVar3 = (**(code **)(**(int **)(param_1 + 0x31c) + 0xb4))();
  if (cVar3 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x338) + 0x38) = 2;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x338) + 0x38) = 0;
  }
  uVar4 = (**(code **)(**(int **)(param_1 + 0x324) + 0xb4))();
  FUN_0045bbb0(*(undefined4 *)(param_1 + 0x338),uVar4);
  uVar4 = (**(code **)(**(int **)(param_1 + 0x328) + 0xb4))();
  iVar5 = *(int *)(param_1 + 0x338);
  *(undefined1 *)(iVar5 + 0x40) = uVar4;
  *(uint *)(iVar5 + 0x30) = (uint)*(byte *)(*(int *)(param_1 + 0x2ec) + 0x210);
  uVar4 = (**(code **)(**(int **)(param_1 + 0x334) + 0xb4))();
  *(undefined1 *)(*(int *)(param_1 + 0x338) + 0x41) = uVar4;
  iVar5 = FUN_00424728(*(int **)(param_1 + 0x2f8));
  if (-1 < iVar5) {
    iVar6 = FUN_00424728(*(int **)(param_1 + 0x2f8));
    iVar5 = *(int *)(param_1 + 0x338);
    *(int *)(iVar5 + 0x1c) = iVar6 + -1;
    iVar5 = *(int *)(iVar5 + 0x24);
    if (iVar5 != 0) {
      FUN_0040272c(iVar5);
    }
    piVar1 = *(int **)(param_1 + 0x2f8);
    uVar7 = FUN_00424728(piVar1);
    piVar1 = (int *)piVar1[0x7c];
    (**(code **)(*piVar1 + 0x18))(piVar1,uVar7);
    uVar7 = FUN_0046a578();
    iVar5 = *(int *)(param_1 + 0x338);
    *(undefined4 *)(iVar5 + 0x24) = uVar7;
    *(undefined1 *)(iVar5 + 0x28) = 1;
    piVar1 = *(int **)(param_1 + 0x2f8);
    uVar7 = FUN_00424728(piVar1);
    piVar1 = (int *)piVar1[0x7c];
    (**(code **)(*piVar1 + 0xc))(piVar1,uVar7,&puStack_8);
    FUN_00403ba4((int *)(*(int *)(param_1 + 0x338) + 0x20),puStack_8);
  }
  iVar5 = FUN_00424728(*(int **)(param_1 + 0x304));
  if (-1 < iVar5) {
    piVar1 = *(int **)(param_1 + 0x304);
    uVar7 = FUN_00424728(piVar1);
    piVar1 = (int *)piVar1[0x7c];
    uStack_2c = (**(code **)(*piVar1 + 0x18))(piVar1,uVar7);
    *(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c) = uStack_2c;
    ppuVar8 = &puStack_c;
    uStack_28 = 0;
    FUN_00469938(uStack_2c,auStack_34);
    uStack_24 = (uint)auStack_34[0];
    uStack_20 = 0;
    FUN_00469938(*(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c),auStack_3c);
    uStack_1c = (uint)uStack_3a;
    uStack_18 = 0;
    FUN_00469938(*(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c),auStack_44);
    uStack_14 = (uint)bStack_40;
    uStack_10 = 0;
    FUN_00408a5c((byte *)"Resolution set to %d (%dx%dx%d)",&uStack_2c,3,(int *)ppuVar8);
    lpOutputString = FUN_00403f94(puStack_c);
    OutputDebugStringA(lpOutputString);
  }
  *in_FS_OFFSET = uStack_5c;
  puStack_54 = &UNK_0046a7bc;
  puStack_58 = (undefined *)0x46a7b4;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

