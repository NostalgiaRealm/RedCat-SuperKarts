/*
 * FUN_00406144 at 00406144
 * LPVOID __register FUN_00406144(void)
 * Address ranges: 00406144-00406186
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LPVOID FUN_00406144(void)

{
  LPVOID pvVar1;
  int in_FS_OFFSET;
  
  if (DAT_0047d4d0 == '\0') {
    return *(LPVOID *)(*(int *)(in_FS_OFFSET + 0x2c) + _tls_index * 4);
  }
  pvVar1 = TlsGetValue(_tls_index);
  if (pvVar1 != (LPVOID)0x0) {
    return pvVar1;
  }
  FUN_004060f4();
  pvVar1 = TlsGetValue(_tls_index);
  if (pvVar1 != (LPVOID)0x0) {
    return pvVar1;
  }
  return DAT_0047d4e4;
}

