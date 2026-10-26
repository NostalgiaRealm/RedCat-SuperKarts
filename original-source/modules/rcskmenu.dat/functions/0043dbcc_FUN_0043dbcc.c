/*
 * FUN_0043dbcc at 0043dbcc
 * undefined __register FUN_0043dbcc(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0043dbcc-0043dd75;0043dd8c-0043dd92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043dbcc(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 uVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *in_FS_OFFSET;
  byte bVar5;
  LPRECT lpRect;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int local_24 [2];
  int local_1c;
  int local_18;
  tagPOINT local_14;
  int *local_c;
  char local_5;
  
  bVar5 = 0;
  puStack_34 = &stack0xfffffffc;
  puStack_38 = &LAB_0043dd76;
  uStack_3c = *in_FS_OFFSET;
  DAT_0047d7b8 = param_1;
  *in_FS_OFFSET = &uStack_3c;
  local_c = (int *)0x0;
  DAT_0047d7c0 = 0;
  local_5 = param_2;
  if (*(char *)((int)param_1 + 0x8b) == '\0') {
    puStack_34 = &stack0xfffffffc;
    FUN_00403088(param_1,&local_c,param_3);
    if (DAT_0047d7b8 == (int *)0x0) {
      *in_FS_OFFSET = uStack_3c;
      return;
    }
    if (local_c == (int *)0x0) {
      local_c = (int *)FUN_0043cec8((int *)&PTR_FUN_0043ad90,'\x01',(int)param_1);
      DAT_0047d7c0 = 1;
    }
  }
  else {
    FUN_00403088(param_1,&local_c,param_3);
    if (DAT_0047d7b8 == (int *)0x0) {
      *in_FS_OFFSET = uStack_3c;
      return;
    }
    if (local_c == (int *)0x0) {
      local_c = FUN_0043cfd4((int *)&PTR_FUN_0043ae18,'\x01',(int)param_1);
      DAT_0047d7c0 = 1;
    }
    piVar3 = (int *)local_c[0xe];
    uVar1 = FUN_00403024(piVar3,(int)&PTR_FUN_0043be00);
    if ((char)uVar1 == '\0') {
      piVar3 = (int *)local_c[0xe];
      if ((piVar3[9] == 0) &&
         (uVar1 = FUN_00403024(piVar3,(int)&PTR_FUN_0043be00), (char)uVar1 == '\0')) {
        GetCursorPos(&local_14);
        local_c[0x11] = local_14.x;
        local_c[0x12] = local_14.y;
      }
      else {
        FUN_0040ebd0(0,0,local_24);
        FUN_0043f1c4(piVar3,local_24,&local_1c);
        local_c[0x11] = local_1c;
        local_c[0x12] = local_18;
      }
      FUN_0040ebd0(local_c[0x11] + *(int *)(local_c[0xe] + 0x38),
                   local_c[0x12] + *(int *)(local_c[0xe] + 0x3c),&local_1c);
      local_c[0x13] = local_1c;
      local_c[0x14] = local_18;
    }
    else {
      lpRect = (LPRECT)(local_c + 0x11);
      hWnd = (HWND)FUN_00445724(piVar3);
      GetWindowRect(hWnd,lpRect);
    }
    piVar3 = local_c + 0x11;
    piVar4 = local_c + 0x17;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + (uint)bVar5 * -2 + 1;
      piVar4 = piVar4 + (uint)bVar5 * -2 + 1;
    }
  }
  FUN_0043da5c(local_c,local_5,param_3);
  *in_FS_OFFSET = uStack_3c;
  return;
}

