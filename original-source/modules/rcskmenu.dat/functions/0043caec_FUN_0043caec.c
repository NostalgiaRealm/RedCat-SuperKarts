/*
 * FUN_0043caec at 0043caec
 * HANDLE __register FUN_0043caec(void)
 * Address ranges: 0043caec-0043cb13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HANDLE FUN_0043caec(void)

{
  HWND pHVar1;
  HANDLE pvVar2;
  
  pHVar1 = GetCapture();
  pvVar2 = FUN_0043c864(pHVar1);
  if (((pvVar2 != (HANDLE)0x0) && (DAT_0047b9b8 != (HANDLE)0x0)) &&
     (pvVar2 == *(HANDLE *)((int)DAT_0047b9b8 + 0x24))) {
    pvVar2 = DAT_0047b9b8;
  }
  return pvVar2;
}

