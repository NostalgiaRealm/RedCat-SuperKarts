/*
 * FUN_00401a80 at 00401a80
 * undefined __register FUN_00401a80(void)
 * Address ranges: 00401a80-00401b35
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401a80(void)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  if (DAT_0047d049 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  FUN_00401444(0x47d458);
  FUN_00401444(0x47d468);
  FUN_00401444(0x47d494);
  DAT_0047d490 = LocalAlloc(0,0xff8);
  if (DAT_0047d490 != (HLOCAL)0x0) {
    iVar1 = 3;
    do {
      *(undefined4 *)((int)DAT_0047d490 + iVar1 * 4 + -0xc) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x401);
    DAT_0047d47c = &DAT_0047d478;
    DAT_0047d478 = &DAT_0047d478;
    DAT_0047d484 = &DAT_0047d478;
    DAT_0047d430 = 1;
  }
  *in_FS_OFFSET = uStack_10;
  if (DAT_0047d049 != '\0') {
    uStack_10 = 0x401b35;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  return;
}

