/*
 * FUN_00405614 at 00405614
 * undefined4 __stdcall FUN_00405614(void)
 * Address ranges: 00405614-004056c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00405614(void)

{
  int iVar1;
  void *this;
  void *this_00;
  int local_8;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____handle_mouse__Mouse_is_0042eb08);
  }
  FUN_00404de4(&DAT_00438480,&DAT_00438484,&local_8);
  if ((DAT_0043848c != 0) && (DAT_00438494 != 0)) {
    if (DAT_0042dfa4 == 1) {
      SetCursor(DAT_004384a8);
    }
    else if ((DAT_0042dfa4 == 2) &&
            ((DAT_0042df80 != DAT_00438480 || (DAT_0042df84 != DAT_00438484)))) {
      iVar1 = FUN_00412061();
      FUN_004054ad(this,iVar1);
      iVar1 = FUN_00412061();
      FUN_0040555a(this_00,iVar1);
    }
  }
  return 0;
}

