/*
 * FUN_0046a350 at 0046a350
 * undefined FUN_0046a350(void)
 * Address ranges: 0046a350-0046a55b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046a350(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  bool bVar4;
  uint **ppuVar5;
  undefined4 uStack_58;
  undefined *puStack_54;
  undefined1 *puStack_50;
  undefined1 auStack_48 [2];
  ushort uStack_46;
  ushort auStack_40 [4];
  uint uStack_38;
  undefined1 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  uint *puStack_28;
  byte abStack_24 [32];
  
  puStack_50 = &stack0xfffffffc;
  puStack_28 = (uint *)0x0;
  puStack_54 = &UNK_0046a55c;
  uStack_58 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_58;
  (**(code **)(**(int **)(param_1 + 0x314) + 0xb8))
            (*(int **)(param_1 + 0x314),*(byte *)(*(int *)(param_1 + 0x338) + 0x34) ^ 1);
  uVar2 = FUN_0046a878(param_1);
  (**(code **)(**(int **)(param_1 + 0x314) + 0x5c))(*(int **)(param_1 + 0x314),uVar2);
  (**(code **)(**(int **)(param_1 + 0x31c) + 0xb8))
            (*(int **)(param_1 + 0x31c),*(int *)(*(int *)(param_1 + 0x338) + 0x38) == 0);
  uVar2 = FUN_0046a878(param_1);
  (**(code **)(**(int **)(param_1 + 0x31c) + 0x5c))(*(int **)(param_1 + 0x31c),uVar2);
  (**(code **)(**(int **)(param_1 + 0x324) + 0xb8))
            (*(int **)(param_1 + 0x324),0 < *(int *)(*(int *)(param_1 + 0x338) + 0x3c));
  (**(code **)(**(int **)(param_1 + 0x328) + 0xb8))
            (*(int **)(param_1 + 0x328),*(undefined1 *)(*(int *)(param_1 + 0x338) + 0x40));
  (**(code **)(**(int **)(param_1 + 0x334) + 0xb8))
            (*(int **)(param_1 + 0x334),*(undefined1 *)(*(int *)(param_1 + 0x338) + 0x41));
  (**(code **)(**(int **)(param_1 + 0x2e8) + 0xb8))
            (*(int **)(param_1 + 0x2e8),*(int *)(*(int *)(param_1 + 0x338) + 0x30) == 0);
  uVar2 = FUN_0046a878(param_1);
  (**(code **)(**(int **)(param_1 + 0x2e8) + 0x5c))(*(int **)(param_1 + 0x2e8),uVar2);
  (**(code **)(**(int **)(param_1 + 0x2ec) + 0xb8))
            (*(int **)(param_1 + 0x2ec),*(int *)(*(int *)(param_1 + 0x338) + 0x30) == 1);
  uVar2 = FUN_0046a878(param_1);
  (**(code **)(**(int **)(param_1 + 0x2ec) + 0x5c))(*(int **)(param_1 + 0x2ec),uVar2);
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x2f8) + 0x1f0) + 0x14))();
  FUN_00402c94(0x2000,iVar3 - 1,abStack_24);
  uVar1 = *(uint *)(*(int *)(param_1 + 0x338) + 0x1c);
  bVar4 = uVar1 < 0xff;
  if (uVar1 < 0x100) {
    bVar4 = (abStack_24[(int)uVar1 >> 3] >> (uVar1 & 7) & 1) != 0;
  }
  if (bVar4) {
    FUN_00424744(*(int **)(param_1 + 0x2f8),*(int *)(*(int *)(param_1 + 0x338) + 0x1c) + 1);
  }
  TfrmDisplaySettings_cboDriverChange(param_1,*(undefined4 *)(param_1 + 0x2f8));
  iVar3 = FUN_00424728(*(int **)(param_1 + 0x2f8));
  if (1 < iVar3) {
    ppuVar5 = &puStack_28;
    FUN_00469938(*(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c),auStack_40);
    uStack_38 = (uint)auStack_40[0];
    uStack_34 = 0;
    FUN_00469938(*(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c),auStack_48);
    uStack_30 = (uint)uStack_46;
    uStack_2c = 0;
    FUN_00408a5c(&UNK_0046a570,&uStack_38,1,(int *)ppuVar5);
    FUN_0043f67c(*(int *)(param_1 + 0x304),puStack_28);
  }
  uVar2 = FUN_0046a878(param_1);
  (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))(*(int **)(param_1 + 0x304),uVar2);
  *in_FS_OFFSET = uStack_58;
  puStack_50 = &UNK_0046a563;
  puStack_54 = (undefined *)0x46a55b;
  FUN_00403b50((int *)&puStack_28);
  return;
}

