/*
 * FUN_004088ac at 004088ac
 * undefined8 __fastcall FUN_004088ac(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004088ac-004088ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_004088ac(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  
  if (in_EAX == 0) {
    in_EAX = FUN_0040917a(param_1,DAT_0040f0c0);
    if (in_EAX != 0) {
      *(undefined1 *)(in_EAX + 0x52) = 1;
    }
  }
  if (in_EAX != 0) {
    *(undefined4 *)(in_EAX + 0xc) = 1;
    DVar1 = GetCurrentThreadId();
    *(DWORD *)(in_EAX + 0xda) = DVar1;
  }
  return CONCAT44(param_2,in_EAX);
}

