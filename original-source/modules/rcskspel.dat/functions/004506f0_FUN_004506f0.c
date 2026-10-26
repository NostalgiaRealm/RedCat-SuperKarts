/*
 * FUN_004506f0 at 004506f0
 * undefined FUN_004506f0(void)
 * Address ranges: 004506f0-00450723
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004506f0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00543d1c == '\0') {
    DAT_00543d1c = '\x01';
    iVar2 = 0;
    do {
      uVar1 = FUN_004a6200(*(undefined4 *)((int)&PTR_s_kogel0_004d2744 + iVar2));
      *(undefined4 *)((int)&DAT_004f0fb8 + iVar2) = uVar1;
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x20);
  }
  return;
}

