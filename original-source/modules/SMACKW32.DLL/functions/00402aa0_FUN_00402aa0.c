/*
 * FUN_00402aa0 at 00402aa0
 * undefined8 __fastcall FUN_00402aa0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00402aa0-00402afb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00402aa0(undefined4 param_1,undefined4 param_2)

{
  UINT UVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  tagWNDCLASSA tStack_38;
  
  UVar1 = SetErrorMode(0x8000);
  DVar2 = LoadModule(s_DISPDIB_DLL_0040e0d4,&DAT_0040e814);
  UVar1 = SetErrorMode(UVar1);
  if (DVar2 < 0x20) {
    uVar4 = UVar1 & 0xffffff00;
  }
  else {
    BVar3 = GetClassInfoA((HINSTANCE)0x0,s_DisplayDibWindow_0040e0e0,&tStack_38);
    uVar4 = (uint)(BVar3 != 0);
  }
  return CONCAT44(param_2,uVar4);
}

