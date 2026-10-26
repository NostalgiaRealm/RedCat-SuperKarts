/*
 * FUN_0041ec24 at 0041ec24
 * undefined4 __register FUN_0041ec24(void)
 * Address ranges: 0041ec24-0041ec99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041ec24(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_stack_00000004;
  byte in_stack_00000008;
  
  if (DAT_0047d706 == '\0') {
    DAT_0047d6e4 = (code *)FUN_0041eab4(2,DAT_0047d6e4,"MonitorFromRect");
    uVar1 = (*DAT_0047d6e4)();
    return uVar1;
  }
  if ((in_stack_00000008 & 3) == 0) {
    if (in_stack_00000004[2] < 1) {
      return 0;
    }
    if (in_stack_00000004[3] < 1) {
      return 0;
    }
    iVar2 = (*DAT_0047d6dc)();
    if (iVar2 <= *in_stack_00000004) {
      return 0;
    }
    iVar2 = (*DAT_0047d6dc)();
    if (iVar2 <= in_stack_00000004[1]) {
      return 0;
    }
  }
  return 0x12340042;
}

