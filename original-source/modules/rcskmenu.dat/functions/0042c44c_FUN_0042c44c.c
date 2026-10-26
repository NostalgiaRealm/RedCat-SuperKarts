/*
 * FUN_0042c44c at 0042c44c
 * HANDLE __register FUN_0042c44c(int param_1)
 * Address ranges: 0042c44c-0042c47e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HANDLE FUN_0042c44c(int param_1)

{
  HANDLE pvVar1;
  HWND pHVar2;
  
  pvVar1 = (HANDLE)0x0;
  if ((*(char *)(param_1 + 0x217) == '\x02') && (*(int *)(param_1 + 0x23c) != 0)) {
    pHVar2 = (HWND)SendMessageA(*(HWND *)(param_1 + 0x23c),0x229,0,0);
    pvVar1 = FUN_0043c864(pHVar2);
  }
  return pvVar1;
}

