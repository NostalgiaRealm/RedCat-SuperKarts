/*
 * FUN_00442e80 at 00442e80
 * undefined FUN_00442e80(void)
 * Address ranges: 00442e80-00442f3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00442e80(void)

{
  bool bVar1;
  bool bVar2;
  BOOL BVar3;
  tagMSG local_1c;
  
  bVar2 = false;
  do {
    bVar1 = false;
    BVar3 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
    if (BVar3 != 0) {
      bVar1 = true;
      if (local_1c.message == 0x12) {
        return 1;
      }
      TranslateMessage(&local_1c);
      DispatchMessageA(&local_1c);
    }
    if (DAT_006abae0 == 0) {
      WaitMessage();
      bVar2 = true;
    }
  } while ((bVar1) || (DAT_006abae0 == 0));
  if (bVar2) {
    FUN_004b08e0(DAT_006a64bc);
    FUN_004b08e0(DAT_006a64c0);
    FUN_004b08e0(DAT_006a64a0);
    FUN_004a3170();
    FUN_004ac880();
    FUN_0049c8f0();
  }
  return 0;
}

