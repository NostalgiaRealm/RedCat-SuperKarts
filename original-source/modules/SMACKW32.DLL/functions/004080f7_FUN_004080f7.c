/*
 * FUN_004080f7 at 004080f7
 * undefined8 __fastcall FUN_004080f7(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004080f7-00408123
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_004080f7(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  ushort in_DS;
  undefined8 uVar3;
  
  do {
    uVar3 = (*(code *)PTR_FUN_0040ef44)();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    iVar1 = (int)uVar3 + iVar2;
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(&DAT_0040ef8c + iVar2);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(&DAT_0040ef90 + iVar2);
  } while (iVar2 != 0x60);
  return CONCAT44(param_2,(uint)in_DS);
}

