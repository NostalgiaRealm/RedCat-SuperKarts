/*
 * FUN_0040187a at 0040187a
 * undefined4 __cdecl FUN_0040187a(byte * param_1)
 * Address ranges: 0040187a-00401966
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 __cdecl FUN_0040187a(byte *param_1)

{
  int iVar1;
  CHAR local_1b0 [400];
  UINT local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_20 = 0x10010;
  local_1c = 0x10021;
  local_18 = 0x10045;
  local_14 = 0x10034;
  local_10 = 0x10013;
  local_c = 0x110011;
  local_8 = 0x90025;
  FUN_0041f64a(local_1b0,param_1,(undefined4 *)&stack0x00000008);
  FUN_00401590(0,1);
  FUN_004015a6((byte *)s___d___s_0042c588);
  ShowWindow(DAT_0043842c,6);
  do {
    iVar1 = FUN_0040a97d();
  } while (iVar1 != 0);
  MessageBoxExA((HWND)0x0,local_1b0,&DAT_0042c594,local_20,0);
  FUN_0040173e();
  FUN_0041f6c8(0);
  return 0;
}

