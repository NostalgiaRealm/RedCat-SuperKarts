/*
 * FUN_0040b4a0 at 0040b4a0
 * undefined __register FUN_0040b4a0(void)
 * Address ranges: 0040b4a0-0040b4f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b4a0(void)

{
  BOOL BVar1;
  _OSVERSIONINFOA local_94;
  
  local_94.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_94);
  if (BVar1 != 0) {
    DAT_0047b0cc = local_94.dwPlatformId;
    DAT_0047b0d0 = local_94.dwMajorVersion;
    DAT_0047b0d4 = local_94.dwMinorVersion;
    _DAT_0047b0d8 = local_94.dwBuildNumber;
    FUN_00403d80((int *)&DAT_0047b0dc,local_94.szCSDVersion,0x80);
  }
  return;
}

