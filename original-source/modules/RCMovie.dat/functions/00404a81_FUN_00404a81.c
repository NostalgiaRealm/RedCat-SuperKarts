/*
 * FUN_00404a81 at 00404a81
 * undefined __stdcall FUN_00404a81(void)
 * Address ranges: 00404a81-00404aed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404a81(void)

{
  int iVar1;
  void *this;
  int local_8;
  
  if ((DAT_00438494 == 0) && (DAT_0043848c != 0)) {
    FUN_00404de4(&DAT_00438480,&DAT_00438484,&local_8);
    if ((DAT_0042dfa4 != 1) && (DAT_0042dfa4 == 2)) {
      iVar1 = FUN_00412061();
      FUN_0040555a(this,iVar1);
    }
    ShowCursor(1);
    DAT_00438494 = 1;
  }
  return;
}

