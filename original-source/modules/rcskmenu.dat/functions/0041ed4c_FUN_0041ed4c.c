/*
 * FUN_0041ed4c at 0041ed4c
 * undefined FUN_0041ed4c(void)
 * Address ranges: 0041ed4c-0041edc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041ed4c(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_stack_00000004;
  int in_stack_00000008;
  uint in_stack_0000000c;
  
  if (DAT_0047d707 == '\0') {
    DAT_0047d6e8 = (code *)FUN_0041eab4(3,DAT_0047d6e8,"MonitorFromPoint");
    uVar1 = (*DAT_0047d6e8)();
    return uVar1;
  }
  if ((in_stack_0000000c & 3) == 0) {
    if (in_stack_00000004 < 0) {
      return 0;
    }
    iVar2 = (*DAT_0047d6dc)();
    if (iVar2 <= in_stack_00000004) {
      return 0;
    }
    if (in_stack_00000008 < 0) {
      return 0;
    }
    iVar2 = (*DAT_0047d6dc)();
    if (iVar2 <= in_stack_00000008) {
      return 0;
    }
  }
  return 0x12340042;
}

