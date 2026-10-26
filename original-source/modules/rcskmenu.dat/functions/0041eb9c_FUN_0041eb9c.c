/*
 * FUN_0041eb9c at 0041eb9c
 * undefined FUN_0041eb9c(void)
 * Address ranges: 0041eb9c-0041ec07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041eb9c(void)

{
  int iVar1;
  int in_stack_00000004;
  
  if (DAT_0047d704 == '\0') {
    DAT_0047d6dc = (code *)FUN_0041eab4(0,DAT_0047d6dc,"GetSystemMetrics");
    (*DAT_0047d6dc)();
  }
  else {
    iVar1 = -1;
    if (in_stack_00000004 - 0x4cU < 2) {
      iVar1 = 0;
    }
    else if (in_stack_00000004 == 0x4e) {
      in_stack_00000004 = 0;
    }
    else if (in_stack_00000004 == 0x4f) {
      in_stack_00000004 = 1;
    }
    else if (in_stack_00000004 - 0x50U < 2) {
      iVar1 = 1;
    }
    if (iVar1 == -1) {
      GetSystemMetrics(in_stack_00000004);
    }
  }
  return;
}

