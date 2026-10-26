/*
 * FUN_00407fcb at 00407fcb
 * longlong __fastcall FUN_00407fcb(undefined4 param_1, uint param_2)
 * Address ranges: 00407fcb-00408011
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00407fcb(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_FUN_0040ef44)();
  pcVar1 = *(code **)(iVar2 + 0x68);
  if (((pcVar1 != (code *)0x1) && (pcVar1 != (code *)0x2)) && (pcVar1 != (code *)0x3)) {
    iVar2 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar2 + 0x68) = 2;
    (*pcVar1)();
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,0xffffffff);
}

