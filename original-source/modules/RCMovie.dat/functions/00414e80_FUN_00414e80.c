/*
 * FUN_00414e80 at 00414e80
 * int __cdecl FUN_00414e80(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414e80-00414f30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00414e80(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_10;
  
  local_10 = 0;
  do {
    uVar1 = FUN_0041fe68(param_2);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      _memset((void *)(param_1 + local_10),uVar2 & 0xff,uVar1 & 0x3f);
      local_10 = local_10 + (uVar1 & 0x3f);
    }
    else {
      *(char *)(param_1 + local_10) = (char)uVar1;
      local_10 = local_10 + 1;
    }
  } while (local_10 < param_3);
  return local_10;
}

