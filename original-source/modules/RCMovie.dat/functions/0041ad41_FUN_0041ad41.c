/*
 * FUN_0041ad41 at 0041ad41
 * undefined __cdecl FUN_0041ad41(int param_1)
 * Address ranges: 0041ad41-0041ae67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041ad41(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = param_1;
  do {
    local_8 = FUN_004127b0(local_8,6);
    if (local_8 == -1) {
      local_8 = param_1;
      do {
        local_8 = FUN_00412821(local_8,6);
        if (local_8 == -1) {
          return;
        }
        iVar1 = FUN_00412b70(local_8);
      } while (*(int *)(iVar1 + 0x20) != 4);
      *(undefined4 *)(iVar1 + 0x20) = 0;
      DAT_0043e144 = (HWND)FUN_004129a2(local_8);
      _DAT_0043e140 = 0;
      SendMessageA(DAT_0043e144,0x2b,0,0x43e130);
      return;
    }
    iVar1 = FUN_00412b70(local_8);
  } while (*(int *)(iVar1 + 0x20) != 4);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  DAT_0043e144 = (HWND)FUN_004129a2(local_8);
  _DAT_0043e140 = 0;
  SendMessageA(DAT_0043e144,0x2b,0,0x43e130);
  return;
}

