/*
 * FUN_0040a24e at 0040a24e
 * undefined __stdcall FUN_0040a24e(void)
 * Address ranges: 0040a24e-0040a2cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a24e(void)

{
  int iVar1;
  
  if (*(int *)(DAT_0043d510 + 0x370) == *(int *)(DAT_0043d510 + 0xc) + -1) {
    DAT_0043d51c = 0;
  }
  else {
    _SmackNextFrame_4(DAT_0043d510);
    FUN_0040a566();
    if ((DAT_0043d51c & (DAT_0043d520 & 1) == 0) != 0) {
      while( true ) {
        iVar1 = _SmackWait_4(DAT_0043d510);
        if (((iVar1 == 0) || (DAT_0043d51c == 0)) || (DAT_0043d518 != 0)) break;
        FUN_0040a566();
      }
    }
  }
  return;
}

