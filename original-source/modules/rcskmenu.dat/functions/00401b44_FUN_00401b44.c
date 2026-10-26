/*
 * FUN_00401b44 at 00401b44
 * undefined __register FUN_00401b44(void)
 * Address ranges: 00401b44-00401c19;00401c21-00401c23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401b44(void)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  
  if (DAT_0047d430 == '\0') {
    return;
  }
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  if (DAT_0047d049 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  DAT_0047d430 = 0;
  LocalFree(DAT_0047d490);
  DAT_0047d490 = (HLOCAL)0x0;
  for (puVar1 = DAT_0047d458; (undefined4 **)puVar1 != &DAT_0047d458; puVar1 = (undefined4 *)*puVar1
      ) {
    VirtualFree((LPVOID)puVar1[2],0,0x8000);
  }
  FUN_00401444(0x47d458);
  FUN_00401444(0x47d468);
  FUN_00401444(0x47d494);
  puVar1 = DAT_0047d450;
  while (puVar1 != (undefined4 *)0x0) {
    DAT_0047d450 = (undefined4 *)*puVar1;
    LocalFree(puVar1);
    puVar1 = DAT_0047d450;
  }
  DAT_0047d450 = puVar1;
  *in_FS_OFFSET = uStack_14;
  if (DAT_0047d049 != '\0') {
    uStack_14 = 0x401c0f;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  uStack_14 = 0x401c19;
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  return;
}

