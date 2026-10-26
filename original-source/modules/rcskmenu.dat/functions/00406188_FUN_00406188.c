/*
 * FUN_00406188 at 00406188
 * undefined __register FUN_00406188(void)
 * Address ranges: 00406188-004061d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406188(void)

{
  CHAR local_10c [264];
  
  GetModuleFileNameA(DAT_0047d4dc,local_10c,0x105);
  _DAT_0047b0c0 = FUN_004050d0(local_10c);
  if (_DAT_0047b0c0 == (HMODULE)0x0) {
    _DAT_0047b0c0 = DAT_0047b0b4;
  }
  FUN_004053b8((undefined4 *)&DAT_0047b0b0);
  return;
}

