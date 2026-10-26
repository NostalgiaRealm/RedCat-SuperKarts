/*
 * FUN_00414c60 at 00414c60
 * int __cdecl FUN_00414c60(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414c60-00414d57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00414c60(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 local_c;
  
  local_18 = 0;
  do {
    uVar1 = FUN_0041fe68(param_2);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      uVar2 = FUN_0040de93(uVar2 & 0xff,8);
      for (local_c = 0; local_c < (int)(uVar1 & 0x3f); local_c = local_c + 1) {
        *(short *)(param_1 + local_18 * 2) = (short)uVar2;
        local_18 = local_18 + 1;
      }
    }
    else {
      uVar1 = FUN_0040de93(uVar1 & 0xff,8);
      *(short *)(param_1 + local_18 * 2) = (short)uVar1;
      local_18 = local_18 + 1;
    }
  } while (local_18 < param_3);
  return local_18;
}

