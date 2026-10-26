/*
 * FUN_0041ecb4 at 0041ecb4
 * undefined FUN_0041ecb4(void)
 * Address ranges: 0041ecb4-0041ed2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041ecb4(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  HWND in_stack_00000004;
  uint in_stack_00000008;
  WINDOWPLACEMENT WStack_30;
  
  if (DAT_0047d705 == '\0') {
    DAT_0047d6e0 = (code *)FUN_0041eab4(1,DAT_0047d6e0,"MonitorFromWindow");
    uVar1 = (*DAT_0047d6e0)();
  }
  else if ((in_stack_00000008 & 3) == 0) {
    BVar2 = IsIconic(in_stack_00000004);
    if (BVar2 == 0) {
      GetWindowRect(in_stack_00000004,&WStack_30.rcNormalPosition);
    }
    else {
      GetWindowPlacement(in_stack_00000004,&WStack_30);
    }
    uVar1 = FUN_0041ec24();
  }
  else {
    uVar1 = 0x12340042;
  }
  return uVar1;
}

