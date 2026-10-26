/*
 * FUN_0043da5c at 0043da5c
 * undefined __register FUN_0043da5c(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0043da5c-0043dbcb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043da5c(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  HWND pHVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar4;
  
  DAT_0047d7bc = param_1;
  param_1[1] = 0;
  GetCursorPos((LPPOINT)&DAT_0047d7c8);
  piVar1 = DAT_0047d7bc;
  DAT_0047d7bc[3] = DAT_0047d7c8;
  piVar1[4] = DAT_0047d7cc;
  DAT_0047d7d0 = GetCursor();
  DAT_0047d7c4 = FUN_0043cd50();
  DAT_0047d7d4 = param_3;
  uVar2 = FUN_00403024(param_1,(int)&PTR_FUN_0043ae18);
  if ((char)uVar2 == '\0') {
    if (param_2 == '\0') {
      DAT_0047d7d8 = '\0';
    }
    else {
      DAT_0047d7d8 = '\x01';
    }
  }
  else {
    iVar4 = param_1[0x11];
    if (param_1[0x13] == iVar4 || param_1[0x13] - iVar4 < 0) {
      param_1[8] = 0;
      param_1[9] = 0;
    }
    else {
      *(double *)(param_1 + 8) =
           (double)(param_1[3] - iVar4) / (double)(param_1[0x13] - param_1[0x11]);
    }
    if (param_1[0x14] - param_1[0x12] < 1) {
      param_1[10] = 0;
      param_1[0xb] = 0;
    }
    else {
      *(double *)(param_1 + 10) =
           (double)(param_1[4] - param_1[0x12]) / (double)(param_1[0x14] - param_1[0x12]);
    }
    if (param_2 == '\0') {
      DAT_0047d7d8 = '\0';
    }
    else {
      DAT_0047d7d8 = '\x02';
      (**(code **)(*param_1 + 0x2c))();
    }
  }
  DAT_0047d7dc = (int *)(**(code **)(*DAT_0047d7bc + 8))();
  uVar2 = extraout_ECX;
  if (DAT_0047d7dc != (int *)0x0) {
    iVar4 = DAT_0047d7cc;
    pHVar3 = GetDesktopWindow();
    FUN_00446ee4(DAT_0047d7dc,pHVar3,DAT_0047d7c8,iVar4);
    uVar2 = extraout_ECX_00;
  }
  DAT_0047d7e4 = FUN_00402e7c((int *)&PTR_FUN_0043cba4,'\x01',uVar2);
  if (DAT_0047d7d8 != '\0') {
    FUN_0043d788((POINT *)&DAT_0047d7c8);
  }
  return;
}

