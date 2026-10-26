/*
 * FUN_004060f4 at 004060f4
 * undefined __register FUN_004060f4(void)
 * Address ranges: 004060f4-00406142
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004060f4(void)

{
  HLOCAL lpTlsValue;
  
  if ((int)_tls_index < 0) {
    FUN_00403b28(0xe2);
  }
  lpTlsValue = LocalAlloc(0x40,0x10);
  if (lpTlsValue == (HLOCAL)0x0) {
    FUN_00403b28(0xe2);
  }
  else {
    TlsSetValue(_tls_index,lpTlsValue);
  }
  DAT_0047d4e4 = lpTlsValue;
  return;
}

