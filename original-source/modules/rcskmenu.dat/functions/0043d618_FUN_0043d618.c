/*
 * FUN_0043d618 at 0043d618
 * undefined4 __register FUN_0043d618(HWND param_1)
 * Address ranges: 0043d618-0043d638
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043d618(HWND param_1)

{
  HANDLE pvVar1;
  
  if (param_1 != (HWND)0x0) {
    pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_0047d7b4);
    if (pvVar1 != (HANDLE)0x0) {
      return CONCAT31((int3)((uint)pvVar1 >> 8),1);
    }
  }
  return 0;
}

