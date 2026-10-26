/*
 * FUN_0042ed80 at 0042ed80
 * undefined __register FUN_0042ed80(int * param_1)
 * Address ranges: 0042ed80-0042ef4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ed80(int *param_1)

{
  char cVar1;
  int *piVar2;
  HWND pHVar3;
  HWND pHVar4;
  undefined4 extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  uint uVar5;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puVar7;
  UINT UVar8;
  WPARAM WVar9;
  LPARAM LVar10;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 *local_24;
  HWND local_20;
  undefined4 local_1c;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  puStack_30 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  local_24 = (undefined4 *)0x0;
  puStack_34 = &LAB_0042f010;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  local_8 = param_1;
  FUN_0043e064();
  if (*(char *)((int)local_8 + 0x47) == '\0') {
    cVar1 = (**(code **)(*local_8 + 0x4c))();
    if (((cVar1 != '\0') && ((*(byte *)(local_8 + 0xb3) & 8) == 0)) &&
       (*(char *)((int)local_8 + 0x217) != '\x01')) goto LAB_0042edf6;
  }
  FUN_00405438((undefined4 *)PTR_PTR_0047c7bc,(int *)&local_24);
  piVar2 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',local_24);
  FUN_00403604(piVar2);
LAB_0042edf6:
  pHVar3 = GetCapture();
  if (pHVar3 != (HWND)0x0) {
    LVar10 = 0;
    WVar9 = 0;
    UVar8 = 0x1f;
    pHVar3 = GetCapture();
    puStack_4c = (undefined1 *)0x42ee10;
    SendMessageA(pHVar3,UVar8,WVar9,LVar10);
  }
  ReleaseCapture();
  *(byte *)(local_8 + 0xb3) = *(byte *)(local_8 + 0xb3) | 8;
  local_20 = GetActiveWindow();
  local_14 = DAT_0047b6b8;
  FUN_0040f72c(*(int **)(DAT_0047d774 + 0x70),0,*(int *)(DAT_0047d774 + 0x6c));
  *(int **)(DAT_0047d774 + 0x6c) = local_8;
  local_16 = *(undefined2 *)(DAT_0047d774 + 0x38);
  FUN_00430630(DAT_0047d774,0);
  local_1c = *(undefined4 *)(DAT_0047d774 + 0x3c);
  local_10 = FUN_00429334(0);
  *in_FS_OFFSET = &stack0xffffffbc;
  FUN_0042ecd0(local_8,0,extraout_ECX);
  puStack_4c = &LAB_0042ef4f;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  LVar10 = 0;
  WVar9 = 0;
  UVar8 = 0xb000;
  pHVar3 = (HWND)FUN_00445724(local_8);
  SendMessageA(pHVar3,UVar8,WVar9,LVar10);
  uVar6 = 0;
  local_8[0x8d] = 0;
  uVar5 = extraout_ECX_00;
  do {
    FUN_00432200(DAT_0047d770,uVar6,uVar5);
    uVar5 = extraout_ECX_01;
    uVar6 = extraout_EDX;
    if (*(char *)(DAT_0047d770 + 0x8c) == '\0') {
      if (local_8[0x8d] != 0) {
        FUN_0042ec20(local_8);
        uVar5 = extraout_ECX_02;
        uVar6 = extraout_EDX_00;
      }
    }
    else {
      local_8[0x8d] = 2;
    }
    local_c = local_8[0x8d];
  } while (local_c == 0);
  LVar10 = 0;
  WVar9 = 0;
  UVar8 = 0xb001;
  pHVar3 = (HWND)FUN_00445724(local_8);
  SendMessageA(pHVar3,UVar8,WVar9,LVar10);
  pHVar3 = (HWND)FUN_00445724(local_8);
  pHVar4 = GetActiveWindow();
  if (pHVar3 != pHVar4) {
    local_20 = (HWND)0x0;
  }
  *in_FS_OFFSET = uStack_50;
  puStack_4c = (undefined1 *)0x42ef4e;
  FUN_0042ecc8(local_8,uStack_50,puVar7);
  return;
}

