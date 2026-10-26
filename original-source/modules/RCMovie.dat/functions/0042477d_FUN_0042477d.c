/*
 * FUN_0042477d at 0042477d
 * undefined __cdecl FUN_0042477d(uint * param_1)
 * Address ranges: 0042477d-004247b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0042477d(uint *param_1)

{
  int *piVar1;
  
  if ((param_1 <= DAT_00437490) && (piVar1 = FUN_00422ebb(param_1), piVar1 != (int *)0x0)) {
    return;
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  HeapAlloc(DAT_0043f81c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return;
}

