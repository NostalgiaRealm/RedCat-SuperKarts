/*
 * FUN_00408c74 at 00408c74
 * undefined8 __fastcall FUN_00408c74(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408c74-00408cd1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00408c74(undefined4 param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  LPVOID in_EAX;
  BOOL BVar2;
  undefined4 uVar3;
  
  pvVar1 = *(LPVOID *)((int)in_EAX + 8);
  BVar2 = VirtualFree(in_EAX,0,0x8000);
  if (BVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if ((in_EAX == DAT_0040e868) && (DAT_0040e868 = pvVar1, pvVar1 == (LPVOID)0x0)) {
      DAT_0040e868 = DAT_0040e864;
      DAT_0040e86c = 0;
    }
    if (in_EAX == DAT_004104c8) {
      DAT_004104c8 = (LPVOID)0x0;
    }
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}

