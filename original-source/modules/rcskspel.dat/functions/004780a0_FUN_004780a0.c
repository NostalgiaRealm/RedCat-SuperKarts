/*
 * FUN_004780a0 at 004780a0
 * undefined FUN_004780a0(void)
 * Address ranges: 004780a0-004780d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004780a0(undefined4 *param_1)

{
  char cVar1;
  void *pvVar2;
  
  *param_1 = 0;
  cVar1 = FUN_004817c0();
  if (cVar1 != '\0') {
    pvVar2 = operator_new(0x400);
    *param_1 = pvVar2;
    FUN_004b2400(pvVar2,0,0x100);
  }
  return param_1;
}

