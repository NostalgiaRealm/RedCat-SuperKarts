/*
 * FUN_004456dc at 004456dc
 * undefined4 __register FUN_004456dc(int param_1)
 * Address ranges: 004456dc-004456fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004456dc(int param_1)

{
  HWND pHVar1;
  
  if (*(int *)(param_1 + 0x14c) != 0) {
    pHVar1 = GetFocus();
    if (pHVar1 == *(HWND *)(param_1 + 0x14c)) {
      return CONCAT31((int3)((uint)pHVar1 >> 8),1);
    }
  }
  return 0;
}

