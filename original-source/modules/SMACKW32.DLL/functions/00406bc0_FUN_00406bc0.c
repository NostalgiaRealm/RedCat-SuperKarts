/*
 * FUN_00406bc0 at 00406bc0
 * undefined __fastcall FUN_00406bc0(undefined4 param_1)
 * Address ranges: 00406bc0-00406c06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00406bc0(undefined4 param_1)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (*(int *)(in_EAX + 0x38) != 0) {
    lVar2 = FUN_00406ce0(param_1,in_EAX);
    iVar1 = (int)((ulonglong)lVar2 >> 0x20);
    do {
      do {
      } while ((*(byte *)(*(int *)(iVar1 + 0x54) + 0x10) & 1) == 0);
    } while ((*(byte *)(*(int *)(iVar1 + 0x58) + 0x10) & 1) == 0);
    *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 1;
    *(undefined4 *)(*(int *)(iVar1 + 0x58) + 0x10) = 1;
    uVar3 = FUN_00406c30(extraout_ECX,iVar1);
    *(undefined4 *)((int)((ulonglong)uVar3 >> 0x20) + 0x38) = 0;
  }
  return;
}

