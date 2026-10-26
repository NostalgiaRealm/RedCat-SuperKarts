/*
 * FUN_00414d60 at 00414d60
 * int __cdecl FUN_00414d60(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414d60-00414e72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00414d60(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int local_1c;
  uint local_14;
  int local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  uint *local_8;
  
  local_1c = 0;
  local_10 = 0;
  local_8 = &local_14;
  do {
    uVar1 = FUN_0041fe68(param_2);
    _local_c = CONCAT31(uStack_b,(char)uVar1);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      _local_c = CONCAT31(uStack_b,(char)uVar2);
      local_14 = FUN_0040de93(uVar2 & 0xff,8);
      for (local_10 = 0; local_10 < (int)(uVar1 & 0x3f); local_10 = local_10 + 1) {
        puVar3 = (undefined2 *)(param_1 + local_1c * 3);
        *puVar3 = (short)*local_8;
        *(undefined1 *)(puVar3 + 1) = *(undefined1 *)((int)local_8 + 2);
        local_1c = local_1c + 1;
      }
    }
    else {
      local_14 = FUN_0040de93(uVar1 & 0xff,8);
      puVar3 = (undefined2 *)(param_1 + local_1c * 3);
      *puVar3 = (short)*local_8;
      *(undefined1 *)(puVar3 + 1) = *(undefined1 *)((int)local_8 + 2);
      local_1c = local_1c + 1;
    }
  } while (local_1c < param_3);
  return local_1c;
}

