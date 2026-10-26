/*
 * FUN_00402c30 at 00402c30
 * undefined __fastcall FUN_00402c30(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 00402c30-00402c61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00402c30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    return;
  }
  if (param_3 == -1) {
    iVar1 = 0;
  }
  else {
    uVar3 = FUN_00406420(param_1,param_2);
    iVar1 = (int)uVar3;
  }
  bVar2 = 0x10 - ((byte)iVar1 & 0xf);
  *(byte *)((uint)bVar2 + iVar1 + -1) = bVar2;
  return;
}

