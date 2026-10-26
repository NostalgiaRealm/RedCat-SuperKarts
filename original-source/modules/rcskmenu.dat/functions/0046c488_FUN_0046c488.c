/*
 * FUN_0046c488 at 0046c488
 * undefined __register FUN_0046c488(int param_1)
 * Address ranges: 0046c488-0046c5ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046c488(int param_1)

{
  int *piVar1;
  byte *lpBitmapName;
  HBITMAP pHVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  byte bVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  byte local_54;
  byte local_53 [43];
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined1 local_1c;
  undefined *local_18;
  undefined1 local_14;
  
  FUN_0040ebd0(0,0,&local_28);
  *(undefined4 *)(param_1 + 0x2a8) = local_28;
  *(undefined4 *)(param_1 + 0x2ac) = local_24;
  local_54 = 0;
  ppuVar6 = &PTR_s_MPPLAY_0047c45c;
  uVar4 = extraout_ECX;
  do {
    bVar5 = 0;
    ppuVar7 = &PTR_s_EN_0046c2c4_8_0047c450;
    do {
      piVar1 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',uVar4);
      *(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4) = piVar1;
      local_20 = *ppuVar7;
      local_1c = 6;
      local_18 = *ppuVar6;
      local_14 = 6;
      lpBitmapName = FUN_004089f4(local_53,(byte *)"%s_%s",&local_20,1);
      pHVar2 = LoadBitmapA(DAT_0047d4dc,(LPCSTR)lpBitmapName);
      FUN_0041d86c(*(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4),pHVar2);
      iVar3 = (**(code **)(**(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4) +
                          0x2c))();
      if (*(int *)(param_1 + 0x2a8) < iVar3) {
        uVar4 = (**(code **)(**(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4) +
                            0x2c))();
        *(undefined4 *)(param_1 + 0x2a8) = uVar4;
      }
      iVar3 = (**(code **)(**(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4) +
                          0x20))();
      uVar4 = extraout_ECX_00;
      if (*(int *)(param_1 + 0x2ac) < iVar3) {
        uVar4 = (**(code **)(**(int **)(param_1 + (uint)local_54 * 0x10 + 0x1fc + (uint)bVar5 * 4) +
                            0x20))();
        *(undefined4 *)(param_1 + 0x2ac) = uVar4;
        uVar4 = extraout_ECX_01;
      }
      bVar5 = bVar5 + 1;
      ppuVar7 = ppuVar7 + 1;
    } while (bVar5 != 3);
    local_54 = local_54 + 1;
    ppuVar6 = ppuVar6 + 1;
  } while (local_54 != 9);
  *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + 8;
  *(int *)(param_1 + 0x2ac) = *(int *)(param_1 + 0x2ac) + 4;
  return;
}

