/*
 * FUN_00429484 at 00429484
 * int __register FUN_00429484(undefined4 param_1)
 * Address ranges: 00429484-004294bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00429484(undefined4 param_1)

{
  DWORD dwThreadId;
  code *lpfn;
  LPARAM lParam;
  
  DAT_0047b6c0 = 0;
  DAT_0047b6c4 = 0;
  lParam = 0;
  lpfn = FUN_00429420;
  DAT_0047b6bc = param_1;
  dwThreadId = GetCurrentThreadId();
  EnumThreadWindows(dwThreadId,lpfn,lParam);
  if (DAT_0047b6c0 != 0) {
    return DAT_0047b6c0;
  }
  return DAT_0047b6c4;
}

