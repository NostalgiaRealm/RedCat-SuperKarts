/*
 * FUN_004017e6 at 004017e6
 * undefined __cdecl FUN_004017e6(uint * param_1)
 * Address ranges: 004017e6-0040181b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004017e6(uint *param_1)

{
  int *piVar1;
  
  if ((param_1 <= DAT_004083bc) && (piVar1 = FUN_00402e7e(param_1), piVar1 != (int *)0x0)) {
    return;
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  HeapAlloc(DAT_0040a01c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return;
}

