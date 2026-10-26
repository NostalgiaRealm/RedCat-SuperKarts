/*
 * FUN_00431198 at 00431198
 * undefined __register FUN_00431198(int param_1)
 * Address ranges: 00431198-00431328
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00431198(int param_1)

{
  ATOM AVar1;
  undefined1 *puVar2;
  BOOL BVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  LPCSTR pCVar7;
  undefined4 uVar8;
  LPARAM lParam;
  LONG dwNewLong;
  undefined4 *in_FS_OFFSET;
  LPVOID pvVar9;
  HINSTANCE pHVar10;
  HMENU pHVar11;
  HWND pHVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 *local_30;
  tagWNDCLASSA local_2c;
  
  puStack_38 = &stack0xfffffffc;
  local_30 = (undefined4 *)0x0;
  puStack_3c = &LAB_00431329;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  if ((*(char *)(param_1 + 0x94) == '\0') && (*PTR_DAT_0047c8d8 == '\0')) {
    puVar2 = FUN_004295d8();
    *(undefined1 **)(param_1 + 0x34) = puVar2;
    BVar3 = GetClassInfoA(DAT_0047d4dc,PTR_s_TApplication_0047b7e0,&local_2c);
    if (BVar3 == 0) {
      _DAT_0047b7cc = DAT_0047d4dc;
      AVar1 = RegisterClassA((WNDCLASSA *)&DAT_0047b7bc);
      if (AVar1 == 0) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c668,(int *)&local_30);
        piVar4 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',local_30);
        FUN_00403604(piVar4);
      }
    }
    iVar15 = 0;
    (**(code **)PTR_DAT_0047c734)();
    uVar5 = (**(code **)PTR_DAT_0047c734)();
    iVar6 = (int)uVar5 >> 1;
    if (iVar6 < 0) {
      iVar6 = iVar6 + (uint)((uVar5 & 1) != 0);
    }
    iVar14 = 0;
    iVar13 = 0;
    pHVar12 = (HWND)0x0;
    pHVar11 = (HMENU)0x0;
    pvVar9 = (LPVOID)0x0;
    pHVar10 = DAT_0047d4dc;
    pCVar7 = FUN_00403f94(*(undefined **)(param_1 + 0x7c));
    uVar8 = FUN_00406c4c(PTR_s_TApplication_0047b7e0,pCVar7,0x84ca0000,pvVar9,pHVar10,pHVar11,
                         pHVar12,iVar13,iVar14,iVar6,iVar15);
    *(undefined4 *)(param_1 + 0x24) = uVar8;
    FUN_00403b50((int *)(param_1 + 0x7c));
    *(undefined1 *)(param_1 + 0x94) = 1;
    SetWindowLongA(*(HWND *)(param_1 + 0x24),-4,*(LONG *)(param_1 + 0x34));
    if (*PTR_DAT_0047c7a0 != '\0') {
      lParam = FUN_00431cd0(param_1);
      SendMessageA(*(HWND *)(param_1 + 0x24),0x80,1,lParam);
      dwNewLong = FUN_00431cd0(param_1);
      SetClassLongA(*(HWND *)(param_1 + 0x24),-0xe,dwNewLong);
    }
    pHVar11 = GetSystemMenu(*(HWND *)(param_1 + 0x24),0);
    DeleteMenu(pHVar11,0xf030,0);
    DeleteMenu(pHVar11,0xf000,0);
    if (*PTR_DAT_0047c7a0 != '\0') {
      DeleteMenu(pHVar11,0xf010,0);
    }
  }
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00431330;
  puStack_3c = (undefined1 *)0x431328;
  FUN_00403b50((int *)&local_30);
  return;
}

